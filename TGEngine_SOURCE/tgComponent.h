#pragma once
#include "tgEntity.h"

namespace tg
{
	using namespace enums;

	class GameObject;
	class Component : public Entity	
	{
	public:
		Component(eComponentType type);
		virtual ~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() const { return mOwner; }
		eComponentType GetType() const { return mType; }

	private:
		GameObject* mOwner;
		eComponentType mType;
	};
}
