#pragma once
#include <cassert>
#include <iostream>

using StackOperation = void(*)(int* arr, int cap, int idx, int top);

// Static Integer Stack (array implementation)
class StaticStack
{
public:
	StaticStack(int capacity)
	{
		this->capacity = capacity;
		stackArray = new int[capacity];
		top = 0;	
	}

	~StaticStack()
	{
		delete[] stackArray;
	}

	void Push(int value)
	{
		assert(top != capacity);
		stackArray[top] = value;
		top++;
	}

	int Pop()
	{
		assert(!IsEmpty());
		top--;
		return stackArray[top];
	}

	void ForEach(StackOperation operation)
	{
		for (int i = top - 1; i >= 0; i--)
		{
			operation(stackArray, capacity, i, top);
		}
	}

	//void Print()
	//{
	//	for (int i = top - 1; i >= 0; i--)
	//	{
	//		printf("%i\n", stackArray[i]);
	//	}
	//}

	int Top()
	{
		return stackArray[top - 1];
	}

	bool IsEmpty() const
	{
		return (top == 0);
	}

private:
	int* stackArray;	// Array
	int capacity;		// How many items can be stored in the stack
	int top;			// Current top of the stack
};
