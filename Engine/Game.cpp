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
#include<cstdlib>
#include<time.h>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )

{
	cube = new uCube(400, 300, Colors::White, uCube::usersize);
	for (int i = 0; i < badnum; i++)
	{
		bcube[i] = new uCube(uCube::badsize + (rand() % (int)(gfx.ScreenWidth - uCube::badsize)),
			uCube::badsize + (rand() % (int)(gfx.ScreenWidth - uCube::badsize)) ,
			Color(255, 255, 0) ,
			uCube::badsize);
		bcube[i]->SetVx(rand() % (int)(2));
		bcube[i]->SetVy(rand() % (int)(2));
	}
	pcube = new uCube(200, 200, Color(255,0,0),uCube::goodsize);
	pcube->SetVx(0);
	pcube->SetVy(0);
	gameover = false;
	change = false;
	score = 0;
}

void Game::Go()
{
	gfx.BeginFrame();
	if (!gameover)
	{
		UpdateModel();
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//update the location of the user depends on which keys he pressed
	cube->Update(wnd.kbd.KeyIsPressed(VK_UP), wnd.kbd.KeyIsPressed(VK_DOWN), wnd.kbd.KeyIsPressed(VK_RIGHT), wnd.kbd.KeyIsPressed(VK_LEFT));
	cube->UpdateMouse(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
	
	if (UpdateImpact(cube, pcube))
	{
		if (score < 600)
		{
			score += 3;
		}
	}
	//checks for bounds
	cube->InBounds();

	//velocity
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		cube->SetVx(5);
	}
	else
	{
		cube->SetVx(3);
	}
	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		cube->SetVy(5);
	}
	else
	{
		cube->SetVy(3);
	}

	//moving the other cubes
	pcube->AutomaticMovement();
	for (int i = 0; i < badnum; i++)
	{
		bcube[i]->AutomaticMovement();
	}
	
	//game over
	for (int i = 0; i < badnum; i++)
	{
		if (cube->Impact(bcube[i]))
		{
			gameover = true;
		}
	}
	
	
}

bool Game::UpdateImpact(uCube* cube, uCube* pcube)
//checks for impact between two cubes if found changes the location of the later cube
{
	if (cube->Impact(pcube))
	{
		pcube->SetX (pcube->GetSize() + (rand() % (int)(gfx.ScreenWidth - pcube->GetSize())));
		pcube->SetY ( pcube->GetSize() + (rand() % (int)(gfx.ScreenHeight - pcube->GetSize())));
		return true;
	}
	return false;
}

void Game::ComposeFrame()
{
	DrawScore(score);
	cube->Draw(gfx);
	//change colors
	if (!change)
	{
		Color c=Colors::MakeRGB((unsigned char)(pcube->GetColor().GetR()),
			(unsigned char)(pcube->GetColor().GetG()+ 1), 
			(unsigned char)(pcube->GetColor().GetB() + 1));
		pcube->SetColor(c);
		if (pcube->GetColor().GetB() == 255)
		{
			change = !change;
		}
	}
	else if (change)
	{
		Color c = Colors::MakeRGB((unsigned char)(pcube->GetColor().GetR()),
			(unsigned char)(pcube->GetColor().GetG() - 1), 
			(unsigned char)(pcube->GetColor().GetB() - 1));
		pcube->SetColor(c);
		if (pcube->GetColor().GetB() == 0)
		{
			change = !change;
		}
	}

	pcube->Draw(gfx);
	for (int i = 0; i < badnum; i++)
	{
		bcube[i]->Draw(gfx);
	}
	
}

void Game::DrawScore(int s)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < s; j++)
		{
			gfx.PutPixel(25+j,5+i,0, 0, 255);
		}
	}
}








