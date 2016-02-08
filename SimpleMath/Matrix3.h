#ifndef _MAT3_H
#define _MAT3_H

#include "Vector3.h"

__declspec(align(32)) struct Matrix3
{
	union
	{
		Vector3 c[3];
		float m[9];
		float mm[3][3];
		struct
		{
			union { Vector3 c1; Vector2 right; };
			union { Vector3 c2; Vector2 up; };
			union { Vector3 c3; Vector2 position; };
		};
	};

	static constexpr Matrix3 identity() {
		return Matrix3{ 1, 0, 0,
			0, 1, 0,
			0, 0, 1 };
	}
};

Matrix3 operator+(const Matrix3 &a, const Matrix3 &b);
Matrix3 operator-(const Matrix3 &a, const Matrix3 &b);
Matrix3 operator*(const Matrix3 &a, const Matrix3 &b);

Matrix3 &operator+=(Matrix3 &a, const Matrix3 &b);
Matrix3 &operator-=(Matrix3 &a, const Matrix3 &b);
Matrix3 &operator*=(Matrix3 &a, const Matrix3 &b);

Matrix3 Transpose(const Matrix3 &a);
//Matrix3 Inverse(const Matrix3 &a) {
//	return Matrix3{};
//}

Matrix3 Minor(const Matrix3 &a);

Matrix3 rotate(float a);
Matrix3 Translate(const Vector2 &xy);
Matrix3 Scale(const Vector2 &xy);

#endif // !_MAT3_H
