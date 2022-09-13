#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Colors.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(const Vec2& in_pos, float in_halfWidth, float in_halfHeight);
	void Update(Keyboard& kbd, float dt);
	void Draw(Graphics& gfx);
	Rect GetRect(float cut);
	void doCollideWithWalls(const Rect& walls);
	bool doCollideWithBall(Ball& ball,float dt);
	void ResetCooldown();
private:
	Color BodyColor = Colors::Gray;
	Color WingColor = Colors::Red;
	float speed = 500.0f;
	float halfWidth;
	float halfHeight;
	Vec2 pos;
	Vec2 vel;
	bool bCooldown = false;;
};
