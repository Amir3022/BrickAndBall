/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	Walls(Vec2(0.0f,0.0f),Vec2(gfx.ScreenWidth-1,gfx.ScreenHeight-1)),
	ball(Vec2(400.0f,300.0f),Vec2(300.0f,300.0f)),
	paddle(Vec2(400.0f,500.0f),50.0f,15.0f)
{
	Vec2 startPos = Vec2(40.0f, 40.0f);
	Color colors[nBrickRows] = { Colors::Red,Colors::Blue,Colors::Green,Colors::Yellow,Colors::Magenta,Colors::White };
	int c = 0;
	for (int j = 0; j < nBrickRows; j++)
	{
		for (int i = 0; i < nBrickColomns; i++)
		{
			Bricks[i + j * nBrickColomns] = Brick(Rect(startPos + Vec2(i * BrickWidth, j * BrickHeight),BrickWidth,BrickHeight), colors[j]);
			c++;
		}
	}
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
	paddle.Update(wnd.kbd, dt);
	paddle.doCollideWithWalls(Walls);
	for (Brick& brick : Bricks)
	{
		if (brick.doCollideWithBall(ball))
		{
			ball.ReboundY();
			break;
		}
	}
	if(paddle.doCollideWithBall(ball))
	{
		ball.ReboundY();
	}
	if (ball.doCollideWithWall(Walls))
	{

	}
}

void Game::ComposeFrame()
{
	for (Brick& brick : Bricks)
	{
		brick.Draw(gfx);
	}
	ball.Draw(gfx);
	paddle.Draw(gfx);
}
