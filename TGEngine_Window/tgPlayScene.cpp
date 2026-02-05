#include "tgPlayScene.h"
#include "tgGameObject.h"
#include "tgPlayer.h"
#include "tgUIManager.h"
#include "tgTransform.h"
#include "tgSpriteRenderer.h"
#include "tgInput.h"
#include "tgTitleScene.h"
#include "tgSceneManager.h"
#include "tgObject.h"
#include "tgTexture.h"
#include "tgResources.h"
#include "tgPlayerScript.h"
#include "tgCamera.h"
#include "tgRenderer.h"
#include "tgAnimator.h"
#include "tgCat.h"
#include "tgCatScript.h"
#include "tgBoxCollider2D.h"
#include "tgCollisionManager.h"
#include "tgTile.h"
#include "tgTilemapRenderer.h"
#include "tgRigidbody.h"
#include "tgPlatform.h"
#include "tgPlatformScript.h"
#include "tgAudioClip.h"
#include "tgAudioListener.h"
#include "tgAudioSource.h"
#include "tgGraphicDevice_DX11.h"
#include "tgMaterial.h"

namespace tg
{
	PlayScene::PlayScene()
		: mPlayer(nullptr)
	{
	}
	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		//// Main Camera
		//GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(800.f, 450.f));
		//mMainCamera = camera->AddComponent<Camera>();

		//// Player
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);

		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetMaterial(Resources::Find<Material>(L"Sprite-Default-Material"));
		sr->SetSprite(Resources::Find<graphics::Texture>(L"Player"));


		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
			SceneManager::LoadScene(L"TitleScene");
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();

		renderer::mainCamera = mMainCamera;

		//CollisionManager::CollisionLayerCheck(enums::eLayerType::Player, enums::eLayerType::Pet, true);
		//CollisionManager::CollisionLayerCheck(enums::eLayerType::Player, enums::eLayerType::Platform, true);

		//UIManager::Push(eUIType::Button);
	}

	void PlayScene::OnExit()
	{
		//UIManager::Pop(eUIType::Button);

		Scene::OnExit();
	}
}