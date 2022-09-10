#pragma once
#include "Rect.h"
#include "Brick.h"
#include "Graphics.h"
class Ball
{
public:
	Ball() = default;
	Ball(const Vec2& in_pos, const Vec2& in_vel);
	void Draw(Graphics& gfx);
	void Update(float dt);
private:
	Vec2 pos;
	Vec2 vel;
};