/*
#include <iostream>
#include <string>
#include "Vector2.h"
//#include "IntArray.h"
//#include "NumberArray.h"
#include <array>
using namespace std;

// We've taken 15 lines of code and reduced it to 5 thanks to templates!
template<typename T>
T Square(T number)
{
	return number * number;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

template<typename T>
T Sum3(T a, T b, T c)
{
	// This is fine and easier to read, just note that we can nest functions!
	//return a + b + c;
	return Add(Add(a, b), c);
}

template<typename T>
T Avg3(T a, T b, T c)
{
	return Sum3(a, b, c) / 3;
}

template<typename T>
struct Test
{
	T value;
};

struct TestFloat : public Test<float> {};
struct TestInt : public Test<int> {};
struct TestChar : public Test<char> {};
struct TestString : public Test<string> {};

int main()
{
	int x2 = Square(2);
	float f2 = Square(2.2f);
	Vector2 v2{ 1.0f, 2.0f };
	v2 = Square(v2);

	int sum3 = Sum3(2, 3, 4);
	int avg3 = Avg3(2, 3, 4);

	TestFloat tf;
	TestInt ti;
	TestChar tc;
	TestString ts;
	tf.value = 1.2f;
	ti.value = 99999;
	tc.value = 'c';
	ts.value = "asdkaljsdjlkasdj";
	Test<int> test;
	test.value = 5;

	// You can't multiply strings (operator*) so this doesn't compile!
	//string str = "";
	//str = Square(str);

	// IntArray and NumberArray are ~70 lines each. This is getting out of hand!!
	//IntArray iArr(10);
	//NumberArray nArr(10, 1.2);
	//nArr.print();

	// Generic data structure so it works for custom types too!!!
	//array<Test, 20> tArr;

	array<int, 10> iArr;
	array<double, 20> nArr;
	iArr.fill(10);
	nArr.fill(20.123f);

	// We can examine stl array to see how it makes use of its templated parameters -- 2nd one is size!
	cout << iArr.size() << endl;
	cout << nArr.size() << endl;
	iArr.front() = 0;
	iArr.back() = 100;

	for (int i = 0; i < iArr.size(); i++)
	{
		cout << iArr.data()[i] << ", ";
	}

	// Identical to the above for loop
	//for (int& i : iArr)
	//	cout << i << ", ";
	//cout << endl;

	for (double& d : nArr)
		cout << d << ", ";
	cout << endl;

	return 0;
}
//*/

/*
int Square(int number)
{
	return number * number;
}

int Add(int number)
{
	return number + number;
}

int Sub(int number)
{
	return number - number;
}

float Square(float number)
{
	return number * number;
}

float Add(float number)
{
	return number + number;
}

float Sub(float number)
{
	return number - number;
}
*/