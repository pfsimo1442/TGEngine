#include "tgLoadingScene.h"
#include "tgRenderer.h"
#include "tgSceneManager.h"
#include "tgResources.h"
#include "tgTexture.h"
#include "tgAudioClip.h"

namespace tg
{
	LoadingScene::LoadingScene()
		: mbLoadCompleted(false)
	{
	}
	LoadingScene::~LoadingScene()
	{
		delete mResourcesLoad;
		mResourcesLoad = nullptr;
	}

	void LoadingScene::Initialize()
	{
		mResourcesLoad = new std::thread(&LoadingScene::resourcesLoad, this, std::ref(mMutex));
	}

	void LoadingScene::Update()
	{
		if (mbLoadCompleted)
		{
			mResourcesLoad->join();
			//mResourcesLoad->detach();

			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void LoadingScene::LateUpdate()
	{

	}

	void LoadingScene::Render(HDC hdc)
	{

	}

	void LoadingScene::OnEnter()
	{
	}
	void LoadingScene::OnExit()
	{
	}

	void LoadingScene::resourcesLoad(std::mutex& m)
	{
		m.lock();
		{
			// Textures
			Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\CatAlpha.bmp");
			Resources::Load<graphics::Texture>(L"PlayerSDV", L"..\\Resources\\Player.bmp");
			Resources::Load<graphics::Texture>(L"PlatformSpringSDV", L"..\\Resources\\SpringFloor.bmp");
			Resources::Load<graphics::Texture>(L"HPBAR", L"..\\Resources\\HPBAR.bmp");
			Resources::Load<graphics::Texture>(L"PixelMap", L"..\\Resources\\pixelMap.bmp");

			// Audios
			Resources::Load<AudioClip>(L"BGSound", L"..\\Resources\\Sound\\smw_bonus_game_end.wav");
		}
		m.unlock();

		// complete
		mbLoadCompleted = true;
	}
}