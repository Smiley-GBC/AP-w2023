#include "Vector2.h"
#include <cstdlib>
#include <cassert>

Vector2 operator+(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

Vector2 operator-(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

Vector2 operator*(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return c;
}

Vector2 operator/(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x / b.x;
	c.y = a.y / b.y;
	return c;
}

Vector2 Vector2::operator+=(const Vector2& b)
{
	x += b.x;
	y += b.y;
	return *this;
}

Vector2 Vector2::operator-=(const Vector2& b)
{
	x -= b.x;
	y -= b.y;
	return *this;
}

Vector2 Vector2::operator*=(const Vector2& b)
{
	x *= b.x;
	y *= b.y;
	return *this;
}

Vector2 Vector2::operator/=(const Vector2& b)
{
	x /= b.x;
	y /= b.y;
	return *this;
}

Vector2 Vector2::operator%=(const Vector2& b)
{
	x = fmodf(x, b.x);
	y = fmodf(y, b.y);
	return *this;
}

float& Vector2::operator[](int index)
{
	assert(index >= 0 && index <= 1);
	return *((float*)this + index);
}
