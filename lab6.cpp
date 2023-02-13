///*
#include <cassert>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "Array.h"
#include "Vector.h"
using namespace std;

int main()
{
	Vector<int> v;
	v.Push(1);
	v.Pop();
	v.Push(2);
	v.Pop();
	v.Push(3);
	v.Pop();
	v.Push(4);
	v.Push(5);
	v.Push(6);
	v.Pop();
	v.Pop();
	v.Pop();
	v.Push(4);
	v.Push(5);
	v.Push(6);

	cout << v.Front() << endl;
	cout << v.Back() << endl;
	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << endl;
	}

	// This is better than native arrays because it zero-initializes members and has a range check!
	Array<float, 2> decimals;
	return 0;
}//*/

// "using" allows us to give a type an alias. The following lines are identical to the compiler.
//using Number = int;
//int a;
//Number a;
// Note to self, the STL is a dark dark place