#include "Paddle.h"
#include <cmath>

Paddle::Paddle(const Vec2& in_pos, float in_halfWidth, float in_halfHeight)
	:
	pos(in_pos),
	halfWidth(in_halfWidth),
	halfHeight(in_halfHeight)
{
}

void Paddle::Update(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
		vel = Vec2(-speed, 0.0f);
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
		vel = Vec2(speed, 0.0f);
	}
	else
	{
		vel = Vec2(0.0f, 0.0f);
	}
}

void Paddle::Draw(Graphics& gfx)
{
	Rect WingRect = GetRect(0.0f);
	Rect BodyRect = GetRect(20.0f);
	gfx.DrawRect(WingRect, WingColor);
	gfx.DrawRect(BodyRect, BodyColor);
}

Rect Paddle::GetRect(float cut)
{
	return Rect::FromCenter(pos, halfWidth - cut, halfHeight);
}

void Paddle::doCollideWithWalls(const Rect& walls)
{
	Rect rect = GetRect(0.0f);
	if (rect.left <= walls.left)
	{
		pos.x = walls.left + halfWidth;
	}
	else if (rect.right >= walls.right)
	{
		pos.x = walls.right - halfWidth;
	}
}

bool Paddle::doCollideWithBall(Ball& ball,float dt)
{
	if (!bCooldown)
	{
		Vec2 ballVel = ball.getVel();
		Rect ballRect = ball.GetRect();
		if (ballRect.IsOverlappigWith(GetRect(0.0f)))
		{
			if (GetRect(0.0f).right - ballRect.left <= (-ballVel.x + vel.x) * dt)
			{
				ball.addPos(Vec2(-(-ballVel.x + vel.x) * dt, 0.0f));
				ball.ReboundX();
			}
			else if (ballRect.right - GetRect(0.0f).left <= (ballVel.x - vel.x) * dt)
			{
				ball.addPos(Vec2(-(ballVel.x - vel.x) * dt, 0.0f));
				ball.ReboundX();
			}
			if (ballRect.bottom - GetRect(0.0f).top <= ballVel.y * dt)
			{
				ball.addPos(Vec2(0.0f, -ballVel.y * dt));
				//ball.ReboundY();
				Vec2 UnitDirection = (ball.getPos() - pos).GetNormalized();
				ball.setVel(UnitDirection * 450.0f);
				if (std::signbit(ballVel.x) != std::signbit(UnitDirection.x))
				{
					ball.ReboundX();
				}
			}
			else if (ballRect.top - GetRect(0.0f).bottom >= ballVel.y * dt)
			{
				ball.addPos(Vec2(0.0f, ballVel.y * dt));
				ball.ReboundY();
			}
			bCooldown = true;
			return true;
		}
	}
	return false;
}

void Paddle::ResetCooldown()
{
	bCooldown = false;
}

void Paddle::setPos(const Vec2& in_pos)
{
	pos = in_pos;
}