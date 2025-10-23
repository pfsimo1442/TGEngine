#pragma once
#include "tgCollider.h"

namespace tg
{
	class CapsuleCollider2D : public Collider
	{
	public:
		CapsuleCollider2D();
		~CapsuleCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		
		//float GetHeight() { return mHeight; }
		//void SetHeight(float height) { mHeight = height; }
		//float GetRadius() { return mRadius; }
		//void SetRadius(float radius) { mRadius = radius; }

	private:
		//float mHeight;
		//float mRadius;
	};
}