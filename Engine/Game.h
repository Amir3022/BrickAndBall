/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Brick.h"
#include "FrameTimer.h"
#include "Ball.h"
#include "Paddle.h"
#include "Sound.h"
#include "Walls.h"


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	
	/********************************/
	/*  User Variables              */
	static constexpr int nBrickRows = 6;
	static constexpr int nBrickColomns = 16;
	static constexpr int nBricks = nBrickRows * nBrickColomns;
	static constexpr float BrickWidth = 40.0f;
	static constexpr float BrickHeight = 15.0f;
	static constexpr Color backgroundColor = Color(7, 49, 112);
	static constexpr Color shadeColor = Color(5, 35, 75);
	FrameTimer ft;
	Brick Bricks[nBricks];
	Ball ball;
	Paddle paddle;
	Sound soundPad;
	Sound soundBrick;
	Sound soundLose;
	Walls walls;
	bool bGameStarted = false;
	bool losePlayed = false;
	bool bLost = false;
	int lives;
	int score;
	/********************************/
};