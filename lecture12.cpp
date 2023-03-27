///*
#include "StaticStack.h"
#include "DynamicQueue.h"
#include <iostream>
using namespace std;

int main()
{
	StaticStack stack(5);

	stack.Push(5);
	stack.Push(10);
	stack.Push(15);

	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;

	return 0;
}
//*/