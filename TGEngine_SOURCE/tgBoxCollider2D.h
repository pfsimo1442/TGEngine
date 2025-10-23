#pragma once
#include "tgCollider.h"

namespace tg
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		//Vector2 GetSize() { return mSize; }

	private:
		//Vector2 mSize;
	};
}