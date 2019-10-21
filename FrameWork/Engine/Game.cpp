#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(300.f, 300.0f), Vec2(100.f,100.0f)),
	Walls(0.0f, float(gfx.ScreenWidth),0.0f,float (gfx.ScreenHeight))
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
	ball.DoWallCollision(Walls);
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
}
