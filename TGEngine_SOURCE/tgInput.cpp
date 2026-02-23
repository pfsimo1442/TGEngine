#include "tgInput.h"
#include "tgApplication.h"

extern tg::Application application;

namespace tg
{
	std::vector<Input::Key> Input::Keys = {};
	math::Vector2 Input::mMousePosition = math::Vector2::Zero;
	math::Vector2 Input::mOnMousePosition = math::Vector2::Zero;
	bool Input::mbMouseOnWindow = false;

	void Input::Initialze()
	{
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::createKeys()
	{
		for (int vk = 0; vk <= 0xFF; ++vk) // 0x00 ~ 0xFF 범위의 Virtual Key Code 검사
		{
			eKeyCode keyCode = static_cast<eKeyCode>(vk); // VK_ 값을 eKeyCode로 변환

			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = keyCode;
			key.vk_KeyCode = vk;

			Keys.push_back(key);
		}
	}

	void Input::clearKeys()
	{
		for (Key& key : Keys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;

			key.bPressed = false;
		}
	}

	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}

	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetWindow().GetHwnd(), &mousePos);

		if (0 < mousePos.x && (UINT)mousePos.x < application.GetWindow().GetWidth()
			&& 0 < mousePos.y && (UINT)mousePos.y < application.GetWindow().GetHeight())
		{
			mbMouseOnWindow = true;
			mOnMousePosition.x = (float)(mousePos.x);
			mOnMousePosition.y = (float)(mousePos.y);
		}
		else
			mbMouseOnWindow = false;

		mMousePosition.x = (float)(mousePos.x);
		mMousePosition.y = (float)(mousePos.y);
	}

	void Input::updateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.keyCode))
			{
				updateKeyDown(key);
			}
			else
			{
				updateKeyUp(key);
			}

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(static_cast<int>(code)) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.bPressed = false;
	}
}