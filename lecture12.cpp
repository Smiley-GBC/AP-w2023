/*
#include "StaticStack.h"
#include "StaticQueue.h"
#include "DynamicStack.h"
#include "DynamicQueue.h"

#include <iostream>
using namespace std;

// With great power comes great responsibility!
void Print(int* arr, int cap, int idx, int top)
{
	//delete[] arr; <-- case and point
	printf("Element at index %i has value %i\n", idx, arr[idx]);
}

int main()
{
	// Don't confuse "Stack Overflow" with "Overflowing a stack"
	// "Stack Overflow" is when we don't have enough memory to make a stack allocation
	// "Overflow" is when a value is greater than a maximum
	// "Underflow" is when a value is less than a minimum
	//int data[10000000];
	
	StaticStack stack(3);
	stack.Push(5);
	stack.Push(10);
	stack.Push(15);

	StaticQueue queue(3);
	queue.Enqueue(5);
	queue.Enqueue(10);
	queue.Enqueue(15);
	
	cout << "Popping stack (last in first out): " << endl;
	stack.ForEach(Print);
	//stack.Print();
	//cout << stack.Top() << endl;
	//cout << stack.Top() << endl;
	//cout << stack.Top() << endl;
	//cout << stack.Pop() << endl;
	//cout << stack.Pop() << endl;
	//cout << stack.Pop() << endl;
	//while (!stack.IsEmpty())
	//{
	//	cout << stack.Pop() << endl;
	//}

	cout << endl << "Popping queue (first in first out): " << endl;
	cout << queue.Front() << endl;
	cout << queue.Front() << endl;
	cout << queue.Front() << endl;
	//cout << queue.Dequeue() << endl;
	//cout << queue.Dequeue() << endl;
	//cout << queue.Dequeue() << endl;
	//while (!queue.IsEmpty())
	//{
	//	cout << queue.Dequeue() << endl;
	//}

	return 0;
}
//*/