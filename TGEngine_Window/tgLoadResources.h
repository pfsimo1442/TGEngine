#pragma once
#include "..\\TGEngine_SOURCE\\tgResources.h"
#include "..\\TGEngine_SOURCE\\tgTexture.h"

namespace tg
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan", L"..\\Resources\\img\\pacman\\0.png");
	}
}