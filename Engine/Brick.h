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
	bool CheckCollideWithBall(const Ball& ball) const;
	void ExecuteCollideWithBall(Ball& ball,float dt);
	const Vec2& GetCenter();

private:
	float padding = -1.0f;
	Rect rect;
	Color color;
	bool bDestroyed = false;
};