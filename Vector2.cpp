#include "Vector2.h"
#include <cstdlib>
#include <cassert>

Vector2 Add(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

Vector2 Sub(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

Vector2 Mul(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return c;
}

Vector2 Div(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x / b.x;
	c.y = a.y / b.y;
	return c;
}

Vector2 Mod(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = fmodf(a.x, b.x);
	c.y = fmodf(a.y, b.y);
	return c;
}

std::istream& Input(std::istream& in, Vector2& vec)
{
	in >> vec.x;
	in >> vec.y;
	return in;
}

std::ostream& Output(std::ostream& out, const Vector2& vec)
{
	out << "x: " << vec.x << " y: " << vec.y << std::endl;
	return out;
}

bool Equals(const Vector2& a, const Vector2& b)
{
	return a.x == b.x && a.y == b.y;
}

Vector2 operator+(const Vector2& a, const Vector2& b)
{
	return Add(a, b);
}

Vector2 operator-(const Vector2& a, const Vector2& b)
{
	return Sub(a, b);
}

Vector2 operator*(const Vector2& a, const Vector2& b)
{
	return Mul(a, b);
}

Vector2 operator/(const Vector2& a, const Vector2& b)
{
	return Div(a, b);
}

Vector2 operator%(const Vector2& a, const Vector2& b)
{
	return Mod(a, b);
}

std::istream& operator>>(std::istream& in, Vector2& vec)
{
	return Input(in, vec);
}

std::ostream& operator<<(std::ostream& out, const Vector2& vec)
{
	return Output(out, vec);
}

bool operator==(const Vector2& a, const Vector2& b)
{
	return Equals(a, b);
}

bool operator!=(const Vector2& a, const Vector2& b)
{
	return !Equals(a, b);
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

Vector2 Vector2::operator++()
{
	x++;
	y++;
	return *this;
}

Vector2 Vector2::operator++(int)
{
	Vector2 copy = *this;
	x++;
	y++;
	return copy;
}

Vector2 Vector2::operator--()
{
	x--;
	y--;
	return *this;
}

Vector2 Vector2::operator--(int)
{
	Vector2 copy = *this;
	x--;
	y--;
	return copy;
}
