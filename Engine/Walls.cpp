#include "Walls.h"
#include <assert.h>

Walls::Walls(const Rect& in_rect, int in_thick, Color c)
	:
	rect(in_rect),
	thickness(in_thick),
	color(c)
{
}

void Walls::Draw(Graphics& gfx)
{
	int left = int(rect.left) - thickness;
	int right = int(rect.right) + thickness;
	int top = int(rect.top) - thickness;
	int bottom = int(rect.bottom) + thickness;
	assert(left >= 0);
	assert(right < gfx.ScreenWidth);
	assert(top >= 0);
	assert(bottom < gfx.ScreenHeight);
	for (int j = top; j < bottom; j++)
	{
		for (int i = left; i < right; i++)
		{
			if (j >= rect.top && j <= rect.bottom)
			{
				if (i<rect.left || i>rect.right)
				{
					gfx.PutPixel(i, j, color);
				}
			}
			else
			{
				gfx.PutPixel(i, j, color);
			}
		}
	}
}

bool Walls::doCollideWithBall(Ball& ball)
{
	bool bCollided = false;
	Rect ballRect = ball.GetRect();
	if (ballRect.left <= rect.left)
	{
		ball.addPos(Vec2(rect.left - ballRect.left, 0.0f));
		ball.ReboundX();
		bCollided = true;
	}
	else if (ballRect.right >= rect.right)
	{
		ball.addPos(Vec2(rect.right - ballRect.right, 0.0f));
		ball.ReboundX();
		bCollided = true;
	}

	if (ballRect.top <= rect.top)
	{
		ball.addPos(Vec2(0.0f,rect.top - ballRect.top));
		ball.ReboundY();
		bCollided = true;
	}
	else if (ballRect.bottom >= rect.bottom)
	{
		ball.addPos(Vec2(0.0F, rect.bottom - ballRect.bottom));
		ball.ReboundY();
		bLost = true;
		bCollided = true;
	}
	return bCollided;
}

bool Walls::checkLose()
{
	return bLost;
}

void Walls::resetLose()
{
	bLost = false;
}

Rect Walls::getRect()
{
	return rect;
}