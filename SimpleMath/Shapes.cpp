#include "Shapes.h"

AABB operator*(const Matrix3 & m, const AABB & a) { return AABB{ m.position * a.position, {a.halfextents.x * m.m[0], a.halfextents.y * m.m[5] } }; }
Circle operator*(const Matrix3 & m, const Circle & a) { return Circle{ m.position * a.position, a.r }; }
Ray operator*(const Matrix3 & m, const Ray & a) { return Ray{ m.position * a.position, a.direction }; }
Plane operator*(const Matrix3 & m, const Plane & a) { return Plane{ m.position * a.position, a.normal }; }
ConvexHull operator*(const Matrix3 & m, const ConvexHull & a) {
	for each (Vector2 v in a.verts) { Translate(v) * m; }
	return a;
}