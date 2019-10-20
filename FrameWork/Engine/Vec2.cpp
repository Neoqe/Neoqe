#include "Vec2.h"

Vec2::Vec2(float x_in, float y_in)
	:
	x(x_in),
	y(y_in)
{
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vec2 Vec2::operator*(const Vec2& rhs) const
{
	return Vec2(x * rhs.x, y * rhs.y);
}

Vec2& Vec2::operator*=(const Vec2& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}
