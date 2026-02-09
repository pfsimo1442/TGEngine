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
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[static_cast<UINT>(comp->GetType())] = comp;

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

		eState GetActiveState() const { return mState; }

		void SetActiveState(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Pause;
		}

		bool IsActive() const { return mState == eState::Active; }
		bool IsDead() const { return mState == eState::Dead; }
		eLayerType GetLayerType() const { return mLayerType; }
		void SetLayerType(const eLayerType layerType) { mLayerType = layerType; }

	private:
		void initializeTransform();
		void death() { mState = eState::Dead; }

	private:
		eState mState;
		std::vector<Component*> mComponents;
		eLayerType mLayerType;
	};
}