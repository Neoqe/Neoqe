#include "Paddle.h"

Paddle::Paddle(const Vec2& pos_in, float halfwidth_in, float halfHeight_in)
	:
	pos(pos_in),
	halfHeight(halfHeight_in),
	halfWidth(halfwidth_in)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	gfx.DrawRect(GetRect(), colour);
}

bool Paddle::DoBallCollison(Ball& ball) const
{
	if (ball.GetVel().y > 0.0f && GetRect().IsOverlappingWith(ball.GetRect()))
	{
		ball.ReBoundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF& walls)
{
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
	}
}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT) || (kbd.KeyIsPressed('A')))
	{
		pos.x -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_LEFT) || kbd.KeyIsPressed('D'))
	{
		pos.x += speed * dt;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos,halfWidth,halfHeight);
}
