#pragma once
#include "..\\TGEngine_SOURCE\\tgScript.h"

namespace tg
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			//LeftWalk,
			//RightWalk,
			//DownWalk,
			//UpWalk,
			Walk, 
			Leak, 
			Tired, 
			Sleep,
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
		void sitDown();
		void move();

	private:
		eState mState;
		eWalkState mCurrentWS;
		eWalkState mLastWS;
		class Animator* mAnimator;
	};
}