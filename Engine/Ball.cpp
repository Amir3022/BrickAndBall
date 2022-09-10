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

bool Ball::doCollideWithWall(const Rect& wall)
{
	bool bCollided = false;
	Rect rect = Rect::FromCenter(pos, radius, radius);
	if (rect.left <= wall.left)
	{
		pos.x += wall.left - rect.left;
		ReboundX();
		bCollided = true;
	}
	else if (rect.right >= wall.right)
	{
		pos.x += wall.right - rect.right;
		ReboundX();
		bCollided = true;
	}

	if (rect.top <= wall.top)
	{
		pos.y += wall.top - rect.top;
		ReboundY();
		bCollided = true;
	}
	else if(rect.bottom >= wall.bottom)
	{
		pos.y += wall.bottom - rect.bottom;
		ReboundY();
		bCollided = true;
	}
	return bCollided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}
