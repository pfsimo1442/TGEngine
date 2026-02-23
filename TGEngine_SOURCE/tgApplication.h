#pragma once
#include "tgGameObject.h"
#include "tgGraphicDevice_DX11.h"
#include "tgEvent.h"
#include "tgWindow.h"
#include "tgApplicationEvent.h"
#include "tgMouseEvent.h"
#include "tgKeyEvent.h"
#include "tgEventQueue.h"

namespace tg
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, int width, int height);
		void InitializeWindow(HWND hwnd);
		void AdjustWindowRect(HWND hwnd, int width, int height);
		void ResizeGraphicDevice(WindowResizeEvent& e);
		void InitializeEtc();
		void InitializeEventHandlers();

		void OnWindowEvent(Event& e);

		void Run();
		void Close();

		void Update();
		void LateUpdate();
		void Render();
		void Present();
		void EndOfFrame();
		void Release();

		void PushEvent(Event* e) { mEventQueue.Push(e); }

		Window& GetWindow() { return mWindow; }
		bool IsLoaded() const { return mbLoaded; }
		void IsLoaded(const bool load) { mbLoaded = load; }

		bool IsRunning() const { return mbRunning; }

	private:
		bool mbLoaded;
		bool mbRunning;

		std::unique_ptr<graphics::GraphicDevice_DX11> mGraphicDevice;
		
		Window mWindow;
		EventQueue mEventQueue;
	};
}