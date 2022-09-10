#include "Paddle.h"

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
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
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

bool Paddle::doCollideWithBall(Ball& ball)
{
	if (ball.getVel().y > 0)
	{
		Rect ballRect = ball.GetRect();
		return ballRect.left <= GetRect(0.0f).right && ballRect.top <= GetRect(0.0f).bottom && ballRect.right > GetRect(0.0f).left && ballRect.bottom >= GetRect(0.0f).top;
	}
	return false;
}