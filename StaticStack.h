#pragma once

// Static Integer Stack (array implementation)
class StaticStack
{
public:
	// Stack Exceptions (Inner classes)
	class Overflow {};
	class Underflow {};

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
		if (top == capacity) throw Overflow();
		stackArray[top] = value;
		top++;
	}

	int Pop()
	{
		if (IsEmpty()) throw Underflow();
		top--;
		return stackArray[top];
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