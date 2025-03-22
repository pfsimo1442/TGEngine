#pragma once
#include "CommonInclude.h"
#include "tgGameObject.h"

namespace tg
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;

		// player
		//float mX;
		//float mY;
		GameObject mPlayer;
	};
}