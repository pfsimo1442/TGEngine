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
#include "tgBoxCollider2D.h"
#include "tgCollisionManager.h"
#include "tgTile.h"
#include "tgTilemapRenderer.h"
#include "tgRigidbody.h"
#include "tgPlatform.h"
#include "tgAudioClip.h"
#include "tgAudioListener.h"
#include "tgAudioSource.h"
#include "tgGraphicDevice_DX11.h"
#include "tgCameraScript.h"
#include "tgMaterial.h"

namespace tg
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		Scene::Initialize();

		//// Main Camera
		GameObject* camera = object::Instantiate<GameObject>(eLayerType::None, Vector3(0.0f, 0.0f, -10.0f));

		Camera* cameraComp = camera->AddComponent<Camera>();
		cameraComp->SetProjectionType(Camera::eProjectionType::Perspective);
		cameraComp->SetSize(200.0f);

		CameraScript* cameraScript = camera->AddComponent<CameraScript>();
		renderer::mainCamera = cameraComp;

		//// Player
		GameObject* player = object::Instantiate<Player>(eLayerType::Player);
		object::DontDestroyOnLoad(player);

		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetSprite(Resources::Find<graphics::Texture>(L"Player"));

		renderer::selectedObject = player;
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

		//CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Pet, true);
		//CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Platform, true);

		//UIManager::Push(eUIType::Button);
	}

	void PlayScene::OnExit()
	{
		//UIManager::Pop(eUIType::Button);

		Scene::OnExit();
	}
}