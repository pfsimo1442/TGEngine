#include "tgPlayerScript.h"
#include "tgInput.h"
#include "tgTransform.h"
#include "tgTime.h"
#include "tgGameObject.h"
#include "tgAnimator.h"
#include "tgCat.h"
#include "tgObject.h"
#include "tgResources.h"
#include "tgRigidbody.h"
#include "tgUIManager.h"
#include "tgSpriteRenderer.h"
#include "tgTexture.h"

namespace tg
{
	PlayerScript::PlayerScript()
		: mState(eState::Idle)
		, mCurrentWS(eWalkState::Null)
		, mLastWS(eWalkState::Null)
		, mAnimator(nullptr)
		, mPosSetter(false)
		, mProjTile(nullptr)
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
		static Vector3 pos = Vector3(-1, -1, 0);

		if (Input::GetKeyDown(eKeyCode::N))
		{
			ProjectTile* newTile = object::Instantiate<ProjectTile>(eLayerType::Player, pos);
			if (newTile)
			{
				SpriteRenderer* sr = newTile->AddComponent<SpriteRenderer>();
				if (sr)
				{
					auto tex = Resources::Find<graphics::Texture>(L"Player");
					if (tex)
						sr->SetSprite(tex);
				}

				mProjTile = newTile;
				pos.x += 1.0f;
			}
		}

		if (Input::GetKeyDown(eKeyCode::D))
		{
			if (mProjTile)
			{
				object::Destroy(mProjTile);
				mProjTile = nullptr;
			}
		}
	}

	void PlayerScript::LateUpdate()
	{
		
	}

	void PlayerScript::Render()
	{

	}

	void PlayerScript::AttackEffect()
	{
		
	}

	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		//if (!(other->GetOwner()->GetLayerType() == eLayerType::None
		//	|| other->GetOwner()->GetLayerType() == eLayerType::BackGround
		//	|| other->GetOwner()->GetLayerType() == eLayerType::Platform
		//	|| other->GetOwner()->GetLayerType() == eLayerType::Tile))
		//{
		//	if (mPosSetter)
		//	{
		//		other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(400.0f, 500.0f));
		//		mPosSetter = false;
		//	}
		//	else
		//	{
		//		other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 200.0f));
		//		mPosSetter = true;
		//	}
		//}
	}

	void PlayerScript::OnCollisionStay(Collider* other)
	{

	}

	void PlayerScript::OnCollisionExit(Collider* other)
	{
		
	}

	void PlayerScript::idle()
	{
		
	}

	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		Vector3 dir = Vector3::Zero;
		float spd = 500.0f;
		
		if (Input::GetKey(eKeyCode::Arrow_Right))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			//mCurrentWS = PlayerScript::eWalkState::Right;
			rb->AddForce(Vector2(200.0f, 0.0f));
			
		}
		if (Input::GetKey(eKeyCode::Arrow_Left))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			//mCurrentWS = PlayerScript::eWalkState::Left;
			rb->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::Arrow_Up))
		{
			//pos.y -= 100.0f * Time::DeltaTime();
			//mCurrentWS = PlayerScript::eWalkState::Up;
			rb->AddForce(Vector2(0.0f, 200.0f));
		}
		if (Input::GetKey(eKeyCode::Arrow_Down))
		{
			//pos.y += 100.0f * Time::DeltaTime();
			//mCurrentWS = PlayerScript::eWalkState::Down;
			rb->AddForce(Vector2(0.0f, -200.0f));
		}

		//dir.Normalize();
		//rb->AddForce(dir * spd);
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
			mState = eState::Idle;
			if (mLastWS != eWalkState::Null)
				mAnimator->PlayAnimation(L"CatSitDown", false);
			mLastWS = eWalkState::Null;
		}
	}
	void PlayerScript::water()
	{
		if (mAnimator->IsCompleteAnimation())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIdle");
		}
	}
}