#pragma once
#include "..\\TGEngine_SOURCE\\tgSceneManager.h"

#include "tgLoadingScene.h"
#include "tgPlayScene.h"
#include "tgTitleScene.h"
#include "tgToolScene.h"

namespace tg
{
	void LoadScenes()
	{
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");

		//SceneManager::CreateScene<ToolScene>(L"ToolScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::LoadScene(L"LoadingScene");
	}
}