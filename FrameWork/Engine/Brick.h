#pragma once

#include "RectF.h"
#include "Colours.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{

public:
	Brick(const RectF& rect_in, Colour colour_in);
	void Draw(Graphics& gfx) const;
	bool DoBallCosllison(Ball & ball);
private:
	RectF rect;
	Colour colour;
	bool destroyed = false;
};