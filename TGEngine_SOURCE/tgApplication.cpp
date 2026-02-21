#include "tgApplication.h"
#include "tgRenderer.h"
#include "tgInput.h"
#include "tgTime.h"
#include "tgResources.h"
#include "tgSceneManager.h"
#include "tgCollisionManager.h"
#include "tgUIManager.h"
#include "tgFmod.h"
#include "tgApplicationEvent.h"
#include "tgMouseEvent.h"


namespace tg
{
	Application::Application()
		: mbLoaded(false)
		, mbRunning(false)
	{
		mWindow.SetEventCallback(TG_BIND_EVENT_FN(Application::OnEvent));
	}
	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd, int width, int height)
	{
		mWindow.SetHwnd(hwnd);
		AdjustWindowRect(hwnd, width, height);
		InitializeEtc();

		mGraphicDevice = std::make_unique<GraphicDevice_DX11>();
		mGraphicDevice->Initialize();
		renderer::Initialize();
		
		Fmod::Initialize();
		CollisionManager::Initialize();
		UIManager::Initialize();
		SceneManager::Initialize();

		mbRunning = true;
	}

	void Application::InitializeWindow(HWND hwnd)
	{
		SetWindowPos(hwnd, nullptr, mWindow.GetXPos(), mWindow.GetYPos()
			, mWindow.GetWindowWidth(), mWindow.GetWindowHeight(), 0);
		ShowWindow(hwnd, SW_SHOWDEFAULT);
	}

	void Application::AdjustWindowRect(HWND hwnd, int width, int height)
	{
		RECT rect = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
		::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		
		RECT winRect;
		::GetWindowRect(mWindow.GetHwnd(), &winRect);

		//window position
		mWindow.SetPos(winRect.left, winRect.top);

		// window size
		mWindow.SetWindowWidth(rect.right - rect.left);
		mWindow.SetWindowHeight(rect.bottom - rect.top);

		//client size
		mWindow.SetWidth(width);
		mWindow.SetHeight(height);

		InitializeWindow(hwnd);
	}

	void Application::ResizeGraphicDevice(UINT width, UINT height)
	{
		if (mGraphicDevice == nullptr)
			return;

		D3D11_VIEWPORT viewport = {};
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;
		viewport.Width = static_cast<float>(width);
		viewport.Height = static_cast<float>(height);
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;

		mWindow.SetWidth(static_cast<UINT>(viewport.Width));
		mWindow.SetHeight(static_cast<UINT>(viewport.Height));

		mGraphicDevice->Resize(viewport);
		renderer::FrameBuffer->Resize(static_cast<UINT>(viewport.Width), static_cast<UINT>(viewport.Height));
	}

	void Application::InitializeEtc()
	{
		Input::Initialze();
		Time::Initialize();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& e) -> bool
			{
				ResizeGraphicDevice(e.GetWidth(), e.GetHeight());
				return true;
			});

		dispatcher.Dispatch<MouseMovedEvent>([this](MouseMovedEvent& e) -> bool
			{
				return true;
			});
	}

	void Application::Run()
	{
		if (mbLoaded == false)
			mbLoaded = true;

		Update();
		LateUpdate();
		Render();

		Destroy();
	}

	void Application::Close()
	{
		mbRunning = false;
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		CollisionManager::Update();
		UIManager::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		UIManager::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		GetDevice()->ClearRenderTargetView();
		GetDevice()->ClearDepthStencilView();
		GetDevice()->BindViewPort();
		GetDevice()->BindDefaultRenderTarget();

		Time::Render();
		CollisionManager::Render();
		UIManager::Render();
		SceneManager::Render();

		//copy back buffer
		Microsoft::WRL::ComPtr<ID3D11Texture2D> src = GetDevice()->GetFrameBuffer();
		Microsoft::WRL::ComPtr<ID3D11Texture2D> dst = renderer::FrameBuffer->GetAttachmentTexture(0)->GetTexture();

		GetDevice()->CopyResource(dst.Get(), src.Get());
	}
	
	void Application::Present()
	{
		GetDevice()->Present();
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Release()
	{
		SceneManager::Release();
		UIManager::Release();
		Resources::Release();

		Fmod::Release();

		renderer::Release();

		if (mGraphicDevice)
		{
			mGraphicDevice.reset();
		}

		mbLoaded = false;
		mbRunning = false;
	}
}