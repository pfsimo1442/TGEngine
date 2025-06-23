#include "tgAnimator.h"
#include "tgResources.h"

namespace tg
{
	Animator::Animator()
		: Component(eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mbLoop(false)
	{
	}
	Animator::~Animator()
	{
		for (auto& iter : mAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : mEvents)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void Animator::Initialize()
	{

	}

	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			Events* events = FindEvents(mActiveAnimation->GetName());

			if (mActiveAnimation->IsComplete() == true)
			{
				if (events)
					events->completeEvent();

				if (mbLoop == true)
					mActiveAnimation->Reset();
			}
		}
	}

	void Animator::LateUpdate()
	{
		
	}

	void Animator::Render(HDC hdc)
	{
		if (mActiveAnimation)
			mActiveAnimation->Render(hdc);
	}

	void Animator::CreateAnimationBySpriteSize(const std::wstring& name
		, graphics::Texture* spriteSheet
		, Vector2 leftTop
		, Vector2 size
		, Vector2 offset
		, UINT spriteLength
		, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->SetName(name);
		animation->CreateAnimation(name, spriteSheet
			, leftTop, size, offset, spriteLength, duration);

		animation->SetAnimator(this);

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));

		mAnimations.insert(std::make_pair(name, animation));
	}

	/*void Animator::CreateAnimationByCellCount(const std::wstring& name
		, graphics::Texture* spriteSheet
		, Vector2 leftTop
		, Vector2 rightBottom
		, Vector2 cellCount
		, Vector2 offset
		, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		////

		animation = new Animation();
		animation->SetName(name);
		animation->CreateAnimation(name, spriteSheet
			, leftTop, size, offset, spriteLength, duration);

		animation->SetAnimator(this);

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));

		mAnimations.insert(std::make_pair(name, animation));
	}*/

	void Animator::CreateAnimationByFolder(const std::wstring& name
		, const std::wstring& path
		, Vector2 offset
		, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		int fileCount = 0;
		std::filesystem::path fs(path);
		std::vector<graphics::Texture*> images = {};
		for (auto& p : std::filesystem::recursive_directory_iterator(fs))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = p.path();

			graphics::Texture* texture = Resources::Load<graphics::Texture>(fileName, fullName);
			images.push_back(texture);

			fileCount++;
		}

		UINT imageWidth = images[0]->GetWidth();
		UINT imageHeight = images[0]->GetHeight();
		Vector2 imageSize = Vector2((float)imageWidth, (float)imageHeight);
		UINT sheetWidth = imageWidth * fileCount;
		UINT sheetHeight = imageHeight;
		graphics::Texture* spriteSheet = graphics::Texture::Create(name, sheetWidth, sheetHeight);

		for (size_t ni = 0; ni < images.size(); ni++)
		{
			BitBlt(spriteSheet->GetHdc()
				, imageWidth * ni, 0
				, imageWidth, imageHeight
				, images[ni]->GetHdc()
				, 0, 0
				, SRCCOPY);
		}
		
		CreateAnimationBySpriteSize(name, spriteSheet
			, Vector2::Zero, imageSize
			, offset, fileCount, duration);
	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = mAnimations.find(name);

		if (iter == mAnimations.end())
			return nullptr;
		
		return iter->second;
	}

	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		if (mActiveAnimation)
		{
			Events* currentEvents = FindEvents(mActiveAnimation->GetName());
			if (currentEvents)
				currentEvents->endEvent();
		}

		Events* nextEvents = FindEvents(animation->GetName());
		if (nextEvents)
			nextEvents->startEvent();

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}

	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		auto iter = mEvents.find(name);

		if (iter == mEvents.end())
			return nullptr;

		return iter->second;
	}

	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->startEvent.mEvent;
	}

	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->completeEvent.mEvent;
	}

	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->endEvent.mEvent;
	}
}