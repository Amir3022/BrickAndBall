#include"Brick.h"
#include <assert.h>

Brick::Brick(const Rect& in_rect, Color c)
	:
	rect(in_rect),
	color(c)
{
}

void Brick::Draw(Graphics& gfx)
{
	if (!bDestroyed)
	{
		gfx.DrawRect(rect.Expand(padding), color);
	}
}

bool Brick::CheckCollideWithBall(const Ball& ball) const
{
	return ball.GetRect().IsOverlappigWith(rect);
}

void Brick::ExecuteCollideWithBall(Ball& ball, float dt)
{
	assert(ball.GetRect().IsOverlappigWith(rect));
	if (!bDestroyed)
	{
		Vec2 ballVel = ball.getVel();
		Rect ballRect = ball.GetRect();
		if (rect.right - ballRect.left <= -ballVel.x * dt)
		{
			ball.addPos(Vec2(ballVel.x * dt, 0.0f));
			ball.ReboundX();
		}
		else if (ballRect.right - rect.left <= ballVel.x * dt)
		{
			ball.addPos(Vec2( -ballVel.x * dt, 0.0f));
			ball.ReboundX();
		}
		if (ballRect.bottom - rect.top <= ballVel.y * dt)
		{
			ball.addPos(Vec2(0.0f, -ballVel.y * dt));
			ball.ReboundY();
		}
		else if (ballRect.top - rect.bottom >= ballVel.y * dt)
		{
			ball.addPos(Vec2(0.0f, ballVel.y * dt));
			ball.ReboundY();
		}
		bDestroyed = true;
	}
}

Vec2 Brick::GetCenter()
{
	return rect.GetCenter();
}