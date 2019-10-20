#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
{
	left = left_in;
	right = right_in;
	bottom = bottom_in;
	top = top_in;
}

RectF::RectF(const Vec2& topleft, const Vec2& bottomright)
	:
	RectF ( topleft.x, bottomright.x, topleft.y, bottomright.y)
{
}

RectF::RectF(const Vec2& topleft, float width, float height)
	:
	RectF ( topleft, topleft + Vec2(width,height))
{
}

bool RectF::IsOverlappingWith(const RectF& other) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}
