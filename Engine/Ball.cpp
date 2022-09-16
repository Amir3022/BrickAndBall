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
	Rect rect = GetRect();
	if (rect.left <= wall.left)
	{
		pos.x = wall.left + radius;
		ReboundX();
		bCollided = true;
	}
	else if (rect.right >= wall.right)
	{
		pos.x = wall.right - radius;
		ReboundX();
		bCollided = true;
	}

	if (rect.top <= wall.top)
	{
		pos.y = wall.top + radius;
		ReboundY();
		bCollided = true;
	}
	else if(rect.bottom >= wall.bottom)
	{
		pos.y = wall.bottom - radius;
		ReboundY();
		bLost = true;
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

Rect Ball::GetRect() const
{
	return  Rect::FromCenter(pos, radius, radius);
}

Vec2 Ball::getVel()
{
	return vel;
}

void Ball::setVel(const Vec2& in_vel)
{
	vel = in_vel;
}

Vec2 Ball::getPos()
{
	return pos;
}

void Ball::addPos(const Vec2& delta_pos)
{
	pos += delta_pos;
}

void Ball::setPos(const Vec2& in_pos)
{
	pos = in_pos;
}

bool Ball::CheckLossCondition()
{
	return bLost;
}

float Ball::getRadius()
{
	return radius;
}