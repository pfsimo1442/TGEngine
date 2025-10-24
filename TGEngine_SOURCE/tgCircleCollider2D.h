#pragma once
#include "tgCollider.h"

namespace tg
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		float GetRadius() { return mRadius; }
		void SetRadius(float radius) { mRadius = radius; }

	private:
		float mRadius;
	};
}