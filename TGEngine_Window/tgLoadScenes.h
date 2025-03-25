#pragma once
#include "..\\TGEngine_SOURCE\\tgSceneManager.h"
#include "tgPlayScene.h"

namespace tg
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}