#include "tgPlayerScript.h"
#include "tgInput.h"
#include "tgTransform.h"
#include "tgTime.h"
#include "tgGameObject.h"
#include "tgAnimator.h"
#include "tgCat.h"
#include "tgCatScript.h"
#include "tgObject.h"
#include "tgResources.h"
#include "tgRigidbody.h"

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
			water();
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

	void PlayerScript::AttackEffect()
	{
		Cat* mCat = object::Instantiate<Cat>(enums::eLayerType::Pet);
		CatScript* catScr = mCat->AddComponent<CatScript>();

		catScr->SetPlayer(GetOwner());

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAni = mCat->AddComponent<Animator>();

		catAni->CreateAnimationBySpriteSize(L"CatWalkDown", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatWalkRight", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatWalkUp", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatWalkLeft", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatSit", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatLeak", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatTired", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAni->CreateAnimationBySpriteSize(L"CatSleep", catTex
			, Vector2(0.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 1.2f);
		catAni->CreateAnimationBySpriteSize(L"CatStretch", catTex
			, Vector2(64.0f, 224.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 2, 0.5f);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		mCat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
		mCat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		catAni->PlayAnimation(L"CatSit", false);
	}

	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		if (!(other->GetOwner()->GetLayerType() == eLayerType::None
			|| other->GetOwner()->GetLayerType() == eLayerType::BackGround
			|| other->GetOwner()->GetLayerType() == eLayerType::Platform
			|| other->GetOwner()->GetLayerType() == eLayerType::Tile))
		{
			if (mPosSetter)
			{
				other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(400.0f, 500.0f));
				mPosSetter = false;
			}
			else
			{
				other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 200.0f));
				mPosSetter = true;
			}
		}
	}

	void PlayerScript::OnCollisionStay(Collider* other)
	{

	}

	void PlayerScript::OnCollisionExit(Collider* other)
	{
		
	}

	void PlayerScript::idle()
	{
		if (Input::GetKeyDown(eKeyCode::Mouse_Left))
		{
			mState = PlayerScript::eState::Water;
			mAnimator->PlayAnimation(L"PlayerWaterDown", false);

			Vector2 mousePos = Input::GetMousePosition();
		}

		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		Vector2 dir = Vector2::Zero;
		float spd = 500.0f;

		if (Input::GetKey(eKeyCode::D))
			dir += Vector2::Right;
		if (Input::GetKey(eKeyCode::A))
			dir += Vector2::Left;
		
		rb->AddForce(dir.normalize() * spd);

		float V = 450.0f;
		//float jumpForce = V * rb->GetMass() / Time::DeltaTime() - rb->GetFriction() * rb->GetMass() * rb->GetMass();
		//if (jumpForce < 0.0f)
		//	jumpForce = 0.0f;

		if ((Input::GetKeyDown(eKeyCode::W) || Input::GetKey(eKeyCode::W)) && rb->IsOnGround())
		{
			//rb->AddForce(Vector2::Up.normalize() * jumpForce);
			rb->AddVelocity(Vector2::Up.normalize() * V);
			rb->SetIsOnGround(false);
		}
		/*if (Input::GetKey(eKeyCode::S))
			dir += Vector2::Down;*/

	}

	void PlayerScript::move()
	{
		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();
		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		Vector2 dir = Vector2::Zero;
		float spd = 500.0f;
		
		if (Input::GetKey(eKeyCode::D))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			//mCurrentWS = PlayerScript::eWalkState::Right;
			dir += Vector2::Right;
			
		}
		if (Input::GetKey(eKeyCode::A))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			//mCurrentWS = PlayerScript::eWalkState::Left;
			dir += Vector2::Left;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			//pos.y -= 100.0f * Time::DeltaTime();
			//mCurrentWS = PlayerScript::eWalkState::Up;
			dir += Vector2::Up;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			//pos.y += 100.0f * Time::DeltaTime();
			//mCurrentWS = PlayerScript::eWalkState::Down;
			dir += Vector2::Down;
		}

		rb->AddForce(dir.normalize() * spd);
		//tr->SetPosition(pos);

		//bool chkDA = false;
		//bool chkWS = false;
		//if (Input::GetKey(eKeyCode::D) && Input::GetKey(eKeyCode::A))
		//	chkDA = true;
		//if (Input::GetKey(eKeyCode::W) && Input::GetKey(eKeyCode::S))
		//	chkWS = true;

		//if (chkDA == true)
		//{
		//	mCurrentWS = PlayerScript::eWalkState::Null;
		//	if (Input::GetKey(eKeyCode::W) && chkWS == false)
		//		mCurrentWS = PlayerScript::eWalkState::Up;
		//	if (Input::GetKey(eKeyCode::S) && chkWS == false)
		//		mCurrentWS = PlayerScript::eWalkState::Down;
		//	if (chkWS == true)
		//		mCurrentWS = PlayerScript::eWalkState::Null;
		//}
		//else if (chkWS == true)
		//{
		//	mCurrentWS = PlayerScript::eWalkState::Null;
		//	if (Input::GetKey(eKeyCode::D))
		//		mCurrentWS = PlayerScript::eWalkState::Right;
		//	if (Input::GetKey(eKeyCode::A))
		//		mCurrentWS = PlayerScript::eWalkState::Left;
		//}

		//if (mCurrentWS != mLastWS)
		//{
		//	if (mCurrentWS == PlayerScript::eWalkState::Right)
		//		mAnimator->PlayAnimation(L"CatRightWalk");
		//	if (mCurrentWS == PlayerScript::eWalkState::Left)
		//		mAnimator->PlayAnimation(L"CatLeftWalk");
		//	if (mCurrentWS == PlayerScript::eWalkState::Up)
		//		mAnimator->PlayAnimation(L"CatUpWalk");
		//	if (mCurrentWS == PlayerScript::eWalkState::Down)
		//		mAnimator->PlayAnimation(L"CatDownWalk");
		//	if (mCurrentWS == PlayerScript::eWalkState::Null)
		//		mAnimator->PlayAnimation(L"CatSitDown", false);
		//}

		//mLastWS = mCurrentWS;

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
	void PlayerScript::water()
	{
		if (mAnimator->IsCompleteAnimation())
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIdle");
		}
	}
}