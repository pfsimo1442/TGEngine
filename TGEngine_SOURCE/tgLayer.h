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
		virtual ~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);
		void EraseGameObject(GameObject* gameObject);

		std::vector<GameObject*>& GetGameObjects() { return mGameObjects; }

	private:
		void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjects);
		void deleteGameObjects(std::vector<GameObject*> gameObjects);
		void eraseDeadGameObject();

		std::vector<GameObject*> mGameObjects;
	};

	using GameObjectIter = std::vector<GameObject*>::iterator;
}