#pragma once
#include "guiEditor.h"
#include "guiEditorWindow.h"

#include "..//TGEngine_SOURCE//tgEvent.h"

namespace gui
{
	class ImguiEditor : public EditorWindow
	{
	public:
		ImguiEditor();
		~ImguiEditor();

		void Initialize() override;
		void Update() override;
		void OnGUI() override;
		void Run() override;

		void OnEnable() override;
		void OnDisable() override;
		void OnDestroy() override;
		void OnEvent(tg::Event& e) override;

		void Begin();
		void End();
		void Release();
		void SetDarkThemeColors();

		void BlockEvents(bool block) { mbBlockEvent = block; }

	private:
		bool mbBlockEvent;
	};
}