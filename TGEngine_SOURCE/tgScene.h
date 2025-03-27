#pragma once
#include "tgEntity.h"
#include "tgGameObject.h"
#include "tgLayer.h"

namespace tg
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();
		
		void AddGameObject(GameObject* gameObj, const eLayerType type);

	private:
		void CreateLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}