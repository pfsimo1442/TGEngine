#include "tgToolScene.h"
#include "tgApplication.h"
#include "tgObject.h"
#include "tgTile.h"
#include "tgTilemapRenderer.h"
#include "tgResources.h"
#include "tgTexture.h"
#include "tgCamera.h"
#include "tgRenderer.h"

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


		//// Tilemap
		Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
		tile->GetComponent<Transform>()->SetPosition(Vector2(128.0f, 128.0f));
		tile->GetComponent<Transform>()->SetPositionStyle(Vector2(0.0f, 0.0f));
		TilemapRenderer* tmRenderer = tile->AddComponent<TilemapRenderer>();
		tmRenderer->SetSize(Vector2(4.0f, 4.0f));
		tmRenderer->SetTileSize(Vector2(16.0f, 16.0f));
		tmRenderer->SetCellCoordination(Vector2(7, 0));

		/*graphics::Texture* tmTexture = */tmRenderer->SetTexture(Resources::Find<graphics::Texture>(L"PlatformSpringSDV"));

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
	}
	
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		// grid
		for (size_t ni = 0; ni < 50; ni++)
		{
			MoveToEx(hdc, (16 * 4) * ni, 0, NULL);
			LineTo(hdc, (16 * 4) * ni, 1000);
		}
		for (size_t ni = 0; ni < 50; ni++)
		{
			MoveToEx(hdc, 0, (16 * 4) * ni,  NULL);
			LineTo(hdc, 1000, (16 * 4) * ni);
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