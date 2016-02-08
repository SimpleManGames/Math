#include "Matrix3.h"

Matrix3 operator+(const Matrix3 & a, const Matrix3 & b) {
	return Matrix3{ 
		a.m[0] + b.m[0], a.m[1] + b.m[1], a.m[2] + b.m[2],
		a.m[3] + b.m[3], a.m[4] + b.m[4], a.m[5] + b.m[5],
		a.m[6] + b.m[6], a.m[7] + b.m[7], a.m[8] + b.m[8] };
}

Matrix3 operator-(const Matrix3 & a, const Matrix3 & b) {
	return Matrix3{ 
		a.m[0] - b.m[0], a.m[1] - b.m[1], a.m[2] - b.m[2],
		a.m[3] - b.m[3], a.m[4] - b.m[4], a.m[5] - b.m[5],
		a.m[6] - b.m[6], a.m[7] - b.m[7], a.m[8] - b.m[8] };
}

Matrix3 operator*(const Matrix3 & a, const Matrix3 & b) {
	return Matrix3{ 
		a.m[0] * b.m[0], a.m[1] * b.m[1], a.m[2] * b.m[2],
		a.m[3] * b.m[3], a.m[4] * b.m[4], a.m[5] * b.m[5],
		a.m[6] * b.m[6], a.m[7] * b.m[7], a.m[8] * b.m[8] };
}

Matrix3 & operator+=(Matrix3 & a, const Matrix3 & b) {
	return Matrix3{ 
		a.m[0] += b.m[0], a.m[1] += b.m[1], a.m[2] += b.m[2],
		a.m[3] += b.m[3], a.m[4] += b.m[4], a.m[5] += b.m[5],
		a.m[6] += b.m[6], a.m[7] += b.m[7], a.m[8] += b.m[8] };
}

Matrix3 & operator-=(Matrix3 & a, const Matrix3 & b) {
	return Matrix3{ 
		a.m[0] -= b.m[0], a.m[1] -= b.m[1], a.m[2] -= b.m[2],
		a.m[3] -= b.m[3], a.m[4] -= b.m[4], a.m[5] -= b.m[5],
		a.m[6] -= b.m[6], a.m[7] -= b.m[7], a.m[8] -= b.m[8] };
}

Matrix3 & operator*=(Matrix3 & a, const Matrix3 & b) {
	return Matrix3{ 
		a.m[0] *= b.m[0], a.m[1] *= b.m[1], a.m[2] *= b.m[2],
		a.m[3] *= b.m[3], a.m[4] *= b.m[4], a.m[5] *= b.m[5],
		a.m[6] *= b.m[6], a.m[7] *= b.m[7], a.m[8] *= b.m[8] };
}

Matrix3 Transpose(const Matrix3 & a) {
	return Matrix3{ 
		a.m[0], a.m[3], a.m[6],
		a.m[1], a.m[4], a.m[7],
		a.m[2], a.m[5], a.m[8] };
}

Matrix3 Minor(const Matrix3 & a) {
	return Matrix3{ 
		((a.m[4]) * (a.m[8])) - ((a.m[5]) * (a.m[7])), ((a.m[3]) * (a.m[8])) - ((a.m[5]) * (a.m[6])), ((a.m[3]) * (a.m[7])) - ((a.m[4]) * (a.m[6])),
		((a.m[1]) * (a.m[8])) - ((a.m[2]) * (a.m[7])), ((a.m[0]) * (a.m[8])) - ((a.m[2]) * (a.m[6])), ((a.m[0]) * (a.m[7])) - ((a.m[1]) * (a.m[6])),
		((a.m[1]) * (a.m[5])) - ((a.m[2]) * (a.m[4])), ((a.m[0]) * (a.m[5])) - ((a.m[2]) * (a.m[3])), ((a.m[0]) * (a.m[4])) - ((a.m[1]) * (a.m[3])) };
}

Matrix3 rotate(float a) {
	return Matrix3{ 
		cosf(0), -sinf(0),  0,
		sinf(0),  cosf(0),  0,
		0,             0,   1 };
}

Matrix3 Translate(const Vector2 & xy) {
	return Matrix3{ 
		1,  0, xy.x,
		0,  1, xy.y,
		0,  0,    1 };
}

Matrix3 Scale(const Vector2 & xy) {
	return Matrix3{ 
		xy.x, 0, 0,
		0, xy.y, 0,
		0,    0, 1 };
}
