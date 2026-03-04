#include "tgSceneManager.h"
#include "tgDontDestroyOnLoad.h"
#include "tgGameObjectEvent.h"

namespace tg
{
    std::map<std::wstring, Scene*> SceneManager::mScene = {};
    Scene* SceneManager::mActiveScene = nullptr;
    Scene* SceneManager::mDontDestroyOnLoad = nullptr;
    EventQueue SceneManager::mEventQueue;

    void SceneManager::Initialize()
    {
        mDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
        InitializeEventHandlers();
    }

    void SceneManager::Update()
    {
        mActiveScene->Update(); 
        mDontDestroyOnLoad->Update();
    }

    void SceneManager::LateUpdate()
    {
        mActiveScene->LateUpdate();
        mDontDestroyOnLoad->LateUpdate();
    }

    void SceneManager::Render()
    {
        mActiveScene->Render();
        mDontDestroyOnLoad->Render();
    }

    void SceneManager::EndOfFrame()
    {
        mActiveScene->EndOfFrame();
        mDontDestroyOnLoad->EndOfFrame();
    }

    void SceneManager::Release()
    {
        for (auto& iter : mScene)
        {
            delete iter.second;
            iter.second = nullptr;
        }
    }

    void SceneManager::InitializeEventHandlers()
    {
        // register Event Handler
        mEventQueue.RegisterHandler<GameObjectCreatedEvent>([](GameObjectCreatedEvent& e) -> bool
            {
                SceneManager::GameObjectCreated(e.GetGameObject(), e.GetScene());
                return true;
		    });

        mEventQueue.RegisterHandler<GameObjectDestroyedEvent>([](GameObjectDestroyedEvent& e) -> bool
            {
                SceneManager::GameObjectDestroyed(e.GetGameObject(), e.GetScene());
                return true;
			});

		// register Standard Handler
        mEventQueue.SetCallback([](Event& e)
            {
                std::cout << "[Application] Unhandled Event: " << e.ToString() << std::endl;
			});
    }

    void SceneManager::GameObjectCreated(GameObject* gameObject, Scene* scene)
    {
		scene->AddGameObject(gameObject, gameObject->GetLayerType());
    }

    void SceneManager::GameObjectDestroyed(GameObject* gameObject, Scene* scene)
    {
		scene->EraseGameObject(gameObject);
    }

    bool SceneManager::SetActiveScene(const std::wstring& name)
    {
        auto iter
            = mScene.find(name);

        if (iter == mScene.end())
            return false;

        mActiveScene = iter->second;
        return true;
    }

    Scene* SceneManager::LoadScene(const std::wstring& name)
    {
        if (mActiveScene)
            mActiveScene->OnExit();

        if (!SetActiveScene(name))
            return nullptr;

        mActiveScene->OnEnter();

        return mActiveScene;
    }

    std::vector<GameObject*> SceneManager::GetGameObjects(eLayerType layer)
    {
        std::vector<GameObject*> gameObjs
            = mActiveScene->GetLayer(layer)->GetGameObjects();
        std::vector<GameObject*> dontDestroyOnLoad
            = mDontDestroyOnLoad->GetLayer(layer)->GetGameObjects();

        gameObjs.insert(gameObjs.end(), dontDestroyOnLoad.begin(), dontDestroyOnLoad.end());

        return gameObjs;
    }
}