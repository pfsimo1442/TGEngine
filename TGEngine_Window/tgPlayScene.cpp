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


		//// Player
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Particle);
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"PlayerSDV");
		Animator* aPlayer = mPlayer->AddComponent<Animator>();

		aPlayer->CreateAnimation(L"PlayerIdle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);


		aPlayer->PlayAnimation(L"PlayerIdle", false);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(0.5f, 0.5f));
	


		//// Cat
		Cat* aCat = object::Instantiate<Cat>(enums::eLayerType::Pet);
		aCat->AddComponent<CatScript>();

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* CatAnimator = aCat->AddComponent<Animator>();

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
			, Vector2(0.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 1.2f);
		CatAnimator->CreateAnimation(L"CatStretch", catTex
			, Vector2(64.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 0.5f);

		CatAnimator->PlayAnimation(L"CatSitDown", false);

		aCat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		aCat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));


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