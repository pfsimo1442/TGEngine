#include "tgRigidbody.h"
#include "tgTime.h"
#include "tgTransform.h"
#include "tgGameObject.h"

namespace tg
{
	Rigidbody::Rigidbody()
		: Component(enums::eComponentType::Rigidbody)
		, mMass(1.0f)
		, mFriction(10.0f)
		, mForce(Vector2::Zero)
		, mAcceleration(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mGravity(Vector2::Zero)
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
		mAcceleration = mForce / mMass;
		mVelocity += mAcceleration * Time::DeltaTime();

		if (mVelocity != Vector2::Zero)
		{
			Vector2 friction = -mVelocity;
			friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

			if (mVelocity.length() <= friction.length())
				mVelocity = Vector2::Zero;
			else
				mVelocity += friction;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos += mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);

		mForce.clear();
	}

	void Rigidbody::LateUpdate()
	{

	}

	void Rigidbody::Render(HDC hdc)
	{

	}
}