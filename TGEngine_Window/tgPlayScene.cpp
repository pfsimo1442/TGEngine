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
		{
			bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BG");
			sr->SetTexture(bg);

			Scene::Initialize();
		}
		
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

		wchar_t str[50] = L"Play Scene ";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
	//	Transform* tr = bg->GetComponent<Transform>();
	//	tr->SetPosition(Vector2(0, 0));
	}
}