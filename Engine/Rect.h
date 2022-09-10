#pragma once
#include "Vec2.h"

class Rect
{
public:
	Rect() = default;
	Rect(float in_left, float in_right, float in_top, float in_bottom);
	Rect(const Vec2& topleft, const Vec2& bottomright);
	Rect(const Vec2& topleft, float width, float height);
	static Rect GetRect(const Vec2& center, float halfWidth, float halfHeight);
	Rect Expand(float padding);
public:
	float left;
	float right;
	float top;
	float bottom;
};
