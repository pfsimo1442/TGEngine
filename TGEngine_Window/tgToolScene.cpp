#include "tgToolScene.h"
#include "tgApplication.h"
#include "tgObject.h"
#include "tgTile.h"
#include "tgTilemapRenderer.h"
#include "tgResources.h"
#include "tgTexture.h"
#include "tgCamera.h"
#include "tgCameraScript.h"
#include "tgRenderer.h"
#include "tgInput.h"

extern tg::Application application;

static Vector2 TransInt(Vector2 a)
{
	return Vector2((float)(int)a.x, (float)(int)a.y);
}

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
		mMainCamera = camera->AddComponent<Camera>();
		CameraScript* camScr = camera->AddComponent<CameraScript>();

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

		if (Input::GetKeyDown(eKeyCode::Mouse_Left) && Input::IsMouseOnWindow() && TilemapRenderer::SelectedCell.x != -1.0f)
		{

			Vector2 pos = Input::GetMousePosition();
			pos = renderer::mainCamera->CalculateTilePosition(pos);

			Vector2 coord = (pos / TilemapRenderer::TileSize);
			coord = TransInt(coord);

			//// Tilemap
			Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
			tile->GetComponent<Transform>()->SetPositionStyle(Vector2(0.0f, 0.0f));
			TilemapRenderer* tmRenderer = tile->AddComponent<TilemapRenderer>();
			tmRenderer->SetSize(Vector2(3.0f, 3.0f));
			tmRenderer->SetTileSize(Vector2(16.0f, 16.0f));
			tmRenderer->SetTexture(Resources::Find<graphics::Texture>(L"PlatformSpringSDV"));
			tmRenderer->SetCellCoordination(TilemapRenderer::SelectedCell);

			tile->SetTilePosition(coord);
			mTiles.push_back(tile);
		}

		// Command
		if (Input::GetKey(eKeyCode::Ctrl_Left))
		{
			if (Input::GetKeyDown(eKeyCode::S))
				Save();

			if (Input::GetKeyDown(eKeyCode::L))
				Load();
		}

		if (Input::GetKeyDown(eKeyCode::N))
			SceneManager::LoadScene(L"PlayScene");
	}
	
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		// grid
		for (size_t ni = 0; ni < 50; ni++)
		{
			Vector2 gridPos = renderer::mainCamera->CalculatePosition(Vector2(TilemapRenderer::TileSize.x * ni, 0.0f));
			
			MoveToEx(hdc, gridPos.x, 0, NULL);
			LineTo(hdc, gridPos.x, 1000);
		}
		for (size_t ni = 0; ni < 50; ni++)
		{
			Vector2 gridPos = renderer::mainCamera->CalculatePosition(Vector2(0.0f, TilemapRenderer::TileSize.y * ni));

			MoveToEx(hdc, 0, gridPos.y,  NULL);
			LineTo(hdc, 1000, gridPos.y);
		}
	}

	void ToolScene::OnEnter()
	{
		Scene::OnEnter();

		renderer::mainCamera = mMainCamera;
	}
	
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}

	void ToolScene::Save()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;
		
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");

		for (Tile* tile : mTiles)
		{
			TilemapRenderer* tmr = tile->GetComponent<TilemapRenderer>();
			Transform* tr = tile->GetComponent<Transform>();

			Vector2 sourceCellCoord = tmr->GetCellCoordination();
			Vector2 pos = tr->GetPosition();

			int cellCoordX = (int)(sourceCellCoord.x);
			int cellCoordY = (int)(sourceCellCoord.y);
			int posX = (int)(pos.x);
			int posY = (int)(pos.y);
			fwrite(&cellCoordX, sizeof(int), 1, pFile);
			fwrite(&cellCoordY, sizeof(int), 1, pFile);
			fwrite(&posX, sizeof(int), 1, pFile);
			fwrite(&posY, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}
	
	void ToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		while (true)
		{
			int cellCoordX = 0;
			int cellCoordY = 0;
			int posX = 0;
			int posY = 0;

			if (fread(&cellCoordX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&cellCoordY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile, Vector2((float)posX, (float)posY));
			tile->GetComponent<Transform>()->SetPositionStyle(Vector2(0.0f, 0.0f));
			TilemapRenderer* tmRenderer = tile->AddComponent<TilemapRenderer>();
			tmRenderer->SetSize(Vector2(3.0f, 3.0f));
			tmRenderer->SetTileSize(Vector2(16.0f, 16.0f));
			tmRenderer->SetTexture(Resources::Find<graphics::Texture>(L"PlatformSpringSDV"));
			tmRenderer->SetCellCoordination(Vector2((float)cellCoordX, (float)cellCoordY));

			mTiles.push_back(tile);
		}

		fclose(pFile);
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

		tg::math::Vector2 coord = (mousePosition / tg::TilemapRenderer::OriginTileSize);
		coord = TransInt(coord);
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