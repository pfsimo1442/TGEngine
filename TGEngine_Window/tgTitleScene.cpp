#include "tgTitleScene.h"
#include "tgInput.h"
#include "tgPlayScene.h"
#include "tgSceneManager.h"

namespace tg
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}
	
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
			SceneManager::LoadScene(L"PlayScene");
		if (Input::GetKeyDown(eKeyCode::T))
			SceneManager::LoadScene(L"ToolScene");
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
}