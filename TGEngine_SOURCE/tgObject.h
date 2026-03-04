#pragma once
#include "tgComponent.h"
#include "tgGameObject.h"
#include "tgLayer.h"
#include "tgScene.h"
#include "tgSceneManager.h"
#include "tgTransform.h"
#include "tgApplication.h"
#include "tgGameObjectEvent.h"

extern tg::Application application;

namespace tg::object
{
	template <typename T>
	static T* Instantiate(eLayerType type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);

		Scene* activeScene = SceneManager::GetActiveScene();
		SceneManager::PushEvent(new tg::GameObjectCreatedEvent(gameObject, activeScene));

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(eLayerType type, Vector3 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);

		Transform* tr = gameObject->template GetComponent<Transform>();
		tr->SetPosition(position);

		Scene* activeScene = SceneManager::GetActiveScene();
		SceneManager::PushEvent(new tg::GameObjectCreatedEvent(gameObject, activeScene));

		return gameObject;
	}

	static void DontDestroyOnLoad(GameObject* gameObject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();

		activeScene->EraseGameObject(gameObject);

		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}

	static void Destroy(GameObject* gameObject)
	{
		if (gameObject != nullptr)
			gameObject->death();

		Scene* activeScene = SceneManager::GetActiveScene();
		SceneManager::PushEvent(new tg::GameObjectDestroyedEvent(gameObject, activeScene));
	}
}