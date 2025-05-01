#include "tgPlayerScript.h"
#include "tgInput.h"
#include "tgTransform.h"
#include "tgTime.h"
#include "tgGameObject.h"
#include "tgAnimator.h"

namespace tg
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mCurrentWS(PlayerScript::eWalkState::Null)
		, mLastWS(PlayerScript::eWalkState::Null)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
	}

	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();
		
		switch (mState)
		{
		case PlayerScript::eState::Idle:
			idle();
			break;
		case PlayerScript::eState::Walk:
			move();
			break;
		case PlayerScript::eState::Leak:
			break;
		case PlayerScript::eState::Tired:
			break;
		case PlayerScript::eState::Sleep:
			break;
		case PlayerScript::eState::Water:
			break;
		case PlayerScript::eState::Stretch:
			break;
		default:
			break;
		}
	}

	void PlayerScript::LateUpdate()
	{
		
	}

	void PlayerScript::Render(HDC hdc)
	{

	}

	void PlayerScript::idle()
	{
		if (Input::GetKeyDown(eKeyCode::Mouse_Left))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"CatRightWalk");

			Vector2 mousePos = Input::GetMousePosition();
		}
	}

	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
			mCurrentWS = PlayerScript::eWalkState::Right;
		}
		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
			mCurrentWS = PlayerScript::eWalkState::Left;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::DeltaTime();
			mCurrentWS = PlayerScript::eWalkState::Up;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();
			mCurrentWS = PlayerScript::eWalkState::Down;
		}


		bool chkDA = false;
		bool chkWS = false;
		if (Input::GetKey(eKeyCode::D) && Input::GetKey(eKeyCode::A))
			chkDA = true;
		if (Input::GetKey(eKeyCode::W) && Input::GetKey(eKeyCode::S))
			chkWS = true;

		if (chkDA == true)
		{
			mCurrentWS = PlayerScript::eWalkState::Null;
			if (Input::GetKey(eKeyCode::W) && chkWS == false)
				mCurrentWS = PlayerScript::eWalkState::Up;
			if (Input::GetKey(eKeyCode::S) && chkWS == false)
				mCurrentWS = PlayerScript::eWalkState::Down;
			if (chkWS == true)
				mCurrentWS = PlayerScript::eWalkState::Null;
		}
		else if (chkWS == true)
		{
			mCurrentWS = PlayerScript::eWalkState::Null;
			if (Input::GetKey(eKeyCode::D))
				mCurrentWS = PlayerScript::eWalkState::Right;
			if (Input::GetKey(eKeyCode::A))
				mCurrentWS = PlayerScript::eWalkState::Left;
		}
		

		tr->SetPosition(pos);

		if (mCurrentWS != mLastWS)
		{
			if (mCurrentWS == PlayerScript::eWalkState::Right)
				mAnimator->PlayAnimation(L"CatRightWalk");
			if (mCurrentWS == PlayerScript::eWalkState::Left)
				mAnimator->PlayAnimation(L"CatLeftWalk");
			if (mCurrentWS == PlayerScript::eWalkState::Up)
				mAnimator->PlayAnimation(L"CatUpWalk");
			if (mCurrentWS == PlayerScript::eWalkState::Down)
				mAnimator->PlayAnimation(L"CatDownWalk");
			if (mCurrentWS == PlayerScript::eWalkState::Null)
				mAnimator->PlayAnimation(L"CatSitDown", false);
		}

		mLastWS = mCurrentWS;

		if ((Input::GetKeyUp(eKeyCode::W) && !(Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::D)))
			|| (Input::GetKeyUp(eKeyCode::S) && !(Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::D)))
			|| (Input::GetKeyUp(eKeyCode::A) && !(Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::D)))
			|| (Input::GetKeyUp(eKeyCode::D) && !(Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::A)))
			)
		{
			mState = PlayerScript::eState::Idle;
			if (mLastWS != PlayerScript::eWalkState::Null)
				mAnimator->PlayAnimation(L"CatSitDown", false);
			mLastWS = PlayerScript::eWalkState::Null;
		}
	}
}