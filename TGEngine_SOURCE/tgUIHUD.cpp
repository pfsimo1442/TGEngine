#include "tgUIHUD.h"
#include "tgResources.h"

namespace tg
{
	UIHUD::UIHUD()
		: UIBase(enums::eUIType::HUD)
	{
	}

	UIHUD::~UIHUD()
	{
	}

	void UIHUD::OnInit()
	{
		mTexture = Resources::Find<graphics::Texture>(L"HPBAR");
	}

	void UIHUD::OnActive()
	{

	}

	void UIHUD::OnInactive()
	{
	}

	void UIHUD::OnUpdate()
	{
	}

	void UIHUD::OnLateUpdate()
	{
	}

	void UIHUD::OnRender()
	{
		//TransparentBlt(hdc
		//	, 0, 0
		//	, mTexture->GetWidth()
		//	, mTexture->GetHeight()
		//	, mTexture->GetHdc()
		//	, 0, 0
		//	, mTexture->GetWidth()
		//	, mTexture->GetHeight()
		//	, RGB(255, 0, 255));
	}

	void UIHUD::OnClear()
	{
		
	}
}