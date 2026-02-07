#pragma once
#include "..//TGEngine_SOURCE//tgSceneManager.h"

#include "tgLoadingScene.h"
#include "tgPlayScene.h"
#include "tgTitleScene.h"

namespace tg
{
	void LoadScenes()
	{
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene");

		SceneManager::LoadScene(L"LoadingScene");
	}
}