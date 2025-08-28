#include "tgUIButton.h"
#include "tgInput.h"

namespace tg
{
	UIButton::UIButton()
		: UIBase(enums::eUIType::Button)
	{

	}

	UIButton::~UIButton()
	{
	}

	void UIButton::OnInit()
	{
		SetPosition(Vector2(200.0f, 200.0f));
		SetSize(Vector2(200.0f, 200.0f));

		mOnClick = std::bind(&UIButton::ButtonClick, this);
	}

	void UIButton::OnActive()
	{
	}

	void UIButton::OnInactive()
	{
	}

	void UIButton::OnUpdate()
	{
		Vector2 mousePos = Input::GetMousePosition();

		if (mPosition.x <= mousePos.x && mousePos.x <= mPosition.x + mSize.x
			&& mPosition.y <= mousePos.y && mousePos.y <= mPosition.y + mSize.y)
			mbMouseOn = true;
		else
			mbMouseOn = false;

		
		if (mbMouseOn)
		{
			if (Input::GetKeyDown(eKeyCode::Mouse_Left))
				mOnClick();
		}
	}

	void UIButton::OnLateUpdate()
	{
	}

	void UIButton::OnRender(HDC hdc)
	{
		::Rectangle(hdc
			, (int)mPosition.x, (int)mPosition.y
			, mPosition.x + mSize.x, mPosition.y + mSize.y);
	}

	void UIButton::OnClear()
	{

	}

	void UIButton::ButtonClick()
	{
		int a = 0;
	}

}