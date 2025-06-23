#pragma once
#include "..\\TGEngine_SOURCE\\tgScript.h"

namespace tg
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk, 
			Leak, 
			Tired, 
			Sleep,
			Water,
			Stretch, 
		};

		enum class eWalkState
		{
			Right,
			Left,
			Up,
			Down,
			Null, 
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void AttackEffect();

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		void idle();
		void move();
		void water();

	private:
		eState mState;
		eWalkState mCurrentWS;
		eWalkState mLastWS;
		class Animator* mAnimator;

		bool mPosSetter;
	};
}