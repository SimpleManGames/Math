#ifndef _VECTOR2_H
#define _VECTOR2_H

#include <cmath>

__declspec(align(32)) struct Vector2
{
	union
	{
		float v[2];
		struct { float x, y; };
		struct { float s, t; };
	};
};

Vector2 operator-(const Vector2 &a);

Vector2 operator+(const Vector2 &a, const Vector2 &b);
Vector2 operator-(const Vector2 &a, const Vector2 &b);
Vector2 operator/(const Vector2 &a, const Vector2 &b);
Vector2 operator/(const Vector2 &a, float b);
Vector2 operator*(const Vector2 &a, const Vector2 &b);
Vector2 operator*(const Vector2 &a, float b);

Vector2 &operator+=(Vector2 &a, const Vector2 &b);
Vector2 &operator-=(Vector2 &a, const Vector2 &b);
Vector2 &operator/=(Vector2 &a, float b);
Vector2 &operator*=(Vector2 &a, float b);

bool operator> (const Vector2 &a, const Vector2 &b);
bool operator>=(const Vector2 &a, const Vector2 &b);
bool operator< (const Vector2 &a, const Vector2 &b);
bool operator<=(const Vector2 &a, const Vector2 &b);

bool operator==(const Vector2 &a, const Vector2 &b);
bool operator!=(const Vector2 &a, const Vector2 &b);

Vector2 normal(const Vector2 &a);
Vector2 perp(const Vector2 &a);

float magnitude(const Vector2 &a);
float dot(const Vector2 &a, const Vector2 &b);
float angle(const Vector2 &a);
float distance(const Vector2 &a, const Vector2 &b);

Vector2 min(const Vector2 &a, const Vector2 &b);
Vector2 max(const Vector2 &a, const Vector2 &b);
Vector2 clamp(const Vector2 &a, const Vector2 &a_min, const Vector2 &a_max);

//vec2 mix(const vec2 &u, const vec2 &v, float t) { return vec2{ u.x * t, u.y * t } + vec2{ v.x * (1.f - t), v.y * (1.f - t) }; }
Vector2 lerp(const Vector2 &u, const Vector2 &v, float t);

Vector2 reflect(const Vector2 &v, const Vector2 &a);
Vector2 project(const Vector2 &a, const Vector2 &b);

#endif // !_VEC2_H