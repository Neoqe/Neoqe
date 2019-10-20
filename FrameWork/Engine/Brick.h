#pragma once

#include "RectF.h"
#include "Colours.h"
#include "Graphics.h"

class Brick
{

public:
	Brick(const RectF& rect_in, Colour colour_in);
	void Draw(Graphics& gfx) const;
private:
	RectF rect;
	Colour colour;
	bool destroyed;
};