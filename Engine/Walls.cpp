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
	int left = rect.left - thickness;
	int right = rect.right + thickness;
	int top = rect.top - thickness;
	int bottom = rect.bottom + thickness;
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