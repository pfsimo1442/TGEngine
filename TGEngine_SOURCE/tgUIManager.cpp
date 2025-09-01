#include "tgUIManager.h"
#include "tgUIHUD.h"
#include "tgUIButton.h"

namespace tg
{
	std::unordered_map<enums::eUIType, UIBase*> UIManager::mUIs = {};
	std::stack<UIBase*> UIManager::mUIBases = {};
	std::queue<enums::eUIType> UIManager::mRequestUIQueue = {};
	UIBase* UIManager::mActiveUI = nullptr;

	void UIManager::Initialize()
	{
		//// Create UI object 
		//UIHUD* hud = new UIHUD();
		//mUIs.insert(std::make_pair(enums::eUIType::HUD, hud));

		//UIButton* button = new UIButton();
		//mUIs.insert(std::make_pair(enums::eUIType::Button, button));
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
		if (mUIBases.size() <= 0)
			return;

		std::vector<UIBase*> buff;

		UIBase* uibase = nullptr;
		while (mUIBases.size() > 0)
		{
			uibase = mUIBases.top();
			mUIBases.pop();

			buff.push_back(uibase);
		}
		std::reverse(buff.begin(), buff.end());

		for (UIBase* ui : buff)
		{
			ui->Render(hdc);
			mUIBases.push(ui);
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

	void UIManager::Release()
	{
		for (auto iter : mUIs)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void UIManager::Push(enums::eUIType type)
	{
		mRequestUIQueue.push(type);
	}

	void UIManager::Pop(enums::eUIType type)
	{
		if (mUIBases.size() <= 0)
			return;

		std::stack<UIBase*> tempStack;

		UIBase* uiBase = nullptr;
		while (mUIBases.size() > 0)
		{
			uiBase = mUIBases.top();
			mUIBases.pop();

			if (uiBase->GetType() != type)
			{
				tempStack.push(uiBase);
				continue;
			}

			if (uiBase->IsFullScreen())
			{
				std::stack<UIBase*> uiBases = mUIBases;
				while (!uiBases.empty())
				{
					UIBase* uiBase = uiBases.top();
					uiBases.pop();
					if (uiBase)
					{
						uiBase->Active();
						break;
					}
				}
			}

			uiBase->UIClear();
		}

		while (tempStack.size() > 0)
		{
			uiBase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uiBase);
		}
	}

	void UIManager::PopAll()
	{

	}
}