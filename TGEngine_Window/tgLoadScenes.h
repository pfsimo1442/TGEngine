#pragma once
#include "..\\TGEngine_SOURCE\\tgSceneManager.h"

#include "tgPlayScene.h"
#include "tgTitleScene.h"

namespace tg
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}