#pragma once
#include <cmath>

namespace tg::math
{
#define PI 3.141592f

	static float ConvertDegreeToRadian(float degree) { return (degree * (PI / 180)); }
	static float ConvertRadianToDegree(float radian) { return (radian * (180 / PI)); }

	struct Vector2
	{
		// Static Funtions
		static Vector2 Rotate(Vector2 vector, float degree)
		{
			float radian = (degree / 180) * PI;
			vector.normalize();
			float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
			float y = sinf(radian) * vector.x + cosf(radian) * vector.y;
		
			return Vector2(x, y);
		}
		static float Dot(Vector2& v1, Vector2& v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}
		static float Cross(Vector2& v1, Vector2& v2)
		{
			return v1.x * v2.y - v1.y * v2.x;
		}

		// Stocks
		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f)
		{
		}
		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{
		}

		// Signed Operator
		Vector2 operator+()
		{
			return Vector2(x, y);
		}
		Vector2 operator-()
		{
			return Vector2(-x, -y);
		}

		// Arithmetic Operator
		Vector2 operator+(float value)
		{
			return Vector2(x + value, y + value);
		}
		Vector2 operator+(Vector2 other)
		{
			return Vector2(x + other.x, y + other.y);
		}
		Vector2 operator-(float value)
		{
			return Vector2(x - value, y - value);
		}
		Vector2 operator-(Vector2 other)
		{
			return Vector2(x - other.x, y - other.y);
		}
		Vector2 operator*(float value)
		{
			return Vector2(x * value, y * value);
		}
		Vector2 operator*(Vector2 v)
		{
			return Vector2(x * v.x, y * v.y);
		}
		Vector2 operator/(float value)
		{
			return Vector2(x / value, y / value);
		}
		Vector2 operator/(Vector2 v)
		{
			return Vector2(x / v.x, y / v.y);
		}

		// Assignment Operator
		void operator+=(float value)
		{
			x += value;
			y += value;
		}
		void operator+=(Vector2 other)
		{
			x += other.x;
			y += other.y;
		}
		void operator-=(float value)
		{
			x -= value;
			y -= value;
		}
		void operator-=(Vector2 other)
		{
			x -= other.x;
			y -= other.y;
		}
		void operator*=(float value)
		{
			x *= value;
			y *= value;
		}
		void operator*=(Vector2 v)
		{
			x *= v.x;
			y *= v.y;
		}
		void operator/=(float value)
		{
			x /= value;
			y /= value;
		}
		void operator/=(Vector2 v)
		{
			x /= v.x;
			y /= v.y;
		}

		// Comparison Operator
		bool operator==(Vector2 v)
		{
			return (x == v.x) && (y == v.y);
		}
		bool operator!=(Vector2 v)
		{
			return (x != v.x) || (y != v.y);
		}

		// Funtions
		void clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		float length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2 abs()
		{
			return Vector2(fabs(x), fabs(y));
		}
		Vector2 integer()
		{
			x = (float)((int)x);
			y = (float)((int)y);

			return *this;
		}
		Vector2 normalize()
		{
			float len = length();
			
			if (len == 0.0f)
				return Vector2::Zero;
			else
			{
				x /= len;
				y /= len;

				return *this;
			}
		}
	};
	struct Vector3
	{
		// Stocks
		static Vector3 One;
		static Vector3 Zero;

		float x;
		float y;
		float z;

		Vector3()
			: x(0.0f)
			, y(0.0f)
			, z(0.0f)
		{
		}
		Vector3(float _x, float _y, float _z)
			: x(_x)
			, y(_y)
			, z(_z)
		{
		}

		// Signed Operator
		Vector3 operator+()
		{
			return Vector3(x, y, z);
		}
		Vector3 operator-()
		{
			return Vector3(-x, -y, -z);
		}

		// Arithmetic Operator
		Vector3 operator+(float value)
		{
			return Vector3(x + value, y + value, z + value);
		}
		Vector3 operator+(Vector3 other)
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}
		Vector3 operator-(float value)
		{
			return Vector3(x - value, y - value, z - value);
		}
		Vector3 operator-(Vector3 other)
		{
			return Vector3(x - other.x, y - other.y, z - other.z);
		}
		Vector3 operator*(float value)
		{
			return Vector3(x * value, y * value, z * value);
		}
		Vector3 operator*(Vector3 v)
		{
			return Vector3(x * v.x, y * v.y, z *v.z);
		}
		Vector3 operator/(float value)
		{
			return Vector3(x / value, y / value, z / value);
		}
		Vector3 operator/(Vector3 v)
		{
			return Vector3(x / v.x, y / v.y, z / v.z);
		}

		// Assignment Operator
		void operator+=(float value)
		{
			x += value;
			y += value;
			z += value;
		}
		void operator+=(Vector3 other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
		}
		void operator-=(float value)
		{
			x -= value;
			y -= value;
			z -= value;
		}
		void operator-=(Vector3 other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
		}
		void operator*=(float value)
		{
			x *= value;
			y *= value;
			z *= value;
		}
		void operator*=(Vector3 v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
		}
		void operator/=(float value)
		{
			x /= value;
			y /= value;
			z /= value;
		}
		void operator/=(Vector3 v)
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;
		}
		
		// Comparison Operator
		bool operator==(Vector3 v)
		{
			return (x == v.x) && (y == v.y) && (z == v.z);
		}
		bool operator!=(Vector3 v)
		{
			return (x != v.x) || (y != v.y) || (z != v.z);
		}

		// Funtions
		void clear()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		float length()
		{
			return sqrtf(x * x + y * y + z * z);
		}

		Vector3 abs()
		{
			return Vector3(fabs(x), fabs(y), fabs(z));
		}
		Vector3 integer()
		{
			x = (float)((int)x);
			y = (float)((int)y);
			z = (float)((int)z);

			return *this;
		}
		Vector3 normalize()
		{
			float len = length();

			if (len == 0.0f)
				return Vector3::Zero;
			else
			{
				x /= len;
				y /= len;
				z /= len;

				return *this;
			}
		}
	};
	
	static Vector2 ConvertWindowCSToFModCS(Vector2 winSize, Vector2 pos)
	{
		return Vector2(
			pos.x / winSize.x * 2 - 1
			, pos.y / winSize.y * 2 - 1
		);
	};
}