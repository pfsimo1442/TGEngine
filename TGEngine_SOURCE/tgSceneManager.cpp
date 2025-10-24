#include "tgSceneManager.h"
#include "tgDontDestroyOnLoad.h"

namespace tg
{
    std::map<std::wstring, Scene*> SceneManager::mScene = {};
    Scene* SceneManager::mActiveScene = nullptr;
    Scene* SceneManager::mDontDestroyOnLoad = nullptr;

    Scene* SceneManager::LoadScene(const std::wstring& name)
    {
        if (mActiveScene)
            mActiveScene->OnExit();

        std::map<std::wstring, Scene*>::iterator iter
            = mScene.find(name);

        if (iter == mScene.end())
            return nullptr;

        mActiveScene = iter->second;
        mActiveScene->OnEnter();

        return iter->second;
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

    void SceneManager::Initialize()
    {
        mDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
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

    void SceneManager::Destroy()
    {
        mActiveScene->Destroy();
        mDontDestroyOnLoad->Destroy();
    }

    void SceneManager::Release()
    {
        for (auto& iter : mScene)
        {
            delete iter.second;
            iter.second = nullptr;
        }
    }
}