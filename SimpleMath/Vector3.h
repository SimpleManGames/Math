#ifndef _VECTOR3_H
#define _VECTOR3_H
#include "Vector2.h"

__declspec(align(32)) struct Vector3
{
	union
	{
		float v[3];
		Vector2 xy;
		Vector2 st;
		struct { float x, y, z; };
		struct { float r, g, b; };
		struct { float s, t, p; };
	};
};

Vector3 operator-(const Vector3 &a);

Vector3 operator+(const Vector3 &a, const Vector3 &b);
Vector3 operator-(const Vector3 &a, const Vector3 &b);
Vector3 operator/(const Vector3 &a, float b);
Vector3 operator*(const Vector3 &a, float b);

Vector3 &operator+=(Vector3 &a, const Vector3 &b);
Vector3 &operator-=(Vector3 &a, const Vector3 &b);
Vector3 &operator/=(Vector3 &a, float b);
Vector3 &operator*=(Vector3 &a, float b);

bool operator> (const Vector3 &a, const Vector3 &b);
bool operator>=(const Vector3 &a, const Vector3 &b);
bool operator< (const Vector3 &a, const Vector3 &b);
bool operator<=(const Vector3 &a, const Vector3 &b);

bool operator==(const Vector3 &a, const Vector3 &b);
bool operator!=(const Vector3 &a, const Vector3 &b);

Vector3 normal(const Vector3 &a);

float magnitude(const Vector3 &a);
float dot(const Vector3 &a, const Vector3 &b);
float distance(const Vector3 &a, const Vector3 &b);

Vector3 cross(const Vector3 &a, const Vector3 &b);

Vector3 min(const Vector3 &a, const Vector3 &b);
Vector3 max(const Vector3 &a, const Vector3 &b);
Vector3 clamp(const Vector3 &a, const Vector3 &a_min, const Vector3 &a_max);

Vector3 mix(const Vector3 &start, const Vector3 &end, float t);
Vector3 lerp(const Vector3 &start, const Vector3 &end, float t);

Vector3 reflect(const Vector3 &incident, const Vector3 &normal);
Vector3 project(const Vector3 &a, const Vector3 &b);

#endif // !_VECTOR3_H