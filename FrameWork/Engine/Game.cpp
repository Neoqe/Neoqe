#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(300.f, 300.0f), Vec2(100.f,100.0f)),
	Walls(0.0f, float(gfx.ScreenWidth),0.0f,float (gfx.ScreenHeight)),
	SoundPad( L"Sounds\\arkpad.wav" )
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
	if (ball.DoWallCollision(Walls))
	{
		SoundPad.Play();
	}
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
}
