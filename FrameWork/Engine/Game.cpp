#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.f, 300.0f), Vec2(100.f, 100.0f)),
	Walls(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)),
	SoundPad(L"Sounds\\arkpad.wav"),
	SoundBrick(L"Sounds\\arkbrick.wav"),
	brick(RectF(450.0f,550.0f,485.0f,515.0f), Colours::Red)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	ball.Update(dt);
	if (brick.DoBallCosllison(ball))
	{
		SoundBrick.Play();
	}

	if (ball.DoWallCollision(Walls))
	{
		SoundPad.Play();
	}

}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	brick.Draw(gfx);
}
