#pragma once
#include <iostream>
struct Vector2;

Vector2 Add(const Vector2& a, const Vector2& b);
Vector2 Sub(const Vector2& a, const Vector2& b);
Vector2 Mul(const Vector2& a, const Vector2& b);
Vector2 Div(const Vector2& a, const Vector2& b);
Vector2 Mod(const Vector2& a, const Vector2& b);
std::istream& Input(std::istream& in, Vector2& vec);
std::ostream& Output(std::ostream& out, const Vector2& vec);
bool Equals(const Vector2& a, const Vector2& b);

// what if (1, 2) vs (2, 1) -- is it greater?? less?? We don't know, so don't overload!!!
//bool Less(const Vector2& a, const Vector2& b);
//bool Greater(const Vector2& a, const Vector2& b);

Vector2 operator+(const Vector2& a, const Vector2& b);
Vector2 operator-(const Vector2& a, const Vector2& b);
Vector2 operator*(const Vector2& a, const Vector2& b);
Vector2 operator/(const Vector2& a, const Vector2& b);
Vector2 operator%(const Vector2& a, const Vector2& b);
std::istream& operator>>(std::istream& in, Vector2& vec);
std::ostream& operator<<(std::ostream& out, const Vector2& vec);
bool operator==(const Vector2& a, const Vector2& b);
bool operator!=(const Vector2& a, const Vector2& b);

struct Vector2
{
	Vector2 operator+=(const Vector2& b);
	Vector2 operator-=(const Vector2& b);
	Vector2 operator*=(const Vector2& b);
	Vector2 operator/=(const Vector2& b);

	Vector2 operator%=(const Vector2& b);
	float& operator[](int index);

	Vector2 operator++();
	Vector2 operator++(int);
	Vector2 operator--();
	Vector2 operator--(int);

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