#pragma once
#include "tgEntity.h"
#include "CommonInclude.h"
#include "tgGameObject.h"

namespace tg
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

		

	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};
}