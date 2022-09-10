#pragma once
#include "Rect.h"
#include "Graphics.h"

class Ball
{
public:
	Ball() = default;
	Ball(const Vec2& in_pos, const Vec2& in_vel);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool doCollideWithWall(const Rect& wall);
	void ReboundX();
	void ReboundY();
	Rect GetRect();
	Vec2 getVel();
	
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};