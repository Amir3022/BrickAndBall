#pragma once
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Walls
{
public:
	Walls() = default;
	Walls(const Rect& in_rect, int in_thick, Color c);
	void Draw(Graphics& gfx);
	void DrawShade(Graphics& gfx, Color c);
	bool doCollideWithBall(Ball& ball);
	bool checkLose();
	void resetLose();
	Rect getRect();

private: 
	Rect rect;
	int thickness;
	Color color;
	bool bLost = false;
};