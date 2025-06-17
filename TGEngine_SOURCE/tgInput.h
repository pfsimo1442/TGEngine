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

		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Arrow_Left, Arrow_Right, Arrow_Up, Arrow_Down,
		Mouse_Left, Mouse_Right, Mouse_Wheel, Mouse_Side1, Mouse_Side2,
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
	};
}