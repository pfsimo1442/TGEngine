#include "tgDontDestroyOnLoad.h"

namespace tg
{
	DontDestroyOnLoad::DontDestroyOnLoad()
	{
	}
	DontDestroyOnLoad::~DontDestroyOnLoad()
	{
	}

	void DontDestroyOnLoad::Initialize() 
	{
		Scene::Initialize();
	}

	void DontDestroyOnLoad::Update()
	{
		Scene::Update();
	}

	void DontDestroyOnLoad::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void DontDestroyOnLoad::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void DontDestroyOnLoad::OnEnter()
	{
		Scene::OnEnter();
	}

	void DontDestroyOnLoad::OnExit()
	{
		Scene::OnExit();
	}
}