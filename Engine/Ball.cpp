#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& in_pos, const Vec2& in_vel)
	:
	pos(in_pos),
	vel(in_vel)
{
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}