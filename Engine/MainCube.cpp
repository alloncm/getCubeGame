#include "MainCube.h"


uCube::uCube(int x1, int y1, Color c, int s)
//initialize the cube
{
	x = x1;
	y = y1;
	color = c;
	size = s;
	vx = vy = 1;
	automove_x = false;
	automove_y = false;
}



void uCube::InBounds()
//checks if the cube is in bounds of the screen
{
	if (x < size)
	{
		x = size;
	}
	if (x > Graphics::ScreenWidth - size)
	{
		x = Graphics::ScreenWidth - size;
	}
	if (y < size)
	{
		y = size;
	}
	if (y >  Graphics::ScreenHeight - size)
	{
		y = Graphics::ScreenHeight - size;
	}
}

void uCube::Update(bool up, bool down, bool right, bool left)
//moves the cube depends on the bool values recived
{
	if (up)
	{
		y -= vy;
	}
	if (down)
	{
		y += vy;
	}
	if (right)
	{
		x += vx;
	}
	if (left)
	{
		x -= vx;
	}
}

bool uCube::Impact(uCube * c)
//checks for impact with another cube
{
	int a = size + c->size;
	if (x<(c->x + a) && x>(c->x - a) && y<(c->y + a) && y>(c->y - a))
	{
		return true;
	}
	return false;
	
}

void uCube::AutomaticMovement()
//moves the cube automicaly 
{
	
	if (x <= size)
	{
		automove_x = true;
		x = size;
	}
	else if (x >= Graphics::ScreenWidth - size)
	{
		automove_x = false;
		x = Graphics::ScreenWidth - size;
	}
	if (automove_x)
	{
		x += vx;
	}
	else
	{
		x -= vx;
	}
	
	if (y <= size)
	{
		automove_y = true;
		y = size;
	}
	else if (y >= Graphics::ScreenHeight - size)
	{
		automove_y = false;
		y = Graphics::ScreenHeight - size;
	}
	if (automove_y)
	{
		y += vy;
	}
	else
	{
		y -= vy;
	}
}

void uCube::Draw(Graphics & gfx)
{
	//draw the cube when the middle is the indecator
	gfx.DrawRect(x - size, y - size, x + size, y + size, color);
}


//gettes and setters
void uCube::SetX(int x0)
{
	x = x0;
}

void uCube::SetY(int y0)
{
	y = y0;
}

int uCube::GetSize()
{
	return size;
}

void uCube::IncSize()
{
	size++;
}

void uCube::SetVx(int v)
{
	vx = v;
}

void uCube::SetVy(int v)
{
	vy = v;
}

void uCube::SetColor(Color c)
{
	this->color = c;
}

Color uCube::GetColor()
{
	return this->color;
}
