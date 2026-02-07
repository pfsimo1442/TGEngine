#pragma once
#include "tgComponent.h"

namespace tg
{
	class Rigidbody : public Component	
	{
	public:
		Rigidbody();
		virtual ~Rigidbody();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetMass(float mass) { mMass = mass; }
		float GetMass() { return mMass; }
		void SetFriction(float friction) { mFriction = friction; }
		float GetFriction() { return mFriction; }
		void AddForce(Vector2 force) { mForce += force; }
		void SetIsOnGround(bool isOnGround) { mbIsOnGround = isOnGround; }
		bool IsOnGround() { return mbIsOnGround; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
		void AddVelocity(Vector2 velocity) { mVelocity += velocity; }
		Vector2 GetVelocity() { return mVelocity; }
		void SetLimitedVelocity(Vector2 lim) { mLimitedVelocity = lim; }
		Vector2 GetLimitedVelocity() { return mLimitedVelocity; }
		void SetGravitationalAcceleration(Vector2 g) { mGravitationalAcceleration = g; }
		Vector2 GetGravitationalAcceleration() { return mGravitationalAcceleration; }

	private:
		bool mbIsOnGround;

		float mMass;
		float mFriction;

		Vector2 mForce;
		Vector2 mAccelation;
		Vector2 mVelocity;
		Vector2 mLimitedVelocity;
		Vector2 mGravitationalAcceleration;
	};
}