#pragma once
#include "..\\TGEngine_SOURCE\\tgScene.h"

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
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

		void Save();
		void Load();

	private:

	};
}

LRESULT CALLBACK WndToolProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);