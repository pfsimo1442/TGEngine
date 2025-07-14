#pragma once
#include "tgEntity.h"

namespace tg
{
	class UIBase : public Entity
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent();
			}
			std::function<void()> mEvent;
		};

		UIBase(enums::eUIType type);
		virtual ~UIBase();

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
		virtual void OnLateUpdate();
		virtual void OnRender(HDC hdc);
		virtual void OnClear();

		enums::eUIType GetType() { return mType; }
		void SetType(enums::eUIType type) { mType = type; }
		void SetFullScreen(bool fullScreen) { mbFullScreen = fullScreen; }
		bool IsFullScreen() { return mbFullScreen; }
		Vector2 GetPosition() { return mPosition; }
		void SetPosition(Vector2 pos) { mPosition = pos; }
		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }

	protected:
		Vector2 mPosition;
		Vector2 mSize;

		bool mbMouseOn;

	private:
		enums::eUIType mType;
		bool mbFullScreen;
		bool mbActive;

		UIBase* mParentUI;
	};
}