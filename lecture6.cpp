#include <iostream>
#include <string>
using namespace std;

// Abstract class. Requires a minimum of 1 pure virtual function
class Shape
{
public:
	// Pure virtual function
	virtual void Draw() const = 0;
};

class Triangle : public Shape
{
public:
	void Draw() const
	{
		cout << "  ^\n";
		cout << "/   \\\n";
		cout << "------\n" << endl;
	}
};

class Circle : public Shape
{
public:
	void Draw() const override
	{
		cout << "()" << endl;
	}
};

class Oval : public Circle
{
public:
	void Draw() const final
	{
		cout << "\n(=)\n" << endl;
	}
};

int main()
{
	Shape* shapes[3] { new Triangle, new Circle, new Oval };
	for (int i = 0; i < 3; i++)
		shapes[i]->Draw();

	return 0;
}

/*
void DrawTriangle()
{
	cout << "  ^\n";
	cout << "/   \\\n";
	cout << "------\n\n";
}
void (*CustomDraw)() = nullptr;
shapes[0]->CustomDraw = DrawTriangle;
shapes[0]->CustomDraw();
*/
