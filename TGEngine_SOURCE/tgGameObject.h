#pragma once

namespace tg
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }


	private:
		// gameobject's coorderate
		float mX;
		float mY;
	};
}