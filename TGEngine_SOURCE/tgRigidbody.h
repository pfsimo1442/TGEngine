#pragma once
#include "tgComponent.h"

namespace tg
{
	class Rigidbody : public Component	
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetMass(float mass) { mMass = mass; }
		void SetFriction(float friction) { mFriction = friction; }
		void AddForce(Vector2 force) { mForce += force; }

	private:
		float mMass;
		float mFriction;

		Vector2 mForce;
		Vector2 mAcceleration;
		Vector2 mVelocity;
		Vector2 mGravity;
	};
}