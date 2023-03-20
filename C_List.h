#include <iostream>
using namespace std;

struct Node
{
	int value = 0;
	Node* next = nullptr;
};

inline void Add(Node*& head, int value)
{
	if (head == nullptr)
	{
		// Create the head if the list is empty
		head = new Node{ value };
	}
	else
	{
		// Otherwise, append to the end of the list (end's next is always nullptr)
		Node* node = head;
		while (node->next != nullptr)
		{
			node = node->next;
		}
		node->next = new Node{ value };
	}
}

// Ascending least to greatest
inline void AddSorted(Node*& head, int value)
{
	if (head == nullptr || head->value >= value)
	{
		// Move the head if the incoming value is the lowest
		head = new Node{ value, head };
	}
	else
	{
		// Otherwise, search for the appropriate place to insert
		Node *previous = head, *current = head->next;
		while (current != nullptr && current->value < value)
		{
			previous = current;
			current = current->next;
		}
		previous->next = new Node{ value, current };
	}
}

inline void Remove(Node*& head, int value)
{
	// Exit if the list is empty
	if (head == nullptr) return;

	// (Note that making this a *& breaks things since we want current to be a copy)
	Node* current = head;
	if (head->value == value)
	{
		// If the head contains the value, delete it and make the next node the head 
		head = head->next;
		delete current;
	}
	else
	{
		// Search for the value
		Node* previous = nullptr;
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

using NodeFunction = void(*)(Node*&);

inline void ForEach(NodeFunction function, Node*& node)
{
	if (node != nullptr)
	{
		Node*& next = node->next;
		function(node);
		ForEach(function, next);
	}
}

inline void Display(Node*& node)
{
	cout << node->value << endl;
}

inline void Destroy(Node*& node)
{
	delete node;
	node = nullptr;
}
