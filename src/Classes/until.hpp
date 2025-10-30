#pragma once
#include <raylib.h>
#include "cmath"

static void GetRotatedRectPoints(Rectangle rect, float rotation, Vector2 out[4]);

static void ProjectOntoAxis(Vector2 axis, const Vector2 points[4], float &min, float &max);

bool CheckCollisionRecsRotated(Rectangle rect1, float rot1, Rectangle rect2, float rot2);