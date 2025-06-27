#include "tgRigidbody.h"
#include "tgTime.h"
#include "tgTransform.h"
#include "tgGameObject.h"
#include "tgRenderer.h"
#include "tgCamera.h"

namespace tg
{
	Rigidbody::Rigidbody()
		: Component(enums::eComponentType::Rigidbody)
		, mbIsOnGround(false)
		, mMass(1.0f)
		, mFriction(0.0f)
		, mForce(Vector2::Zero)
		, mAcceleration(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mLimitedVelocity(700.0f)
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
		mAcceleration = mForce / mMass;
		mVelocity += mAcceleration * Time::DeltaTime();

		if (mbIsOnGround)
		{
			Vector2 gravity = mGravitationalAcceleration;
			gravity.normalize();

			float dot = Vector2::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			mVelocity += mGravitationalAcceleration * Time::DeltaTime();
		}

		Vector2 gravity = mGravitationalAcceleration;
		gravity.normalize();
		float dot = Vector2::Dot(mVelocity, gravity);
		gravity *= dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitedVelocity.x < gravity.x)
			gravity.x = mLimitedVelocity.x;
		if (mLimitedVelocity.y < gravity.y)
			gravity.y = mLimitedVelocity.y;

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
		wchar_t str1[50] = L"";
		swprintf_s(str1, 50, L"Time: %f", mForce.y);
		int len1 = wcsnlen_s(str1, 50);

		TextOut(hdc, 0, 0, str1, len1);


		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		Vector2 lineEndPos = pos + mVelocity / 5.0f;

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		MoveToEx(hdc, pos.x, pos.y, nullptr);
		LineTo(hdc, lineEndPos.x, lineEndPos.y);

		SelectObject(hdc, oldPen);
		DeleteObject(redPen);
	}
}