#pragma once
#include <iostream>
class DynamicStack
{
private:
	class StackNode
	{
		friend class DynamicStack;
		int value;
		StackNode* next;

		// Constructor
		StackNode(int value, StackNode* next = nullptr)
		{
			this->value = value;
			this->next = next;
		}
	};

	StackNode* top;
public:
	DynamicStack()
	{
		top = nullptr;
	}

	void Push(int value)
	{
		top = new StackNode(value, top);
	}

	int Pop()
	{
		

		if (IsEmpty())
		{
			std::cout << "The stack is empty.\n";
			exit(1);	// Don't do this!!! Use exception handling
			return 0;
		}
		else
		{
			int value = top->value;
			StackNode* temp = top;
			top = top->next;
			delete temp;
			return value;
		}
	}

	bool IsEmpty() const
	{
		return (!top);
	}
};