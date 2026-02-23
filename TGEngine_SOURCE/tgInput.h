#pragma once
#include "CommonInclude.h"

namespace tg
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Mouse_Left = VK_LBUTTON, Mouse_Right = VK_RBUTTON, Control_Break_Processing = VK_CANCEL,
		Mouse_Wheel = VK_MBUTTON, Mouse_X1 = VK_XBUTTON1, Mouse_X2 = VK_XBUTTON2,

		Backspace = VK_BACK, Tab = VK_TAB, Clear = VK_CLEAR, Enter = VK_RETURN,
		Shift = VK_SHIFT, Ctrl = VK_CONTROL, Alt = VK_MENU, Pause = VK_PAUSE, Lock_Captial = VK_CAPITAL,

		IME_Kana = VK_KANA, IME_Hangul = VK_HANGUL, IME_On = VK_IME_ON, IME_Junja = VK_JUNJA,
		IME_Final = VK_FINAL, IME_Hanja = VK_HANJA, IME_Kanji = VK_KANJI, IME_Off = VK_IME_OFF,
		Escape = VK_ESCAPE, IME_Convert = VK_CONVERT, IME_Nonconvert = VK_NONCONVERT, IME_Accept = VK_ACCEPT, IME_Mode_Change = VK_MODECHANGE,

		Spacebar = VK_SPACE, Page_Up = VK_PRIOR, Page_Down = VK_NEXT, Endkey = VK_END, Home = VK_HOME,

		Arrow_Left = VK_LEFT, Arrow_Right = VK_RIGHT, Arrow_Up = VK_UP, Arrow_Down = VK_DOWN,

		Select = VK_SELECT, Print = VK_PRINT, Execute = VK_EXECUTE, PrintScreen = VK_SNAPSHOT,
		Insert = VK_INSERT, Delete = VK_DELETE, Help = VK_HELP,

		K0 = 0x30, K1 = 0x31, K2 = 0x32, K3 = 0x33, K4 = 0x34, K5 = 0x35, K6 = 0x36, K7 = 0x37, K8 = 0x38, K9 = 0x39,

		Q = 0x51, W = 0x57, E = 0x45, R = 0x52, T = 0x54, Y = 0x59, U = 0x55, I = 0x49, O = 0x4F, P = 0x50,
		A = 0x41, S = 0x53, D = 0x44, F = 0x46, G = 0x47, H = 0x48, J = 0x4A, K = 0x4B, L = 0x4C,
		Z = 0x5A, X = 0x58, C = 0x43, V = 0x56, B = 0x42, N = 0x4E, M = 0x4D,

		Window_Left = VK_LWIN, Window_Right = VK_RWIN, Application = VK_APPS, Sleep = VK_SLEEP,

		N0 = VK_NUMPAD0, N1 = VK_NUMPAD1, N2 = VK_NUMPAD2, N3 = VK_NUMPAD3, N4 = VK_NUMPAD4,
		N5 = VK_NUMPAD5, N6 = VK_NUMPAD6, N7 = VK_NUMPAD7, N8 = VK_NUMPAD8, N9 = VK_NUMPAD9,

		Multiply = VK_MULTIPLY, Add = VK_ADD, Separator = VK_SEPARATOR,
		ubtract = VK_SUBTRACT, Decimal = VK_DECIMAL, Divide = VK_DIVIDE,

		F1 = VK_F1, F2 = VK_F2, F3 = VK_F3, F4 = VK_F4, F5 = VK_F5, F6 = VK_F6,
		F7 = VK_F7, F8 = VK_F8, F9 = VK_F9, F10 = VK_F10, F11 = VK_F11, F12 = VK_F12,
		F13 = VK_F13, F14 = VK_F14, F15 = VK_F15, F16 = VK_F16, F17 = VK_F17, F18 = VK_F18,
		F19 = VK_F19, F20 = VK_F20, F21 = VK_F21, F22 = VK_F22, F23 = VK_F23, F24 = VK_F24,

		Lock_Number = VK_NUMLOCK, Lock_Scroll = VK_SCROLL,

		Shift_Left = VK_LSHIFT, Shift_Right = VK_RSHIFT,
		Ctrl_Left = VK_LCONTROL, Ctrl_Right = VK_RCONTROL,
		Alt_Left = VK_LMENU, Alt_Right = VK_RMENU,

		Browser_Back = VK_BROWSER_BACK, Browser_Forward = VK_BROWSER_FORWARD,
		Browser_Refresh = VK_BROWSER_REFRESH, Browser_Stop = VK_BROWSER_STOP, Browser_Search = VK_BROWSER_SEARCH,
		Browser_Favorites = VK_BROWSER_FAVORITES, Browser_Start = VK_BROWSER_HOME,
		
		Volume_Mute = VK_VOLUME_MUTE, Volume_Down = VK_VOLUME_DOWN, Volume_Up = VK_VOLUME_UP,
		
		Media_Track_Next = VK_MEDIA_NEXT_TRACK, Media_Track_Previous = VK_MEDIA_PREV_TRACK,
		Media_Stop = VK_MEDIA_STOP, Media_Play_Pause = VK_MEDIA_PLAY_PAUSE,
		
		Launch_Mail = VK_LAUNCH_MAIL, Launch_Media_Select = VK_LAUNCH_MEDIA_SELECT,
		Launch_App1 = VK_LAUNCH_APP1, Launch_App2 = VK_LAUNCH_APP2,
		
		OEM_Equal = VK_OEM_PLUS, OEM_Comma = VK_OEM_COMMA, OEM_Dash = VK_OEM_MINUS, OEM_Period = VK_OEM_PERIOD,
		OEM_ANSI_Semicolon = VK_OEM_1, OEM_ANSI_Slash = VK_OEM_2, OEM_ANSI_Grave_Accent = VK_OEM_3,
		OEM_ANSI_Brace_Left = VK_OEM_4, OEM_ANSI_BackSlash = VK_OEM_5,
		OEM_ANSI_Brace_Right = VK_OEM_6, OEM_ANSI_Apostrophe = VK_OEM_7,
		OEM_CSA_Crtl_Right = VK_OEM_8, OEM_ISO_Backslash = VK_OEM_102,
		
		IME_Process = VK_PROCESSKEY, Packet = VK_PACKET,
		
		Attn = VK_ATTN, CrSel = VK_CRSEL, ExSel = VK_EXSEL,
		Erase_EOF = VK_EREOF, Play = VK_PLAY,
		Zoom = VK_ZOOM, PA1 = VK_PA1, OEM_Clear = VK_OEM_CLEAR,
		
		End,
	};

	enum class eMouseCode
	{
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			int vk_KeyCode;
			bool bPressed;
		};

		static void Initialze();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }

		__forceinline static math::Vector2 GetMousePosition() { return mMousePosition; }

	private:
		static void createKeys();
		static void clearKeys();
		static void updateKeys();
		static void updateKey(Key& key);

		static bool isKeyDown(eKeyCode code);
		static void getMousePositionByWindow();
		static void updateKeyDown(Key& key);
		static void updateKeyUp(Key& key);

	private:
		static std::vector<Key> Keys;
		static math::Vector2 mMousePosition;
	};
}