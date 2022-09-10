#include "Rect.h"


Rect::Rect(float in_left, float in_right, float in_top, float in_bottom)
	:
	left(in_left),
	right(in_right),
	top(in_top),
	bottom(in_bottom)
{
}

Rect::Rect(const Vec2& topleft, const Vec2& bottomright)
	:
	Rect(topleft.x, bottomright.x, topleft.y, bottomright.y)
{
}

Rect::Rect(const Vec2& topleft, float width, float height)
	:
	Rect(topleft,topleft+Vec2(width,height))
{
}

Rect Rect::GetRect(const Vec2& center, float halfWidth, float halfHeight)
{
	return Rect(center-Vec2(halfWidth, halfHeight), center + Vec2(halfWidth, halfHeight));
}

Rect Rect::Expand(float padding)
{
	return Rect(left - padding, right + padding, top - padding, bottom + padding);
}