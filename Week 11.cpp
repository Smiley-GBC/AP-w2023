#include <iostream>

using namespace std;

struct NumberNode
{
	int value = 0;
	NumberNode* next = nullptr;
};

using NodeFunction = void(*)(NumberNode*&);

void ForEach(NumberNode*& node, NodeFunction function)
{
	if (node != nullptr)
	{
		NumberNode*& next = node->next;
		function(node);
		ForEach(next, function);
	}
}

void Display(NumberNode*& node)
{
	cout << node->value << endl;
}

void Destroy(NumberNode*& node)
{
	delete node;
	node = nullptr;
}

class NumberList
{
public:
	void Add(int value)
	{
		if (head == nullptr)
		{
			// Create the head if the list is empty
			head = new NumberNode{ value };
		}
		else
		{
			// Otherwise, append to the end of the list (end's next is always nullptr)
			NumberNode* node = head;
			while (node->next != nullptr)
			{
				node = node->next;
			}
			node->next = new NumberNode{ value };
		}
	}

	void Remove(int value)
	{
		// Exit if the list is empty
		if (head == nullptr) return;

		// (Note that making this a *& breaks things since we want current to be a copy)
		NumberNode* current = head; 
		if (head->value == value)
		{
			// If the head contains the value, delete it and make the next node the head 
			head = head->next;
			delete current;
		}
		else
		{
			// Search for the value
			NumberNode* previous = nullptr;
			while (current != nullptr && current->value != value)
			{
				previous = current;
				current = current->next;
			}
			// If the value was found, assign previous to current's next
			if (current != nullptr)
			{
				previous->next = current->next;
				delete current;
			}
		}
	}

protected:
	NumberNode* head = nullptr;
};

int main()
{
	NumberList numberList;
	numberList.Add(0);
	numberList.Add(1);
	numberList.Add(2);
	numberList.Add(3);
	numberList.Remove(3);
	numberList.Remove(0);
	numberList.Remove(2);
	numberList.Remove(1);

	return 0;
}

// Right-to-left initialization
//NumberNode* head = new NumberNode{ 3, nullptr };
//head = new NumberNode{ 2, head };
//head = new NumberNode{ 1, head };
//head = new NumberNode{ 0, head };

// Left-to-right initialization
//NumberNode* head =
//	new NumberNode { 0,
//	new NumberNode { 1,
//	new NumberNode { 2,
//	new NumberNode { 3 }
//}} };

// Per-node operations
//ForEach(head, Display);
//ForEach(head, Destroy);
