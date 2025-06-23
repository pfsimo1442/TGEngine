#pragma once
#include "CommonInclude.h"
#include "tgComponent.h"
#include "tgCollider.h"
//#include "tgObject.h"

namespace tg::object
{
	void Destroy(GameObject* gameObject);
}

namespace tg
{
	class GameObject
	{
	public:
		friend void object::Destroy(GameObject* obj);

		enum class eState
		{
			Active,
			Pause,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}
		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

		void SetActiveState(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Pause;
		}
		eState GetActiveState() { return mState; }
		void SetLayerType(eLayerType layerType) { mLayerType = layerType; }
		eLayerType GetLayerType() { return mLayerType; }

		bool IsActive() { return mState == eState::Active; }
		bool IsPause() { return mState == eState::Pause; }
		bool IsDead() { return mState == eState::Dead; }

	private:
		void initializeTransform();
		void death() { mState = eState::Dead; }

	private:
		eState mState;
		std::vector<Component*> mComponents;
		eLayerType mLayerType;
	};
}