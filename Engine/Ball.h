#pragma once
#include "Rect.h"
#include "Graphics.h"

class Ball
{
public:
	Ball() = default;
	Ball(const Vec2& in_pos, const Vec2& in_vel);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool doCollideWithWall(const Rect& wall);
	void ReboundX();
	void ReboundY();
	Rect GetRect() const;
	Vec2 getVel();
	Vec2 getPos();
	void addPos(const Vec2& delta_pos);
	void setPos(const Vec2& in_pos);
	bool CheckLossCondition();
	
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
	bool bLost = false;
};