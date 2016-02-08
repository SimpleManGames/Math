#include "Vector3.h"

Vector3 operator-(const Vector3 &a) { return Vector3{ -a.x, -a.y, -a.z }; }

Vector3 operator+(const Vector3 &a, const Vector3 &b) { return Vector3{ a.x + b.x, a.y + b.y, a.z + b.z }; }
Vector3 operator-(const Vector3 &a, const Vector3 &b) { return Vector3{ a.x - b.x, a.y - b.y, a.z - b.z }; }
Vector3 operator/(const Vector3 &a, float b) { return Vector3{ a.x / b, a.y / b, a.z / b }; }
Vector3 operator*(const Vector3 &a, float b) { return Vector3{ a.x * b, a.y * b, a.z * b }; }

Vector3 &operator+=(Vector3 &a, const Vector3 &b) { return Vector3{ a.x += b.x, a.y += b.y, a.z += b.z }; }
Vector3 &operator-=(Vector3 &a, const Vector3 &b) { return Vector3{ a.x -= b.x, a.y -= b.y, a.z -= b.z }; }
Vector3 &operator/=(Vector3 &a, float b) { return Vector3{ a.x /= b, a.y /= b, a.z /= b }; }
Vector3 &operator*=(Vector3 &a, float b) { return Vector3{ a.x *= b, a.y *= b, a.z *= b }; }

bool operator> (const Vector3 &a, const Vector3 &b) { return (a.x > b.x && a.y > b.y && a.z > b.z) ? true : false; }
bool operator>=(const Vector3 &a, const Vector3 &b) { return (a.x >= b.x && a.y >= b.y && a.z >= b.z) ? true : false; }
bool operator< (const Vector3 &a, const Vector3 &b) { return (a.x < b.x && a.y < b.y && a.z < b.z) ? true : false; }
bool operator<=(const Vector3 &a, const Vector3 &b) { return (a.x <= b.x && a.y <= b.y && a.z <= b.z) ? true : false; }

bool operator==(const Vector3 &a, const Vector3 &b) { return (a.x == b.x && a.y == b.y && a.z == b.z) ? true : false; }
bool operator!=(const Vector3 &a, const Vector3 &b) { return (a.x != b.x && a.y != b.y && a.z != b.z) ? true : false; }

Vector3 normal(const Vector3 &a) { return Vector3{ a.x / a.x, a.y / a.y, a.z / a.z }; }

float magnitude(const Vector3 &a) { return (float)sqrt(a.x * a.x + a.y * a.y + a.z * a.z); }
float dot(const Vector3 &a, const Vector3 &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
float distance(const Vector3 &a, const Vector3 &b) { return (float)sqrt(dot(b - a, b - a)); }

Vector3 cross(const Vector3 &a, const Vector3 &b) { return Vector3{ a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.z }; }

Vector3 min(const Vector3 &a, const Vector3 &b) { return (a.x < b.x && a.y < b.y && a.z < b.z) ? a : b; }
Vector3 max(const Vector3 &a, const Vector3 &b) { return (a.x < b.x && a.y < b.y && a.z < b.z) ? b : a; }
Vector3 clamp(const Vector3 &a, const Vector3 &a_min, const Vector3 &a_max) { return min(max(a, a_min), a_max); }

Vector3 mix(const Vector3 &start, const Vector3 &end, float t);
Vector3 lerp(const Vector3 &start, const Vector3 &end, float t);

Vector3 reflect(const Vector3 &incident, const Vector3 &normal);
Vector3 project(const Vector3 &a, const Vector3 &b);