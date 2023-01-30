#pragma once
struct Vector2
{
	// We want to avoid overloading operators as members since its ugly and error-prone
	//Vector2 operator+(const Vector2& b)
	//{
	//	x += b.x;
	//	y += b.y;
	//	return *this;
	//}

	float x = 0.0f;
	float y = 0.0f;
};

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