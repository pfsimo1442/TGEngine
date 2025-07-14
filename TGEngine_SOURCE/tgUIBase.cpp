#include "tgUIBase.h"

namespace tg
{
	UIBase::UIBase(enums::eUIType type)
		: mType(type)
		, mbMouseOn(false)
	{
	}
	UIBase::~UIBase()
	{
	}

	void UIBase::Initialize()
	{
		OnInit();
	}

	void UIBase::Active()
	{
		mbActive = true;
		OnActive();
	}

	void UIBase::Inactive()
	{
		mbActive = false;
		OnInactive();
	}

	void UIBase::Update()
	{
		if (mbActive)
			OnUpdate();
	}

	void UIBase::LateUpdate()
	{
		if (mbActive)
			OnLateUpdate();
	}

	void UIBase::Render(HDC hdc)
	{
		if (mbActive)
			OnRender(hdc);
	}

	void UIBase::UIClear()
	{
		OnClear();
	}

	void UIBase::OnInit()
	{

	}

	void UIBase::OnActive()
	{

	}

	void UIBase::OnInactive()
	{

	}

	void UIBase::OnUpdate()
	{

	}

	void UIBase::OnLateUpdate()
	{

	}

	void UIBase::OnRender(HDC hdc)
	{

	}

	void UIBase::OnClear()
	{

	}
}