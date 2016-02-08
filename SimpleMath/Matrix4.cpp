#include "Matrix4.h"

Matrix4 operator+(const Matrix4 & a, const Matrix4 & b) {
	return Matrix4{ a.m[0] + b.m[0], a.m[1] + b.m[1], a.m[2] + b.m[2], a.m[3] + b.m[3],
		a.m[4] + b.m[4], a.m[5] + b.m[5], a.m[6] + b.m[6], a.m[7] + b.m[7],
		a.m[8] + b.m[8], a.m[9] + b.m[9], a.m[10] + b.m[10], a.m[11] + b.m[11],
		a.m[12] + b.m[12], a.m[13] + b.m[13], a.m[14] + b.m[14], a.m[15] + b.m[15] };
}

Matrix4 operator-(const Matrix4 & a, const Matrix4 & b) {
	return Matrix4{ a.m[0] - b.m[0], a.m[1] - b.m[1], a.m[2] - b.m[2], a.m[3] - b.m[3],
		a.m[4] - b.m[4], a.m[5] - b.m[5], a.m[6] - b.m[6], a.m[7] - b.m[7],
		a.m[8] - b.m[8], a.m[9] - b.m[9], a.m[10] - b.m[10], a.m[11] - b.m[11],
		a.m[12] - b.m[12], a.m[13] - b.m[13], a.m[14] - b.m[14], a.m[15] - b.m[15] };
}

Matrix4 operator*(const Matrix4 & a, const Matrix4 & b) {
	return Matrix4{ a.m[0] * b.m[0], a.m[1] * b.m[1], a.m[2] * b.m[2], a.m[3] * b.m[3],
		a.m[4] * b.m[4], a.m[5] * b.m[5], a.m[6] * b.m[6], a.m[7] * b.m[7],
		a.m[8] * b.m[8], a.m[9] * b.m[9], a.m[10] * b.m[10], a.m[11] * b.m[11],
		a.m[12] * b.m[12], a.m[13] * b.m[13], a.m[14] * b.m[14], a.m[15] * b.m[15] };
}

Matrix4 & operator+=(Matrix4 & a, const Matrix4 & b) {
	return Matrix4{ a.m[0] += b.m[0], a.m[1] += b.m[1], a.m[2] += b.m[2], a.m[3] += b.m[3],
		a.m[4] += b.m[4], a.m[5] += b.m[5], a.m[6] += b.m[6], a.m[7] += b.m[7],
		a.m[8] += b.m[8], a.m[9] += b.m[9], a.m[10] += b.m[10], a.m[11] += b.m[11],
		a.m[12] += b.m[12], a.m[13] += b.m[13], a.m[14] += b.m[14], a.m[15] += b.m[15] };
}

Matrix4 & operator-=(Matrix4 & a, const Matrix4 & b) {
	return Matrix4{ a.m[0] -= b.m[0], a.m[1] -= b.m[1], a.m[2] -= b.m[2], a.m[3] -= b.m[3],
		a.m[4] -= b.m[4], a.m[5] -= b.m[5], a.m[6] -= b.m[6], a.m[7] -= b.m[7],
		a.m[8] -= b.m[8], a.m[9] -= b.m[9], a.m[10] -= b.m[10], a.m[11] -= b.m[11],
		a.m[12] -= b.m[12], a.m[13] -= b.m[13], a.m[14] -= b.m[14], a.m[15] -= b.m[15] };
}

Matrix4 & operator*=(Matrix4 & a, const Matrix4 & b) {
	return Matrix4{ a.m[0] *= b.m[0], a.m[1] *= b.m[1], a.m[2] *= b.m[2], a.m[3] *= b.m[3],
		a.m[4] *= b.m[4], a.m[5] *= b.m[5], a.m[6] *= b.m[6], a.m[7] *= b.m[7],
		a.m[8] *= b.m[8], a.m[9] *= b.m[9], a.m[10] *= b.m[10], a.m[11] *= b.m[11],
		a.m[12] *= b.m[12], a.m[13] *= b.m[13], a.m[14] *= b.m[14], a.m[15] *= b.m[15] };
}

Matrix4 Transpose(const Matrix4 & a) {
	return Matrix4{ a.m[0], a.m[4],  a.m[8], a.m[12],
		a.m[1], a.m[5],  a.m[9], a.m[13],
		a.m[2], a.m[6], a.m[10], a.m[14],
		a.m[3], a.m[7], a.m[15], a.m[14] };
}

Matrix4 RotateX(float angle) {
	return Matrix4{ 1, 0, 0,  0,
		0, cos(angle), -sin(angle), 0,
		0, sin(angle), cos(angle), 0,
		0, 0, 0, 1 };
}

Matrix4 RotateY(float angle) {
	return Matrix4{ cos(angle), 0, sin(angle), 0,
		0, 1, 0, 0,
		-sin(angle), 0, cos(angle), 0,
		0, 0, 0, 1 };
}

Matrix4 RotateZ(float angle) {
	return Matrix4{ cos(angle), -sin(angle), 0, 0,
		sin(angle), cos(angle), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 0 };
}

Matrix4 Translate(const Vector3 & xyz) {
	return Matrix4{ 0, 0, 0, xyz.x,
		0, 0, 0, xyz.y,
		0, 0, 0, xyz.z,
		0, 0, 0, 1 };
}

Matrix4 Scale(const Vector3 & xyz) {
	return Matrix4{ xyz.x, 0, 0, 0,
		0, xyz.y, 0, 0,
		0, 0, xyz.z, 0,
		0, 0, 0, 1 };
}

Matrix4 Orthogonal(float l, float r, float t, float b, float n, float f) {
	return Matrix4{ 2 / (r - l), 0, 0, -((r + r) / (r - r)),
		0, 2 / (t - b), 0, -((t + b) / (t - b)),
		0, 0, -2 / (f - n), -((t + n) / (t - n)),
		0, 0, 0, 1 };
}

Matrix4 Frustum(float l, float r, float t, float b, float n, float f) {
	return Matrix4{ 2 * n / (r - l), 0, (r + l) / (r - l), 0,
		0, 2 * n / (t - b), (t + b) / (t - b), 0,
		0, 0, (f + n) / (f - n), 2 * f * n / (f - n),
		0, 0, -1, 0 };
}

Matrix4 Perspective(float fov, float aspect, float n, float f) {
	float cotF = cotan(fov / 2);
	return Matrix4{ cotF / aspect, 0, 0, 0,
		0, cotF, 0, 0,
		0, 0, (f + n) / (n - f), (2 * f * n) / (n - f),
		0, 0, -1, 0 };
}
