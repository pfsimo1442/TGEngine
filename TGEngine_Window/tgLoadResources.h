#pragma once
#include "..\\TGEngine_SOURCE\\tgResources.h"
#include "..\\TGEngine_SOURCE\\tgTexture.h"

namespace tg
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"D:\\Engine\\TGEngine\\Resources\\CloudOcean.png");
	}
}