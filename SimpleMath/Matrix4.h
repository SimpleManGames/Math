#ifndef _MATRIX4_H
#define _MATRIX4_H

#include "Vector4.h"
#include "Matrix3.h"
/*
Example memory layouts and data structure designs for math types.

They make heavy use of 'untagged' unions and structures to avoid
the potentially nebulous performance costs, implementation details,
and duplicity of operator overloading.

Esmeralda Salamone, esmes@aie.edu.au, 1/25/2016

For instructional use.
*/

double cotan(double i) { return(1 / tan(i)); }

__declspec(align(32)) struct Matrix4
{
	union
	{
		float m[16];
		vec4  c[4];
		float mm[4][4];
		struct
		{
			union { vec4 c1; Vector3 right; };
			union { vec4 c2; Vector3 up; };
			union { vec4 c3; Vector3 forward; };
			union { vec4 c4; Vector3 position; };
		};
	};
	static constexpr Matrix4 identity() {
		return Matrix4{ 1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1 };
	}
};

Matrix4 operator+(const Matrix4 &a, const Matrix4 &b);
Matrix4 operator-(const Matrix4 &a, const Matrix4 &b);
Matrix4 operator*(const Matrix4 &a, const Matrix4 &b);

Matrix4 &operator+=(Matrix4 &a, const Matrix4 &b);
Matrix4 &operator-=(Matrix4 &a, const Matrix4 &b);
Matrix4 &operator*=(Matrix4 &a, const Matrix4 &b);

Matrix4 Transpose(const Matrix4 &a);
Matrix4 Inverse(const Matrix4 &a); //aka, the terror

Matrix4 RotateX(float angle);
Matrix4 RotateY(float angle);
Matrix4 RotateZ(float angle);
Matrix4 Translate(const Vector3 &xyz);
Matrix4 Scale(const Vector3 &xyz);

Matrix4 Orthogonal(float l, float r, float t, float b, float n, float f);
Matrix4 Frustum(float l, float r, float t, float b, float n, float f);
Matrix4 Perspective(float fov, float aspect, float n, float f); // assert n > 0 && f > n
Matrix4 lookAt(const Vector3 &eye, const Vector3 &target, const Vector3 &up);

#endif // !_MAT4_H