/*

#include <iostream>

using namespace std;

// Function overloading, functions can have the same name as long as their parameters are different
void Function()
{
	printf("I am a function\n");
}

void Function(int number)
{
	printf("I am a function with a value of %i\n", number);
}

// Class with a copy-constructor. We can add parameters to a constructor to give objects unique values upon instantiation
// Circle c1; <-- outputs "Default circle created!
// Circle c2(5); <-- outputs "Custom circle create with radius 5"
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

// We can create private methods called "helper functions" to allow for code re-use.
// We need to update the area of the rectangle every time the user modifies the length or width.
// Hence, we call SetArea() within both SetLength() and SetWidth(), but do not allow the user to call it due to private access.
// This could be avoided altogether by re-computing the area within the Area() function by instead returning l * w.
// Storing members that can be easily re-computed is called "stale code". Try to avoid to make your program simpler :)
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

// We can make our program faster by passing objects "by-reference", meaning we use the "actual object" instead of a copy of the object.
void DisplayRectangle(Rectangle& r)
{
	cout << r.GetLength() << endl;
	cout << r.GetWidth() << endl;
}

// When we pass "by-value" (no &), we make a copy of the object.
// Despite calling r.SetWidth(10), it has no effect since the parameter r is a copy of whatever object was passed to ModifyRectangle().
Rectangle ModifyRectangle(Rectangle r)
{
	r.SetWidth(10);
	return r;
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
//	b++;		// We can avoid such issues by working with references instead of pointers when possible
//}

// In c++ classes, dynamic resources should be created within the constructor, and destroyed within the destructor
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

// Note that we must store the amount of elements in our dynamic array otherwise we can't do anything useful with it.
// (How can we loop through an array if we don't know its size)?
	int number;

private:
	int* data;
};

int main()
{	
	// We can use new[] to create a dynamic array, and delete[] to destroy it.
	int number;
	cin >> number;
	int* dynamicArray = new int[number];
	delete dynamicArray;

	// Fixed-sized arrays are managed by the compiler, but their size cannot change!
	int staticArray[100];

	// Different data-types have different sizes. This is evident when inspecting their memory in the debugger.
	char character = 0;
	short smallNumber = 1;
	int largeNumber = 2;

	// Arrays are "contiguous", meaning their elements are beside each other in memory (again, see debugger memory window)!
	int arr[4] = { 1, 2, 3, 4 };

	// value vs reference test
	IncrementByValue(number);
	IncrementByReference(number);
	printf("%i\n", number);

	// value vs reference object test
	Rectangle r;
	r.SetLength(10);
	Rectangle r2 = ModifyRectangle(r);
	DisplayRectangle(r2);
	printf("%i\n", r.Area());

	// function overloading test
	Function();
	Function(5);

	// default vs overloaded constructor test
	Circle circle, circle2(5.0f);
	Circle* dynamicCircle = new Circle();
	delete dynamicCircle;
	//circle.~Circle();
	// Don't call the destructor manually like above! Let the compiler invoke it automatically.
	
	cin.get();
	return 0;
}
//*/
