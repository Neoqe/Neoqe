#include "Brick.h"

Brick::Brick(const RectF& rect_in, Colour colour_in)
	:
	rect(rect_in),
	colour(colour_in)
{
}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, colour);
}
