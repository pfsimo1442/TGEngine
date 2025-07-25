#include "tgMath.h"

namespace tg::math
{
	Vector2 Vector2::One = Vector2(1.0f, 1.0f);
	Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);
	Vector2 Vector2::Right = Vector2(1.0f, 0.0f);
	Vector2 Vector2::Left = Vector2(-1.0f, 0.0f);
	Vector2 Vector2::Up = Vector2(0.0f, -1.0f);
	Vector2 Vector2::Down = Vector2(0.0f, 1.0f);

	Vector3 Vector3::One = Vector3(1.0f, 1.0f, 1.0f);
	Vector3 Vector3::Zero = Vector3(0.0f, 0.0f, 0.0f);
}