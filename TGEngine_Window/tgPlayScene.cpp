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
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera*  cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();
		


		mPlayer = object::Instantiate<Player>(enums::eLayerType::Particle);
		//SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		//sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		//graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"MapleEffect");
		//Animator* animator = mPlayer->AddComponent<Animator>();
		//animator->CreateAnimation(L"CatFrontMove", catTexture
		//	, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::Zero, 8, 0.05f);
		//animator->PlayAnimation(L"CatFrontMove");

		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();

		animator->CreateAnimation(L"CatDownWalk", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"CatRightWalk", packmanTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"CatUpWalk", packmanTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"CatLeftWalk", packmanTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"CatSitDown", packmanTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"CatLeak", packmanTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"CatTired", packmanTexture
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"CatSleep", packmanTexture
			, Vector2(0.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 0.1f);
		animator->CreateAnimation(L"CatStretch", packmanTexture
			, Vector2(64.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 0.1f);

		animator->PlayAnimation(L"CatSitDown", false);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(30.0f);
		//sr->SetTexture(catTexture);

		//GameObject* bg = object::Instantiate<GameObject>
		//	(enums::eLayerType::Player/*, Vector2(100.0f, 100.0f)*/);
		//SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		////bgSr->SetSize(Vector2(3.0f, 3.0f));

		//graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Bubble");
		//bgSr->SetTexture(bgTexture);


		////Cat
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Pet);
		cat->AddComponent<CatScript>();

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* CatAnimator = cat->AddComponent<Animator>();

		CatAnimator->CreateAnimation(L"CatDownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		CatAnimator->CreateAnimation(L"CatRightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		CatAnimator->CreateAnimation(L"CatUpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		CatAnimator->CreateAnimation(L"CatLeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		CatAnimator->CreateAnimation(L"CatSitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		CatAnimator->CreateAnimation(L"CatLeak", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		CatAnimator->CreateAnimation(L"CatTired", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		CatAnimator->CreateAnimation(L"CatSleep", catTex
			, Vector2(0.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 0.1f);
		CatAnimator->CreateAnimation(L"CatStretch", catTex
			, Vector2(64.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 0.1f);

		CatAnimator->PlayAnimation(L"CatSitDown", false);

		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));


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