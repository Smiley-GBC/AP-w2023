/*
#include <iostream>
#include <string>
using namespace std;

void DrawTriangle()
{
	cout << "  ^\n";
	cout << "/   \\\n";
	cout << "------\n\n";
}

void DrawCircle()
{
	cout << "()" << endl;
}

void DrawOval()
{
	cout << "\n(=)\n" << endl;
}

using CShape = void (*)();

//struct CShape
//{
//	void (*CustomDraw)() = nullptr;
//};

// Abstract class. Requires a minimum of 1 pure virtual function
class Shape
{
public:
	// Pure virtual function
	virtual void Draw() const = 0;
	
	// Remember the override and final keywords, they save you from doing unintended static lookip!
	//void Draw() const {}
	
	// We can still have regular virtual methods, but then the base class can be instantiated
	//virtual void Draw() const
	//{
	//	cout << "Shape draw" << endl;
	//}
};

class Triangle : public Shape
{
public:
	void Draw() const override
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

//class ExtraCircle : public Circle
//{
//public:
//	void Draw() const final
//	{
//		cout << "()()" << endl;
//	}
//};

class Oval : public Circle
{
public:
	// Note that we can still derive from classes with final methods, we just can't override them!
	//void Test() {}
	void Draw() const final
	{
		cout << "\n(=)\n" << endl;
	}
};

int main()
{
	// The "Old School" way of doing polymorphism
	CShape triangle = DrawTriangle;
	CShape circle = DrawCircle;
	CShape oval = DrawOval;

	// If we instead store function pointers directly, we can ommit the initial assignment
	//triangle.CustomDraw = DrawTriangle;
	//circle.CustomDraw = DrawCircle;
	//oval.CustomDraw = DrawOval;
	CShape shapes[3]{ triangle, circle, oval };
	for (int i = 0; i < 3; i++)
		shapes[i]();//.CustomDraw();

	//Shape* shapes[3] { new Triangle, new Circle, new Oval };
	//for (int i = 0; i < 3; i++)
	//	shapes[i]->Draw();

	return 0;
}

// Function pointer syntax -- <return type>(*<name>)(<parameters>)
//void RandomFunction(int number)
//{
//
//}
//
//string AnotherRandomFunction(int number)
//{
//	return "";
//}
//
//void (*RandomFunctionPtr)(int) = nullptr;
//string(*RandomFunctionPtr2)(int) = nullptr;
//*/
