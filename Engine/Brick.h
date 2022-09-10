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
	Rect rect;
	Color color;
	bool bDestroyed = false;
};