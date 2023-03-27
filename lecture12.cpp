///*
#include "StaticStack.h"
#include "DynamicStack.h"
#include "StaticQueue.h"
#include "DynamicQueue.h"
#include <iostream>
using namespace std;

int main()
{
	// Don't confuse "Stack Overflow" with "Overflowing a stack"
	// "Stack Overflow" is when we don't have enough memory to make a stack allocation
	// "Overflow" is when a value is greater than a maximum
	// "Underflow" is when a value is less than a minimum
	//int data[10000000];
	
	StaticStack stack(5);
	stack.Push(5);
	stack.Push(10);
	stack.Push(15);

	StaticQueue queue(8);
	queue.Enqueue(5);
	queue.Enqueue(10);
	queue.Enqueue(15);
	
	cout << "Popping stack (last in first out): " << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;

	cout << "Popping queue (first in first out): " << endl;
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;

	return 0;
}
//*/