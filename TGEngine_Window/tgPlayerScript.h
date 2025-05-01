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

	private:
		void idle();
		void move();

	private:
		eState mState;
		eWalkState mCurrentWS;
		eWalkState mLastWS;
		class Animator* mAnimator;
	};
}