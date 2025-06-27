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
		playerCol->SetSize(Vector2(100.0f, 150.0f));
		//playerCol->SetOffset(Vector2(-50.0f, -100.0f));

		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"PlayerSDV");
		Animator* playerAni = mPlayer->AddComponent<Animator>();

		playerAni->CreateAnimationBySpriteSize(L"PlayerIdle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAni->CreateAnimationBySpriteSize(L"PlayerWaterDown", playerTex
			, Vector2(0.0f, 2000.f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2::One * 100.0f);
		//mPlayer->GetComponent<Transform>()->SetPositionStyle(Vector2(0.375f, 0.25f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(0.5f, 0.5f));

		Rigidbody* playerRig = mPlayer->AddComponent<Rigidbody>();
		playerRig->SetFriction(100.0f);
	
		playerAni->PlayAnimation(L"PlayerIdle");
		
		playerAni->GetCompleteEvent(L"PlayerWaterDown") = std::bind(&PlayerScript::AttackEffect, playerScr);
		

		//// Cat
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Pet);
		CatScript* catScr = cat->AddComponent<CatScript>();
		//BoxCollider2D* catCol = cat->AddComponent<BoxCollider2D>();
		CircleCollider2D* catCol = cat->AddComponent<CircleCollider2D>();
		//CapsuleCollider2D* catCol = cat->AddComponent<CapsuleCollider2D>();
		catCol->SetSize(Vector2(100.0f, 100.0f));
		//catCol->SetOffset(Vector2(-50.0f, -50.0f));

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAni = cat->AddComponent<Animator>();

		/*catAni->CreateAnimationBySpriteSize(L"CatWalkDown", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatWalkRight", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatWalkUp", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatWalkLeft", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatSit", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatLeak", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatTired", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatSleep", catTex
			, Vector2(0.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 1.2f);
		catAni->CreateAnimationBySpriteSize(L"CatStretch", catTex
			, Vector2(64.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 0.5f);*/

		catAni->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);

		cat->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 100.0f));
		//cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		//catAni->PlayAnimation(L"CatSit", false);
		catAni->PlayAnimation(L"MushroomIdle");

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
	}

	void PlayScene::OnExit()
	{
		Scene::OnExit();

		//Transform* tr = mPlayer->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}