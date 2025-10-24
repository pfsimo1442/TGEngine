#include "tgGameObject.h"
#include "tgInput.h"
#include "tgTime.h"
#include "tgTransform.h"

namespace tg::object
{
		void Destroy(GameObject* gameObject)
		{
			if (gameObject != nullptr)
				gameObject->death();
		}
}

namespace tg
{

	GameObject::GameObject()
		: mState(eState::Active)
		, mLayerType(eLayerType::None)
	{
		mComponents.resize((UINT)eComponentType::End);
		initializeTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}

	void GameObject::Render()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render();
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}
