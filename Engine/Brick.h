#pragma once
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const Rect& in_rect, Color c);
	void Draw(Graphics& gfx);
	bool doCollideWithBall(Ball& ball);

private:
	float padding = -1.0f;
	Rect rect;
	Color color;
	bool bDestroyed = false;
};