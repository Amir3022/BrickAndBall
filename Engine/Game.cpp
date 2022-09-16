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
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(700.0f, 200.0f), Vec2(0.0f, 0.0f)),
	paddle(Vec2(400.0f, 500.0f), 50.0f, 10.0f),
	soundBrick(L"Sounds\\arkbrick.wav"),
	soundPad(L"Sounds\\arkpad.wav"),
	soundLose(L"Sounds\\lose4.wav"),
	walls(Rect(Vec2(20.0, 20.0f), Vec2(779.0f, 579.0f)), 20, Color(50, 50, 50)),
	lives(2),
	score(0)
{
	Vec2 startPos = Vec2(80.0f, 40.0f);
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
	if (bGameStarted)
	{
		if (!bLost)
		{
			const float dt = ft.Mark();
			ball.Update(dt);
			paddle.Update(wnd.kbd, dt);
			paddle.doCollideWithWalls(walls.getRect());
			float curDistanceSq;
			int index;
			bool collisionHappened = false;
			for (int i = 0; i < nBricks; i++)
			{
				if (Bricks[i].CheckCollideWithBall(ball))
				{
					float newDistanceSq = (ball.getPos() - Bricks[i].GetCenter()).GetLengthSq();
					if (collisionHappened)
					{
						if (newDistanceSq < curDistanceSq)
						{
							curDistanceSq = newDistanceSq;
							index = i;
						}
					}
					else
					{
						curDistanceSq = newDistanceSq;
						index = i;
						collisionHappened = true;
					}
				}
			}
			if (collisionHappened)
			{
				Bricks[index].ExecuteCollideWithBall(ball, dt);
				paddle.ResetCooldown();
				soundBrick.Play();
				score += 5;
			}
			if (paddle.doCollideWithBall(ball, dt))
			{
				soundPad.Play();
			}
			if (walls.doCollideWithBall(ball))
			{
				paddle.ResetCooldown();
				bLost = walls.checkLose();
				if (bLost)
				{
					soundLose.Play();
					lives--;
				}
			}
		}
		else
		{
			if (wnd.kbd.KeyIsPressed(VK_RETURN) && lives>=0)
			{
				ft.Mark();
				bLost = false;
				paddle.setPos(Vec2(400.0f, 500.0f));
				ball.setPos(Vec2(700.0f,200.0f));
				ball.setVel(Vec2(1.0f, 1.0f).Normalize() * 450.0f);
				walls.resetLose();
			}
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			ft.Mark();
			bGameStarted = true;
			ball.setVel(Vec2(1.0f, 1.0f).Normalize() * 450.0f);
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE))
	{
		exit(0);
	}
}

void Game::ComposeFrame()
{
	for (int j = 0; j < gfx.ScreenHeight; j++)
	{
		for (int i = 0; i < gfx.ScreenWidth; i++)
		{
			gfx.PutPixel(i, j, Color(12, 87, 199));
		}
	}
	if (bGameStarted)
	{
		for (Brick& brick : Bricks)
		{
			brick.Draw(gfx);
		}
		paddle.Draw(gfx);
		ball.Draw(gfx);
		walls.Draw(gfx);
		if (bLost)
		{
			SpriteCodex::DrawGameOver(350, 250, gfx);
		}
	}
}
