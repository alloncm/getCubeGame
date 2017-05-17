#include "MainCube.h"


uCube::uCube(int x1, int y1, Color c, int s)
//initialize the cube
{
	pos.x = x1;
	pos.y = y1;
	color = c;
	size = s;
	vel.x = vel.y = 1;
	automove_x = false;
	automove_y = false;
}



void uCube::InBounds()
//checks if the cube is in bounds of the screen
{
	if (pos.x < size)
	{
		pos.x = size;
	}
	if (pos.x > Graphics::ScreenWidth - size)
	{
		pos.x = Graphics::ScreenWidth - size;
	}
	if (pos.y < size)
	{
		pos.y = size;
	}
	if (pos.y >  Graphics::ScreenHeight - size)
	{
		pos.y = Graphics::ScreenHeight - size;
	}
}

void uCube::Update(bool up, bool down, bool right, bool left)
//moves the cube depends on the bool values recived
{
	if (up)
	{
		pos.y -= vel.y;
	}
	if (down)
	{
		pos.y += vel.y;
	}
	if (right)
	{
		pos.x += vel.x;
	}
	if (left)
	{
		pos.x -= vel.x;
	}
}

void uCube::UpdateMouse(int posx, int posy)
{
	Vec2 vl (posx - pos.x, posy - pos.y);
	vl = vl.Normalise();
	vel = vl;
	pos += vel;
}

bool uCube::Impact(uCube * c)
//checks for impact with another cube
{
	int a = size + c->size;
	if (pos.x<(c->pos.x + a) && pos.x>(c->pos.x - a) && pos.y<(c->pos.y + a) && pos.y>(c->pos.y - a))
	{
		return true;
	}
	return false;
	
}

void uCube::AutomaticMovement()
//moves the cube automicaly 
{
	
	if (pos.x <= size)
	{
		automove_x = true;
		pos.x = size;
	}
	else if (pos.x >= Graphics::ScreenWidth - size)
	{
		automove_x = false;
		pos.x = Graphics::ScreenWidth - size;
	}
	if (automove_x)
	{
		pos.x += vel.x;
	}
	else
	{
		pos.x -= vel.x;
	}
	
	if (pos.y <= size)
	{
		automove_y = true;
		pos.y = size;
	}
	else if (pos.y >= Graphics::ScreenHeight - size)
	{
		automove_y = false;
		pos.y = Graphics::ScreenHeight - size;
	}
	if (automove_y)
	{
		pos.y += vel.y;
	}
	else
	{
		pos.y -= vel.y;
	}
}

void uCube::Draw(Graphics & gfx)
{
	//draw the cube when the middle is the indecator
	gfx.DrawRect(pos.x - size, pos.y - size, pos.x + size, pos.y + size, color);
}


//gettes and setters
void uCube::SetX(int x0)
{
	pos.x = x0;
}

void uCube::SetY(int y0)
{
	pos.y = y0;
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
	vel.x = v;
}

void uCube::SetVy(int v)
{
	vel.y = v;
}

void uCube::SetColor(Color c)
{
	this->color = c;
}

Color uCube::GetColor()
{
	return this->color;
}
