#pragma once

#include "Ball.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colours.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(const Vec2& pos_in, float halfwidth_in, float halfHeight_in);
	void Draw(Graphics& gfx) const;
	bool DoBallCollison(Ball& ball) const;
	void DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
private:
	float speed = 300.0f;
	Colour colour = Colours::White;
	float halfWidth;
	float halfHeight;
	Vec2 pos;
};