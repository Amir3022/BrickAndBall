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

void Brick::DrawShade(Graphics& gfx, Color c)
{
	if (!bDestroyed)
	{
		Rect temp = rect.Expand(padding);
		float shadeLength = (temp.bottom - temp.top) / 2.0f;
		int inc = 0;
		for (int j=int(temp.bottom);j<(temp.bottom+ shadeLength);j++)
		{
			for (int i = int(temp.left); i < (temp.right);i++)
			{
				gfx.PutPixel(i + inc, j, c);
			}
			inc++;
		}
		inc = 1;
		for (int j = int(temp.top); j < temp.bottom + shadeLength; j++)
		{
			for (int i = int(temp.right); i < temp.right + shadeLength; i++)
			{
				if (i <= temp.right+inc)
				{
					gfx.PutPixel(i, j, c);
				}
			}
			if (inc < shadeLength)
			{
				inc++;
			}
		}
	}
}

bool Brick::CheckCollideWithBall(const Ball& ball) const
{
	if (!bDestroyed)
	{
		return ball.GetRect().IsOverlappigWith(rect);
	}
	return false;
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
			//ball.addPos(Vec2(ballVel.x * dt, 0.0f));
			ball.ReboundX();
		}
		else if (ballRect.right - rect.left <= ballVel.x * dt)
		{
			//ball.addPos(Vec2( -ballVel.x * dt, 0.0f));
			ball.ReboundX();
		}
		if (ballRect.bottom - rect.top <= ballVel.y * dt)
		{
			//ball.addPos(Vec2(0.0f, -ballVel.y * dt));
			ball.ReboundY();
		}
		else if (ballRect.top - rect.bottom >= ballVel.y * dt)
		{
			//ball.addPos(Vec2(0.0f, ballVel.y * dt));
			ball.ReboundY();
		}
		bDestroyed = true;
	}
}

Vec2 Brick::GetCenter()
{
	return rect.GetCenter();
}