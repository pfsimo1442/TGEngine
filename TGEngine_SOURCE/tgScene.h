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
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();
		
		void AddGameObject(GameObject* gameObj, eLayerType type);
		void EraseGameObject(GameObject* gameObj);
		Layer* GetLayer(const eLayerType type) const { return mLayers[static_cast<UINT>(type)]; }

	private:
		void createLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}