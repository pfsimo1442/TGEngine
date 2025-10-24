#pragma once
#include "..\\TGEngine_SOURCE\\tgScene.h"
#include "tgTile.h"

namespace tg
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnEnter() override;
		void OnExit() override;

		void Save();
		void Load();

	private:
		void renderGreed();
		void createTileObject();

	private:
		class Camera* mMainCamera;
		std::vector<Tile*> mTiles;
	};
}

LRESULT CALLBACK WndToolProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);