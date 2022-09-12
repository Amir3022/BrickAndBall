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
		Rect ballRect = ball.GetRect();
		ball.ReboundY();
		bDestroyed = true;
	}
}

const Vec2& Brick::GetCenter()
{
	return rect.GetCenter();
}