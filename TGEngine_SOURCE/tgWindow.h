#pragma once
#include "CommonInclude.h"
#include "tgEvent.h"

namespace tg
{
	struct WindowProps
	{
		std::wstring Title;
		UINT Width;
		UINT Height;
		HWND Hwnd;

		WindowProps(const std::wstring& title = L"TG Engine", 
			UINT width = 1280,
			UINT height = 720)
			: Title(title)
			, Width(width)
			, Height(height)
			, Hwnd(NULL)
		{
		}
	};

	class Window
	{
	public:
		struct WindowData
		{
			std::wstring Title;
			HWND Hwnd;
			
			UINT Width;
			UINT Height;

			UINT WindowWidth;
			UINT WindowHeight;

			UINT X;
			UINT Y;

			bool VSync;
			EventCallbackFn EventCallback;
		};

		void Initalize();
		void SetWindowResize(UINT width, UINT height);
		void SetCursorPos(double x, double y);

		void SetEventCallback(const EventCallbackFn& callback) { mData.EventCallback = callback; }

		HWND GetHwnd() { return mData.Hwnd; }
		UINT GetWidth() { return mData.Width; }
		UINT GetHeight() { return mData.Height; }
		void SetHwnd(HWND hwnd) { mData.Hwnd = hwnd; }
		void SetWidth(UINT width) { mData.Width = width; }
		void SetHeight(UINT height) { mData.Height = height; }

		UINT GetWindowWidth() { return mData.WindowWidth; }
		UINT GetWindowHeight() { return mData.WindowHeight; }
		void SetWindowWidth(UINT width) { mData.WindowWidth = width; }
		void SetWindowHeight(UINT height) { mData.WindowHeight = height; }

		UINT GetXPos() { return mData.X; }
		UINT GetYPos() { return mData.Y; }
		void SetPos(UINT x, UINT y) { mData.X = x; mData.Y = y; }

	private:
		WindowData mData;
	};
}