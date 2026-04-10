#include "tgInput.h"
#include "tgApplication.h"

extern tg::Application application;

namespace tg
{
	std::vector<Input::Key> Input::Keys = {};
	Vector2 Input::mMousePosition = Vector2::Zero;

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

		UINT width = application.GetWindow().GetWidth();
		UINT height = application.GetWindow().GetHeight();

		mMousePosition.x = -1.0f;
		mMousePosition.y = -1.0f;

		if (static_cast<UINT>(mousePos.x) > 0 && static_cast<UINT>(mousePos.x) < width)
			mMousePosition.x = static_cast<float>(mousePos.x);

		if (static_cast<UINT>(mousePos.y) > 0 && static_cast<UINT>(mousePos.y) < height)
			mMousePosition.y = static_cast<float>(mousePos.y);
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