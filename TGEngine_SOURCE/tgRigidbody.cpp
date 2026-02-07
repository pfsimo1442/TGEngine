#include "tgRigidbody.h"
#include "tgTime.h"
#include "tgTransform.h"
#include "tgGameObject.h"
#include "tgRenderer.h"
#include "tgCamera.h"

namespace tg
{
	Rigidbody::Rigidbody()
		: Component(eComponentType::Rigidbody)
		, mbIsOnGround(false)
		, mMass(1.0f)
		, mFriction(0.0f)
		, mForce(Vector2::Zero)
		, mAccelation(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mLimitedVelocity(Vector2(500.0f, 700.0f))
		, mGravitationalAcceleration(Vector2(0.0f, 1000.0f))
	{	
	}
	Rigidbody::~Rigidbody()
	{
	}

	void Rigidbody::Initialize()
	{

	}

	void Rigidbody::Update()
	{
		//mAccelation = mForce / mMass;
		//mVelocity += mAccelation * Time::DeltaTime();

		//if (mbIsOnGround)
		//{
		//	Vector2 gravity = mGravitationalAcceleration;
		//	gravity.Normalize();

		//	float dot = mVelocity.Dot(gravity);
		//	mVelocity -= gravity * dot;
		//}
		//else
		//{
		//	mVelocity += mGravitationalAcceleration * Time::DeltaTime();
		//}

		//Vector2 gravity = mGravitationalAcceleration;
		//gravity.Normalize();
		//float dot = mVelocity.Dot(gravity);
		//gravity *= dot;

		//Vector2 sideVelocity = mVelocity - gravity;
		//if (mLimitedVelocity.x < gravity.x)
		//	gravity.x = mLimitedVelocity.x;
		//if (mLimitedVelocity.y < gravity.y)
		//	gravity.y = mLimitedVelocity.y;

		//if (mVelocity != Vector2::Zero)
		//{
		//	Vector2 friction = -mVelocity;
		//	friction.Normalize();
		//	friction = friction * mFriction * mMass * Time::DeltaTime();

		//	if (mVelocity.Length() <= friction.Length())
		//		mVelocity = Vector2::Zero;
		//	else
		//		mVelocity += friction;
		//}

		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();
		//pos += mVelocity * Time::DeltaTime();
		//tr->SetPosition(pos);

		//mForce = Vector2::Zero;
	}

	void Rigidbody::LateUpdate()
	{

	}

	void Rigidbody::Render()
	{
		
	}
}