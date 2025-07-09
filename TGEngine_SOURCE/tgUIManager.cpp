#include "tgUIManager.h"

namespace tg
{
	std::unordered_map<enums::eUIType, UIBase*> UIManager::mUIs = {};
	std::stack<UIBase*> UIManager::mUIBases = {};
	std::queue<enums::eUIType> UIManager::mRequestUIQueue = {};
	UIBase* UIManager::mActiveUI = nullptr;

	void UIManager::Initialize()
	{

	}

	void UIManager::Onload(enums::eUIType type)
	{
		std::unordered_map<enums::eUIType, UIBase*>::iterator iter
			= mUIs.find(type);

		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}

	void UIManager::Update()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Update();
				uiBases.pop();
			}
		}
		
		if (mRequestUIQueue.size() > 0)
		{
			enums::eUIType requestUIType = mRequestUIQueue.front();
			mRequestUIQueue.pop();
			Onload(requestUIType);
		}
	}

	void UIManager::LateUpdate()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}

	void UIManager::Render(HDC hdc)
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Render(hdc);
				uiBases.pop();
			}
		}
	}

	void UIManager::OnComplete(UIBase* addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		if (addUI->IsFullScreen())
		{
			std::stack<UIBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				UIBase* uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase)
				{
					uiBase->Inactive();
				}
			}
		}

		mUIBases.push(addUI);
		mActiveUI = nullptr;
	}

	void UIManager::OnFail()
	{
		mActiveUI = nullptr;
	}

	void UIManager::Push(enums::eUIType type)
	{
		mRequestUIQueue.push(type);
	}

	void UIManager::Pop(enums::eUIType type)
	{
		if (mUIBases.size() <= 0)
			return;

		UIBase* uiBase = nullptr;
		while (mUIBases.size() < 0)
		{
			uiBase = mUIBases.top();
			mUIBases.pop();
		}
	}

	void UIManager::PopAll()
	{

	}
}