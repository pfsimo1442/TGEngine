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
		//// Collision Manager
		CollisionManager::CollisionLayerCheck(enums::eLayerType::Player, enums::eLayerType::Pet, true);

		//// Main Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera*  cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;


		//// Player
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);
		PlayerScript* playerScript = mPlayer->AddComponent<PlayerScript>();
		//BoxCollider2D* playerCollider = mPlayer->AddComponent<BoxCollidessr2D>();
		//CircleCollider2D* playerCollider = mPlayer->AddComponent<CircleCollider2D>();
		CapsuleCollider2D* playerCollider = mPlayer->AddComponent<CapsuleCollider2D>();
		playerCollider->SetSize(Vector2(100.0f, 150.0f));
		//playerCollider->SetOffset(Vector2(-50.0f, -100.0f));

		graphics::Texture* playerTexture = Resources::Find<graphics::Texture>(L"PlayerSDV");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();

		playerAnimator->CreateAnimationBySpriteSize(L"PlayerIdle", playerTexture
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimationBySpriteSize(L"PlayerWaterDown", playerTexture
			, Vector2(0.0f, 2000.f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2::One * 100.0f);
		//mPlayer->GetComponent<Transform>()->SetPositionStyle(Vector2(0.375f, 0.25f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(0.5f, 0.5f));
	
		playerAnimator->PlayAnimation(L"PlayerIdle");
		
		playerAnimator->GetCompleteEvent(L"PlayerWaterDown") = std::bind(&PlayerScript::AttackEffect, playerScript);
		

		//// Cat
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Pet);
		CatScript* catScript = cat->AddComponent<CatScript>();
		//BoxCollider2D* catCollider = cat->AddComponent<BoxCollider2D>();
		CircleCollider2D* catCollider = cat->AddComponent<CircleCollider2D>();
		//CapsuleCollider2D* catCollider = cat->AddComponent<CapsuleCollider2D>();
		catCollider->SetSize(Vector2(100.0f, 100.0f));
		//catCollider->SetOffset(Vector2(-50.0f, -50.0f));

		graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();

		/*catAnimator->CreateAnimationBySpriteSize(L"CatWalkDown", catTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimationBySpriteSize(L"CatWalkRight", catTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimationBySpriteSize(L"CatWalkUp", catTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimationBySpriteSize(L"CatWalkLeft", catTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimationBySpriteSize(L"CatSit", catTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimationBySpriteSize(L"CatLeak", catTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimationBySpriteSize(L"CatTired", catTexture
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimationBySpriteSize(L"CatSleep", catTexture
			, Vector2(0.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 1.2f);
		catAnimator->CreateAnimationBySpriteSize(L"CatStretch", catTexture
			, Vector2(64.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 0.5f);*/

		catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);

		cat->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 100.0f));
		//cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		//catAnimator->PlayAnimation(L"CatSit", false);
		catAnimator->PlayAnimation(L"MushroomIdle");

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
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
			Scene::Render(hdc);
			//wchar_t str[50] = L"Play Scene ";
			
			//TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
	//	Transform* tr = mPlayer->GetComponent<Transform>();
	//	tr->SetPosition(Vector2(0, 0));
	}
}