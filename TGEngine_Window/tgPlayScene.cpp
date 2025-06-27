#include "tgPlayScene.h"
#include "tgGameObject.h"
#include "tgPlayer.h"
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
		/*
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, L"..\\Resources\\TileSaves\\Test", L"rb");

		while (true)
		{
			int cellCoordX = 0;
			int cellCoordY = 0;
			int posX = 0;
			int posY = 0;

			if (fread(&cellCoordX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&cellCoordY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile, Vector2((float)posX, (float)posY));
			tile->GetComponent<Transform>()->SetPositionStyle(Vector2(0.0f, 0.0f));
			TilemapRenderer* tmRenderer = tile->AddComponent<TilemapRenderer>();
			tmRenderer->SetSize(Vector2(3.0f, 3.0f));
			tmRenderer->SetTileSize(Vector2(16.0f, 16.0f));
			tmRenderer->SetTexture(Resources::Find<graphics::Texture>(L"PlatformSpringSDV"));
			tmRenderer->SetCellCoordination(Vector2((float)cellCoordX, (float)cellCoordY));

			//mTiles.push_back(tile);
		}

		fclose(pFile);
		*/


		//// Main Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera*  cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;


		//// Player
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);
		PlayerScript* playerScr = mPlayer->AddComponent<PlayerScript>();
		//BoxCollider2D* playerCol = mPlayer->AddComponent<BoxCollidessr2D>();
		//CircleCollider2D* playerCol = mPlayer->AddComponent<CircleCollider2D>();
		CapsuleCollider2D* playerCol = mPlayer->AddComponent<CapsuleCollider2D>();
		playerCol->SetSize(Vector2(50.0f, 100.0f));
		//playerCol->SetOffset(Vector2(-50.0f, -100.0f));

		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"PlayerSDV");
		Animator* playerAni = mPlayer->AddComponent<Animator>();

		playerAni->CreateAnimationBySpriteSize(L"PlayerIdle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAni->CreateAnimationBySpriteSize(L"PlayerWaterDown", playerTex
			, Vector2(0.0f, 2000.f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(500.0f, 150.0f));
		//mPlayer->GetComponent<Transform>()->SetPositionStyle(Vector2(0.375f, 0.25f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(0.5f, 0.5f));

		Rigidbody* playerRig = mPlayer->AddComponent<Rigidbody>();
		playerRig->SetFriction(200.0f);
		playerRig->SetLimitedVelocity(Vector2(400.0f, 1000.0f));
	
		playerAni->PlayAnimation(L"PlayerIdle");
		
		playerAni->GetCompleteEvent(L"PlayerWaterDown") = std::bind(&PlayerScript::AttackEffect, playerScr);
		

		//// Platform
		Platform* platform = object::Instantiate<Platform>(eLayerType::Platform, Vector2(700.0f, 750.0f));
		//platform->GetComponent<Transform>()->SetPositionStyle(Vector2(0.0f, 0.0f));
		BoxCollider2D* platformCol = platform->AddComponent<BoxCollider2D>();
		platformCol->SetSize(Vector2(1000.0f, 500.0f));
		PlatformScript* platformScr = platform->AddComponent<PlatformScript>();


		////main camera - set target
		//cameraComp->SetTarget(cat);

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
		if (Input::GetKeyDown(eKeyCode::T))
			SceneManager::LoadScene(L"ToolScene");
	}

	void PlayScene::Render(HDC hdc)
	{
			Scene::Render(hdc);
			//wchar_t str[50] = L"Play Scene ";
			
			//TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();

		//// Collision Manager
		CollisionManager::CollisionLayerCheck(enums::eLayerType::Player, enums::eLayerType::Pet, true);
		CollisionManager::CollisionLayerCheck(enums::eLayerType::Player, enums::eLayerType::Platform, true);
	}

	void PlayScene::OnExit()
	{
		Scene::OnExit();

		//Transform* tr = mPlayer->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}