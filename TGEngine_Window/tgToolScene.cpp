#include "tgToolScene.h"
#include "tgApplication.h"
#include "tgObject.h"
#include "tgTile.h"
#include "tgTilemapRenderer.h"
#include "tgResources.h"
#include "tgTexture.h"
#include "tgCamera.h"
#include "tgRenderer.h"
#include "tgInput.h"

extern tg::Application application;

namespace tg
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}

	void ToolScene::Initialize()
	{
		//// Main Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2((float)application.GetWidth() / 2, (float)application.GetHeight() / 2));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		////main camera - set target
		//cameraComp->SetTarget(tile);

		Scene::Initialize();
	}

	void ToolScene::Update()
	{
		Scene::Update();
	}

	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyUp(eKeyCode::Mouse_Left))
		{
			Vector2 pos = Input::GetMousePosition();

			Vector2 coord = (pos / TilemapRenderer::TileSize).integer();

			//// Tilemap
			Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
			tile->GetComponent<Transform>()->SetPositionStyle(Vector2(0.0f, 0.0f));
			TilemapRenderer* tmRenderer = tile->AddComponent<TilemapRenderer>();
			tmRenderer->SetSize(Vector2(4.0f, 4.0f));
			tmRenderer->SetTileSize(Vector2(16.0f, 16.0f));
			tmRenderer->SetTexture(Resources::Find<graphics::Texture>(L"PlatformSpringSDV"));
			tmRenderer->SetCellCoordination(TilemapRenderer::SelectedCell);

			tile->SetTilePosition(coord);
		}
	
	}
	
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		// grid
		for (size_t ni = 0; ni < 50; ni++)
		{
			MoveToEx(hdc, TilemapRenderer::TileSize.x * ni, 0, NULL);
			LineTo(hdc, TilemapRenderer::TileSize.x * ni, 1000);
		}
		for (size_t ni = 0; ni < 50; ni++)
		{
			MoveToEx(hdc, 0, TilemapRenderer::TileSize.y * ni,  NULL);
			LineTo(hdc, 1000, TilemapRenderer::TileSize.y * ni);
		}
	}

	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}
}

LRESULT CALLBACK WndToolProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		tg::math::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;

		tg::math::Vector2 coord = (mousePosition / tg::TilemapRenderer::OriginTileSize).integer();
		tg::TilemapRenderer::SelectedCell = coord;
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		tg::graphics::Texture* tilemapTexture
			= tg::Resources::Find<tg::graphics::Texture>(L"PlatformSpringSDV");

		TransparentBlt(hdc
			, 0, 0
			, tilemapTexture->GetWidth(), tilemapTexture->GetHeight()
			, tilemapTexture->GetHdc()
			, 0, 0
			, tilemapTexture->GetWidth(), tilemapTexture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}