#pragma once
#include "tgGameObject.h"
#include "tgGraphicDevice_DX11.h"
#include "tgEvent.h"
#include "tgWindow.h"

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
		void ResizeGraphicDevice(UINT width, UINT height);
		void InitializeEtc();

		void OnEvent(Event& e);

		void Run();
		void Close();

		void Update();
		void LateUpdate();
		void Render();
		void Present();
		void Destroy();
		void Release();

		Window& GetWindow() { return mWindow; }
		bool IsLoaded() const { return mbLoaded; }
		void IsLoaded(const bool load) { mbLoaded = load; }

		bool IsRunning() const { return mbRunning; }

	private:
		bool mbLoaded;
		bool mbRunning;

		std::unique_ptr<graphics::GraphicDevice_DX11> mGraphicDevice;
		
		Window mWindow;
	};
}