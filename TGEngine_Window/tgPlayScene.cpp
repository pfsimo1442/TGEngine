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
		


		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		//SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		//sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.25f);

		animator->PlayAnimation(L"CatFrontMove");
		//sr->SetTexture(packmanTexture);

		GameObject* bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
		bgSr->SetTexture(bgTexture);



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