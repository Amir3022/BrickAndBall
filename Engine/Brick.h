#pragma once
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick() = default;
	Brick(const Rect& in_rect, Color c);
	void Draw(Graphics& gfx);

private:
	float padding = -1.0f;
	Rect rect;
	Color color;
	bool bDestroyed = false;
};