#pragma once
struct Vector2;

Vector2 operator+(const Vector2& a, const Vector2& b);
Vector2 operator-(const Vector2& a, const Vector2& b);
Vector2 operator*(const Vector2& a, const Vector2& b);
Vector2 operator/(const Vector2& a, const Vector2& b);

struct Vector2
{
	Vector2 operator+=(const Vector2& b);
	Vector2 operator-=(const Vector2& b);
	Vector2 operator*=(const Vector2& b);
	Vector2 operator/=(const Vector2& b);

	Vector2 operator%=(const Vector2& b);
	float& operator[](int index);

	float x = 0.0f;
	float y = 0.0f;
};

// We want to avoid overloading operators as members since its ugly and error-prone
//Vector2 operator+(const Vector2& b)
//{
//	x += b.x;
//	y += b.y;
//	return *this;
//}