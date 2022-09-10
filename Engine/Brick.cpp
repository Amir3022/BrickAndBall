#include"Brick.h"

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

bool Brick::doCollideWithBall(Ball& ball)
{
	if (!bDestroyed)
	{
		Rect ballRect = ball.GetRect();
		bDestroyed = ballRect.left <= rect.right && ballRect.top <= rect.bottom && ballRect.right > rect.left && ballRect.bottom >= rect.top;
		return bDestroyed;

	}
	return false;
}