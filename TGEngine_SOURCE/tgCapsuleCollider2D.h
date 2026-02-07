#pragma once
#include "tgCollider.h"

namespace tg
{
	class CapsuleCollider2D : public Collider
	{
	public:
		CapsuleCollider2D();
		virtual ~CapsuleCollider2D();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
		
		//float GetHeight() { return mHeight; }
		//void SetHeight(float height) { mHeight = height; }
		//float GetRadius() { return mRadius; }
		//void SetRadius(float radius) { mRadius = radius; }

	private:
		//float mHeight;
		//float mRadius;
	};
}