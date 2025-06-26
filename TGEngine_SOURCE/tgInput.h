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
		Mouse_Left, Mouse_Right, Control_Break_Processing, Mouse_Wheel, Mouse_X1, Mouse_X2,
		Backspace, Tab, Clear, Enter, Shift, Ctrl, Alt, Pause, Lock_Captial,
		IME_Kana, IME_Hangul, IME_On, IME_Junja, IME_Final, IME_Hanja, IME_Kanji, IME_Off,
		Escape, IME_Convert, IME_Nonconvert, IME_Accept, IME_Mode_Change,
		Spacebar, Page_Up, Page_Down, Endkey, Home,
		Arrow_Left, Arrow_Right, Arrow_Up, Arrow_Down,
		Select, Print, Execute, PrintScreen, Insert, Delete, Help,
		K0, K1, K2, K3, K4, K5, K6, K7, K8, K9,
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Window_Left, Window_Right, Application, Sleep,
		N0, N1, N2, N3, N4, N5, N6, N7, N8, N9,
		Multiply, Add, Separator, Subtract, Decimal, Divide,
		F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
		Lock_Number, Lock_Scroll,
		Shift_Left, Shift_Right, Ctrl_Left, Ctrl_Right, Alt_Left, Alt_Right,
		Browser_Back, Browser_Forward, Browser_Refresh, Browser_Stop, Browser_Search, Browser_Favorites, Browser_Start,
		Volume_Mute, Volume_Down, Volume_Up,
		Media_Track_Next, Media_Track_Previous, Media_Stop, Media_Play_Pause,
		Launch_Mail, Launch_Media_Select, Launch_App1, Launch_App2,
		OEM_Equal, OEM_Comma, OEM_Dash, OEM_Period,
		OEM_ANSI_Semicolon, OEM_ANSI_Slash, OEM_ANSI_Grave_Accent, OEM_ANSI_Brace_Left, OEM_ANSI_BackSlash, OEM_ANSI_Brace_Right, OEM_ANSI_Apostrophe,
		OEM_CSA_Crtl_Right, OEM_ISO_Backslash,
		IME_Process, Packet,
		Attn, CrSel, ExSel, Erase_EOF, Play, Zoom, PA1, OEM_Clear, 
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialze();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }

		__forceinline static math::Vector2 GetMousePosition() { return mMousePosition; }
		__forceinline static math::Vector2 GetOnMousePosition() { return mOnMousePosition; }
		__forceinline static bool IsMouseOnWindow() { return mbMouseOnWindow; }

	private:
		static void createKeys();
		static void clearKeys();
		static void updateKeys();
		static void updateKey(Key& key);

		static bool isKeyDown(eKeyCode code);
		static void getMousePositionByWindow ();
		static void updateKeyDown(Key& key);
		static void updateKeyUp(Key& key);

	private:
		static std::vector<Key> Keys;
		static math::Vector2 mMousePosition;
		static math::Vector2 mOnMousePosition;
		static bool mbMouseOnWindow;
	};
}