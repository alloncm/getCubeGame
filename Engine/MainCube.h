#pragma once
#include"Graphics.h"


class uCube
{
private:
	int x;
	int y;
	Color color;
	int vx;
	int vy;
	int size;
	bool automove_x;
	bool automove_y;
public:
	uCube(int x, int y, Color c ,int size);
	void InBounds();
	void Update(bool up, bool down, bool right, bool left);
	bool Impact(uCube* c);
	void AutomaticMovement();
	void Draw(Graphics& gfx);
	void SetX(int x0);
	void SetY(int y0);
	int GetSize();
	void IncSize();
	void SetVx(int v);
	void SetVy(int v);
	void SetColor(Color c);
	Color GetColor();

	static int constexpr badsize = 6;
	static int constexpr goodsize = 10;
	static int constexpr usersize = 5;
};