#include "tgInput.h"
#include "tgApplication.h"

extern tg::Application application;

namespace tg
{
	std::vector<Input::Key> Input::Keys = {};
	math::Vector2 Input::mMousePosition = math::Vector2::Zero;
	math::Vector2 Input::mOnMousePosition = math::Vector2::Zero;
	bool Input::mbMouseOnWindow = false;

	int ASCII[(int)eKeyCode::End] =
	{
		VK_LBUTTON, VK_RBUTTON, VK_CANCEL, VK_MBUTTON, VK_XBUTTON1, VK_XBUTTON2,
		VK_BACK, VK_TAB, VK_CLEAR, VK_RETURN, VK_SHIFT, VK_CONTROL, VK_MENU, VK_PAUSE, VK_CAPITAL,
		VK_KANA, VK_HANGEUL/*VK_HANGUL*/, VK_IME_ON, VK_JUNJA, VK_FINAL, VK_HANJA, VK_KANJI, VK_IME_OFF,
		VK_ESCAPE, VK_CONVERT, VK_NONCONVERT, VK_ACCEPT, VK_MODECHANGE,
		VK_SPACE, VK_PRIOR, VK_NEXT, VK_END, VK_HOME,
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
		VK_SELECT, VK_PRINT, VK_EXECUTE, VK_SNAPSHOT, VK_INSERT, VK_DELETE, VK_HELP,
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LWIN, VK_RWIN, VK_APPS, VK_SLEEP,
		VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9,
		VK_MULTIPLY, VK_ADD, VK_SEPARATOR, VK_SUBTRACT, VK_DECIMAL, VK_DIVIDE,
		VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12, 
		VK_F13, VK_F14, VK_F15, VK_F16, VK_F17, VK_F18, VK_F19, VK_F20, VK_F21, VK_F22, VK_F23, VK_F24,
		VK_NUMLOCK, VK_SCROLL,
		VK_LSHIFT, VK_RSHIFT, VK_LCONTROL, VK_RCONTROL, VK_LMENU, VK_RMENU,
		VK_BROWSER_BACK, VK_BROWSER_FORWARD, VK_BROWSER_REFRESH, VK_BROWSER_STOP, VK_BROWSER_SEARCH,VK_BROWSER_FAVORITES, VK_BROWSER_HOME,
		VK_VOLUME_MUTE, VK_VOLUME_DOWN, VK_VOLUME_UP,
		VK_MEDIA_NEXT_TRACK, VK_MEDIA_PREV_TRACK, VK_MEDIA_STOP, VK_MEDIA_PLAY_PAUSE,
		VK_LAUNCH_MAIL, VK_LAUNCH_MEDIA_SELECT, VK_LAUNCH_APP1, VK_LAUNCH_APP2,
		VK_OEM_PLUS, VK_OEM_COMMA, VK_OEM_MINUS, VK_OEM_PERIOD,
		VK_OEM_1, VK_OEM_2, VK_OEM_3, VK_OEM_4, VK_OEM_5, VK_OEM_6, VK_OEM_7, 
		VK_OEM_8, VK_OEM_102,
		VK_PROCESSKEY, VK_PACKET,
		VK_ATTN, VK_CRSEL, VK_EXSEL, VK_EREOF, VK_PLAY, VK_ZOOM, VK_PA1, VK_OEM_CLEAR,
	};

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
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

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
		ScreenToClient(application.GetHwnd(), &mousePos);

		if (0 < mousePos.x && (UINT)mousePos.x < application.GetWidth()
			&& 0 < mousePos.y && (UINT)mousePos.y < application.GetHeight())
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
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
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