#include "Vec2.h"

using namespace std;

Vec2::Vec2()
{
	x = 0.0;
	y = 0.0;
}

Vec2::Vec2(float x1, float y1)
{
	x = x1;
	y = y1;
}

Vec2 Vec2::operator+(const Vec2 & v) const
{
	Vec2 d(x + v.x, y + v.y);
	return d;
}

Vec2 Vec2::operator-(const Vec2 & v)const
{
	return Vec2(x - v.x, y - v.y);
}

Vec2 & Vec2::operator+=(const Vec2 & v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vec2 & Vec2::operator-=(const Vec2 & v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Vec2 Vec2::operator*(const int p) const
{
	return Vec2(x*p, y*p);
}

Vec2 Vec2::operator/(const int p) const
{
	return Vec2(x / p, y / p);
}

float Vec2::GetLength()
{
	return sqrt(x*x + y*y);
}

Vec2 Vec2::Normalise()
{
	float len = GetLength();
	if (len != 0)
	{
		return (*this) / len;
	}
	return Vec2(0, 0);
}


