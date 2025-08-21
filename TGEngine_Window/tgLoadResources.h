#pragma once
#include "..\\TGEngine_SOURCE\\tgResources.h"
#include "..\\TGEngine_SOURCE\\tgTexture.h"
#include "..\\TGEngine_SOURCE\\tgAudioClip.h"

namespace tg
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\CatAlpha.bmp");
		Resources::Load<graphics::Texture>(L"PlayerSDV", L"..\\Resources\\Player.bmp");
		Resources::Load<graphics::Texture>(L"PlatformSpringSDV", L"..\\Resources\\SpringFloor.bmp");
		Resources::Load<graphics::Texture>(L"HPBAR", L"..\\Resources\\HPBAR.bmp");

		Resources::Load<AudioClip>(L"BGSound", L"..\\Resources\\Sound\\smw_bonus_game_end.wav");
	}
}