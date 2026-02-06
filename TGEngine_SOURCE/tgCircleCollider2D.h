#pragma once
#include "tgCollider.h"

namespace tg
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		virtual ~CircleCollider2D();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		float GetRadius() { return mRadius; }
		void SetRadius(float radius) { mRadius = radius; }

	private:
		float mRadius;
	};
}