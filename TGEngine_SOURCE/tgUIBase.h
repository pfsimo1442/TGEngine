#pragma once
#include "tgEntity.h"

namespace tg
{
	class UIBase : public Entity
	{
	public:
		UIBase();
		~UIBase();

		/// <summary>
		/// Initializes the UI. This method is called when the UI is created or activated.
		/// </summary>
		void Initialize();
		/// <summary>
		/// Activates the UI. This method is called when the UI becomes active.
		/// </summary>
		void Active();
		/// <summary>
		/// Inactivates the UI. This method is called when the UI is no longer active.
		/// </summary>
		void Inactive();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		/// <summary>
		/// Clears the UI elements. This method is called to reset the UI state.
		/// </summary>
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInactive();
		virtual void OnUpdate();
		virtual void OnClear();

		enums::eUIType GetType() { return mType; }
		void SetFullScreen(bool fullScreen) { mbFullScreen = fullScreen; }
		bool IsFullScreen() { return mbFullScreen; }

	private:
		enums::eUIType mType;
		bool mbFullScreen;
		bool mbActive;
	};
}