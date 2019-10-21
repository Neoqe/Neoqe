#include "Brick.h"

Brick::Brick(const RectF& rect_in, Colour colour_in)
	:
	rect(rect_in),
	colour(colour_in)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed) 
	{
		gfx.DrawRect(rect, colour);
	}
}

bool Brick::DoBallCosllison(Ball & ball)
{
	if (!destroyed && rect.IsOverlappingWith(ball.GetRect()))
	{
		ball.ReBoundY();
		destroyed = true;
		return true;
	}
	return false;
}
