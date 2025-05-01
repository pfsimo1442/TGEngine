#include "tgCatScript.h"
#include "tgInput.h"
#include "tgTransform.h"
#include "tgTime.h"
#include "tgGameObject.h"
#include "tgAnimator.h"

namespace tg
{
	CatScript::CatScript()
		: mState(CatScript::eState::SitDown)
		, mCurrentWS(CatScript::eWalkState::Null)
		, mLastWS(CatScript::eWalkState::Null)
		, mAnimator(nullptr)
		, wasSleep(false)
		, isStretch(false)
		, wasStretch(false)
		, mTime(0.0f)
		, mStretchTime(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}

	void CatScript::Initialize()
	{
	}

	void CatScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();

		switch (mState)
		{
		case CatScript::eState::SitDown:
			sitDown();
			break;
		case CatScript::eState::Walk:
			walk();
			break;
		case CatScript::eState::Leak:
			break;
		case CatScript::eState::Tired:
			tired();
			break;
		case CatScript::eState::Sleep:
			sleep();
			break;
		case CatScript::eState::Stretch:
			stretch();
			break;
		default:
			break;
		}
	}

	void CatScript::LateUpdate()
	{

	}

	void CatScript::Render(HDC hdc)
	{

	}

	void CatScript::sitDown()
	{
		mTime += Time::DeltaTime();
		if (mTime > 1.0f && wasSleep == false)
		{
			int isSleep = rand() % 10;
			if (isSleep == 0)
			{
				mState = eState::Sleep;
				mAnimator->PlayAnimation(L"CatSleep");
			}
			wasSleep = true; 
		}
		if (mTime > 2.0f)
		{
			wasSleep = false;
			mState = CatScript::eState::Walk;
			int direction = (rand() % 4);
			mDirection = (eDirection)direction;
			if (mDirection == CatScript::eDirection::Right)
			{
				if (rand() % 4 == 0)
					isStretch = true;
				else
					isStretch = false;
			}
			playWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
	}

	void CatScript::walk()
	{
		mTime += Time::DeltaTime();
		if (mTime > 0.5f && isStretch == true)
		{
			mState = eState::Stretch;
			mAnimator->PlayAnimation(L"CatStretch", false);
			isStretch = false;
			wasStretch = true;
		}
		if (mTime > 1.0f)
		{
			int isTired = rand() % 6;
			if (isTired == 0)
			{
				mState = eState::Tired;
				mAnimator->PlayAnimation(L"CatTired", false);
			}
			else
			{
				mState = CatScript::eState::SitDown;
				mAnimator->PlayAnimation(L"CatSitDown", false);
			}
			mTime = 0.0f;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
	}

	void CatScript::tired()
	{

	}

	void CatScript::sleep()
	{

	}

	void CatScript::stretch()
	{
		mStretchTime += Time::DeltaTime();
		if (mStretchTime > 1.0f && wasStretch == true)
		{
			mState = CatScript::eState::Walk;
			mAnimator->PlayAnimation(L"CatRightWalk");
			wasStretch = false;
			mStretchTime = 0.0f;
		}
	}

	void CatScript::playWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"CatLeftWalk");
			break;
		case CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"CatRightWalk");
			break;
		case CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"CatDownWalk");
			break;
		case CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"CatUpWalk");
			break;
		default:
			assert(false);
			break;
		}
	}

	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();

		switch (mDirection)
		{
		case CatScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case CatScript::eDirection::Right:
			if (isStretch == false && wasStretch == true)
				pos.x;
			else
				pos.x += 100.0f * Time::DeltaTime();
			break;
		case CatScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
}