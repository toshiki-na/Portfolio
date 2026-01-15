#ifndef VEC3UTILITY_H
#define VEC3UTILITY_H

/*
	3次元ベクトルの定義、計算の処理用
*/

#include <cmath>
#include <DXLib.h>

//3次元ベクトルの定義
struct Vec3
{
public:
	float x{ 0.0f };
	float y{ 0.0f };
	float z{ 0.0f };

	//ベクトルの長さの取得
	inline float Length() const
	{
		float length = sqrtf(x * x + y * y + z * z);
		return length;
	}

	//ベクトルの長さの二乗の取得
	inline float LengthSq()const
	{
		float length_squared = x * x + y * y + z * z;
		return length_squared;
	}

	//ベクトルの正規化
	inline Vec3 Normalized() const
	{
		float length = Length();
		Vec3 result = Zero();

		//0除算防止
		if (length != 0.0f)
		{
			result.x = x / length;
			result.y = y / length;
			result.z = z / length;
		}
		return result;
	}

	inline static Vec3 Zero()
	{
		return Vec3{ 0.0f, 0.0f, 0.0f };
	}

	//DXライブラリVECTORにVec3を変換
	inline DxLib::VECTOR ToDXLibVECTOR() const
	{
		return VGet(x, y, z);
	}

};

//ベクトル同士の加算
inline Vec3 operator+(const Vec3& vec01_, const Vec3& vec02_)
{
	Vec3 result;
	result.x = vec01_.x + vec02_.x;
	result.y = vec01_.y + vec02_.y;
	result.z = vec01_.z + vec02_.z;
	return result;
}

//ベクトル同士の加算代入
inline Vec3& operator+=(Vec3& vec01_, const Vec3& vec02_)
{
	vec01_.x += vec02_.x;
	vec01_.y += vec02_.y;
	vec01_.z += vec02_.z;
	return vec01_;
}

//ベクトル同士の減算
inline Vec3 operator-(const Vec3& vec01_, const Vec3& vec02_)
{
	Vec3 result;
	result.x = vec01_.x - vec02_.x;
	result.y = vec01_.y - vec02_.y;
	result.z = vec01_.z - vec02_.z;
	return result;
}

//ベクトル同士の減算代入
inline Vec3& operator-=(Vec3& vec01_, const Vec3& vec02_)
{
	vec01_.x -= vec02_.x;
	vec01_.y -= vec02_.y;
	vec01_.z -= vec02_.z;
	return vec01_;
}

//ベクトルのスカラー倍
inline Vec3 operator*(const Vec3& vec_, float magnification_)
{
	Vec3 result;
	result.x = vec_.x * magnification_;
	result.y = vec_.y * magnification_;
	result.z = vec_.z * magnification_;
	return result;
}

inline Vec3 operator*(float magnification_, const Vec3& vec_)
{
	Vec3 result;
	result.x = vec_.x * magnification_;
	result.y = vec_.y * magnification_;
	result.z = vec_.z * magnification_;
	return result;
}

//ベクトルのスカラー倍代入
inline Vec3& operator*=(Vec3& vec_, float magnification_)
{
	vec_.x *= magnification_;
	vec_.y *= magnification_;
	vec_.z *= magnification_;
	return vec_;
}

class Vec3Math
{
public:
	//ベクトル同士の内積
	inline static float Dot(const Vec3& vec01_, const Vec3& vec02_)
	{
		float result = vec01_.x * vec02_.x + vec01_.y * vec02_.y + vec01_.z * vec02_.z;
		return result;
	}

	//ベクトル同士の外積ベクトル
	inline static Vec3 Cross(const Vec3& vec01_, const Vec3& vec02_)
	{
		Vec3 result;
		result.x = vec01_.y * vec02_.z - vec01_.z * vec02_.y;
		result.y = vec01_.z * vec02_.x - vec01_.x * vec02_.z;
		result.z = vec01_.x * vec02_.y - vec01_.y * vec02_.x;
		return result;
	}
};
#endif