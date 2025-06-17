#pragma once
#include "..\\TGEngine_SOURCE\\tgScript.h"
#include "..\\TGEngine_SOURCE\\tgTransform.h"

namespace tg
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			Sit,
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

		enum class eDirection
		{
			Left, 
			Right,
			Down,
			Up,
			End,
		};

		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPlayer(GameObject* player) { mPlayer = player; }

	private: //fun
		void sit();
		void walk();
		void tired();
		void sleep();
		void stretch();

		void playWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);

	private: //var
		eState mState;
		eWalkState mCurrentWS;
		eWalkState mLastWS;
		eDirection mDirection;
		class Animator* mAnimator;

		bool wasSleep;
		bool isStretch;
		bool wasStretch;

		float mTime;
		float mDeathTime;
		float mStretchTime;

		GameObject* mPlayer;
		
		float mRadian;
	};
}