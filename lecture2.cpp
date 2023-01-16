#include <iostream>

using namespace std;

void Function()
{
	printf("I am a function\n");
}

void Function(int number)
{
	printf("I am a function with a value of %i\n", number);
}

class Circle
{
public:
	Circle()
	{
		printf("Default circle created!\n");
	}

	Circle(float r)
	{
		radius = r;
		printf("Custom circle create with radius %f\n", r);
	}

	~Circle()
	{
		printf("Circle destroyed!\n");
	}

private:
	float radius;
};

// Example of when we could use private methods (SetArea() doesn't need to be available outside of Rectangle)
class Rectangle
{
public:
	int Area()
	{
		return a;
	}

	void SetLength(int length)
	{
		l = length;
		SetArea();
	}

	void SetWidth(int width)
	{
		w = width;
		SetArea();
	}

	int GetLength() const
	{
		return l;
	}

	int GetWidth() const
	{
		return w;
	}

private:
	int l, w, a;

	void SetArea()
	{
		a = l * w;
	}
};

void DisplayRectangle(Rectangle& r)
{
	cout << r.GetLength() << endl;
	cout << r.GetWidth() << endl;
}

Rectangle ModifyRectangle(Rectangle r)
{
	Rectangle newRectangle;
	newRectangle.SetWidth(r.GetLength());
	return newRectangle;
}

void IncrementByValue(int n)
{
	n++;
}

void IncrementByReference(int& n)
{
	n++;
}

//void Test(int* a, int& b)
//{
//	//*(a++);	// This increments the addess of a, and then dereferences it (not what we want)
//	(*a)++;		// This dereferences the value pointed to by a and then increments it (what we want)
//	b++;
//}

void ReferenceTest(int& n)
{
	printf("%i\n", n);
}

class Test
{
public:
	Test()
	{
		data = new int[1000];
	}

	~Test()
	{
		delete[] data;
	}

	int number;

private:
	int* data;
};

int main()
{
	Test* t = new Test;
	t->number;

	int number;
	cin >> number;
	int staticArray[100];
	int* dynamicArray = new int[number];
	delete dynamicArray;

	//int a = 5;	//ensure a is initialized otherwise we get garbage (using references doesn't make you immune)!
	//int& b = a;
	//ReferenceTest(b);
	//int a = 0, b = 0;
	//Test(&a, b);
	//printf("%i %i\n", a, b);

	//char character = 0;
	//short smallNumber = 1;
	//int largeNumber = 2;
	//
	//int arr[4] = { 1, 2, 3, 4 };

	//IncrementByValue(number);
	//IncrementByReference(number);
	//printf("%i\n", number);
	//Rectangle r;
	//r.SetLength(10);
	//Rectangle r2 = ModifyRectangle(r);
	//DisplayRectangle(r2);
	//printf("%i\n", r.Area());
	//Circle circle, circle2(5.0f);
	//Circle* dynamicCircle = new Circle();
	//Function();
	//Function(5);
	//circle.~Circle();
	//delete dynamicCircle;
	//cin.get();
	return 0;
}
