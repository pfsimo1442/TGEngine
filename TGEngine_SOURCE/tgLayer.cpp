#include "tgLayer.h"

namespace tg
{
	Layer::Layer()
		: mGameObjects{}
	{
	}
	Layer::~Layer()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr)
				continue;

			delete gameObject;
			gameObject = nullptr;
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{		
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		for (GameObjIter iter = mGameObjects.begin()
			; iter != mGameObjects.end();)
		{
			GameObject::eState activeState = (*iter)->GetActiveState();
			if (activeState == GameObject::eState::Dead)
			{
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;
				 
				continue;
			}

			iter++;
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
}