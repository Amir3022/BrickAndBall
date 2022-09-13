#pragma once
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"

class Walls
{
public:
	Walls() = default;
	Walls(const Rect& in_rect, int in_thick, Color c);
	void Draw(Graphics& gfx);

private: 
	Rect rect;
	int thickness;
	Color color;
};