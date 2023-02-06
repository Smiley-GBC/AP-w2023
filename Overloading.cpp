#include <iostream>
using namespace std;

struct vec2
{
	float x = 0.0f;
	float y = 0.0f;
};

vec2 Add(vec2 a, vec2 b)
{
	return { a.x + a.x, b.x + b.x };
}

vec2 operator+(vec2 a, vec2 b)
{
	//cout << "WHOOOOOOOOOOOO" << endl;
	//cout << "WHOOOOOOOOOOOO" << endl;
	//cout << "WHOOOOOOOOOOOO" << endl;
	//cout << "WHOOOOOOOOOOOO" << endl;
	//return Add(a, b);
	// Operator overloads are *literally* just functions, but their names are math symbols!
	return { a.x + a.x, b.x + b.x };
}

ostream& operator<<(ostream& out, const vec2& vec)
{
	out << "x: " << vec.x << " y: " << vec.y << endl;
	return out;
}

int main()
{
	// We can do math operations on build-in ("Native" or "Primitive" types)
	float x1 = 1.0f;
	float x2 = 1.0f;
	float x3 = x2 + x1;
	cout << x3 << endl;

	//string name;
	//cout << name;

	// We cannot do math operations on user-defined types (objects)
	vec2 a{ 1.0f, 1.0f };
	vec2 b{ 1.0f, 1.0f };
	//vec2 c = Add(b, a);
	vec2 c = b + a;
	cout << c << endl;

	return 0;
}