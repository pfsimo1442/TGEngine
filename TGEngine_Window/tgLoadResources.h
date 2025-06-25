#pragma once
#include "..\\TGEngine_SOURCE\\tgResources.h"
#include "..\\TGEngine_SOURCE\\tgTexture.h"

namespace tg
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\CatAlpha.bmp");
		Resources::Load<graphics::Texture>(L"PlayerSDV", L"..\\Resources\\Player.bmp");
		Resources::Load<graphics::Texture>(L"PlatformSpringSDV", L"..\\Resources\\SpringFloor.bmp");
	}
}