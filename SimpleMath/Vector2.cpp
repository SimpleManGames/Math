#include "Vector2.h"

Vector2 operator-(const Vector2 & a) { return Vector2{ -a.x, -a.y }; }

Vector2 operator+(const Vector2 &a, const Vector2 &b) { return Vector2{ a.x + b.x, a.y + b.y }; }
Vector2 operator-(const Vector2 &a, const Vector2 &b) { return Vector2{ a.x - b.x, a.y - b.y }; }
Vector2 operator/(const Vector2 &a, const Vector2 &b) { return Vector2{ a.x / b.x, a.y / b.y }; }
Vector2 operator/(const Vector2 &a, float b) { return Vector2{ a.x / b, a.y / b }; }
Vector2 operator*(const Vector2 &a, const Vector2 &b) { return Vector2{ a.x * b.x, a.y * b.y }; }
Vector2 operator*(const Vector2 &a, float b) { return Vector2{ a.x * b, a.y * b }; }

Vector2 &operator+=(Vector2 &a, const Vector2 &b) { return Vector2{ a.x += b.x, a.y += b.y }; }
Vector2 &operator-=(Vector2 &a, const Vector2 &b) { return Vector2{ a.x -= b.x, a.y -= b.y }; }
Vector2 &operator/=(Vector2 &a, float b) { return Vector2{ a.x /= b, a.y /= b }; }
Vector2 &operator*=(Vector2 &a, float b) { return Vector2{ a.x *= b, a.y *= b }; }

bool operator> (const Vector2 &a, const Vector2 &b) { return (a.x > b.x && a.y > b.y) ? true : false; }
bool operator>=(const Vector2 &a, const Vector2 &b) { return (a.x >= b.x && a.y >= b.y) ? true : false; }
bool operator< (const Vector2 &a, const Vector2 &b) { return (a.x < b.x && a.y < b.y) ? true : false; }
bool operator<=(const Vector2 &a, const Vector2 &b) { return (a.x <= b.x && a.y <= b.y) ? true : false; }

bool operator==(const Vector2 &a, const Vector2 &b) { return (a.x == b.x && a.y == b.y) ? true : false; }
bool operator!=(const Vector2 &a, const Vector2 &b) { return (a.x != b.x && a.y != b.y) ? true : false; }

Vector2 normal(const Vector2 &a) { return Vector2{ a.x / a.x, a.y / a.y }; }
Vector2 perp(const Vector2 &a) { return Vector2{ -a.y, a.x }; }

float magnitude(const Vector2 &a) { return (float)sqrt(a.x * a.x + a.y * a.y); }
float dot(const Vector2 &a, const Vector2 &b) { return a.x * b.x + a.y * b.y; }
float angle(const Vector2 &a) { return atan2(a.x, -a.y); }
float distance(const Vector2 &a, const Vector2 &b) { return (float)sqrt(dot(b - a, b - a)); }

Vector2 min(const Vector2 &a, const Vector2 &b) { return (a.x < b.x && a.y < b.y) ? a : b; }
Vector2 max(const Vector2 &a, const Vector2 &b) { return (a.x < b.x && a.y < b.y) ? b : a; }
Vector2 clamp(const Vector2 &a, const Vector2 &a_min, const Vector2 &a_max) { return min(max(a, a_min), a_max); }

//vec2 mix(const vec2 &u, const vec2 &v, float t) { return vec2{ u.x * t, u.y * t } + vec2{ v.x * (1.f - t), v.y * (1.f - t) }; }
Vector2 lerp(const Vector2 &u, const Vector2 &v, float t) { return Vector2{ u.x * t, u.y * t } +Vector2{ v.x * (1.f - t), v.y * (1.f - t) }; }

Vector2 reflect(const Vector2 &v, const Vector2 &a) {
	Vector2 n = normal(a);
	float co = -2 * (dot(v, n) / (magnitude(n) * magnitude(n)));
	Vector2 r = {};
	r.x = v.x + co * n.x;
	r.y = r.y + co * n.y;
	return r;
}
Vector2 project(const Vector2 &a, const Vector2 &b) { return Vector2{ b.x * (a.x * b.x) / (b.x * b.x), b.y * (a.y * b.y) / (b.y * b.y) }; }
