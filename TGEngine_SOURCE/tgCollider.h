#pragma once
#include "tgComponent.h"

namespace tg
{
	class Collider : public Component
	{
	public:
		Collider(eColliderType type);
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		UINT32 GetID() { return mID; }
		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 offset) { mOffset = offset; }
		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }

		eColliderType GetColliderType() { return mType; }

	private:
		static UINT32 mCollisionID;

		UINT32 mID;
		Vector2 mOffset;
		Vector2 mSize;

		eColliderType mType;
	};
}