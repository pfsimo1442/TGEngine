#include "tgLoadingScene.h"
#include "tgRenderer.h"
#include "tgSceneManager.h"
#include "tgResources.h"
#include "tgTexture.h"
#include "tgAudioClip.h"
#include "tgApplication.h"

#include "tgTitleScene.h"
#include "tgPlayScene.h"

extern tg::Application application;

namespace tg
{
	LoadingScene::LoadingScene()
		: mbLoadCompleted(false)
		, mMutualExclusion()
		, mResourcesLoadThread()
	{
	}
	LoadingScene::~LoadingScene()
	{
		delete mResourcesLoadThread;
		mResourcesLoadThread = nullptr;
	}

	void LoadingScene::Initialize()
	{
		mResourcesLoadThread = new std::thread(&LoadingScene::resourcesLoad, this, std::ref(mMutualExclusion));
	}

	void LoadingScene::Update()
	{
		
	}

	void LoadingScene::LateUpdate()
	{

	}

	void LoadingScene::Render()
	{
		if (mbLoadCompleted)
		{
			mResourcesLoadThread->join();
			//mResourcesLoadThread->detach();

			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void LoadingScene::OnEnter()
	{
	}
	void LoadingScene::OnExit()
	{
	}

	void LoadingScene::resourcesLoad(std::mutex& m)
	{
		while (true)
		{
			if (application.IsLoaded() == true)
				break;
		}

		m.lock();
		{
			Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\CloudOcean.png");

			renderer::Initialize();

			SceneManager::CreateScene<TitleScene>(L"TitleScene");
			SceneManager::CreateScene<PlayScene>(L"PlayScene");
		}
		m.unlock();

		// complete
		SceneManager::SetActiveScene(L"LoadingScene");
		mbLoadCompleted = true;
	}
}