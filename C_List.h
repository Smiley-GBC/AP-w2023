#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T value = 0;
	Node* next = nullptr;
};

template<typename T>
inline void Add(Node<T>*& head, T value)
{
	if (head == nullptr)
	{
		// Create the head if the list is empty
		head = new Node<T>{ value };
	}
	else
	{
		// Otherwise, append to the end of the list (end's next is always nullptr)
		Node<T>* node = head;
		while (node->next != nullptr)
		{
			node = node->next;
		}
		node->next = new Node<T>{ value };
	}
}

// Ascending least to greatest
template<typename T>
inline void AddSorted(Node<T>*& head, T value)
{
	if (head == nullptr || head->value >= value)
	{
		// Move the head if the incoming value is the lowest
		head = new Node<T>{ value, head };
	}
	else
	{
		// Otherwise, search for the appropriate place to insert
		Node<T> *previous = head, *current = head->next;
		while (current != nullptr && current->value < value)
		{
			previous = current;
			current = current->next;
		}
		previous->next = new Node<T>{ value, current };
	}
}

template<typename T>
inline void Remove(Node<T>*& head, T value)
{
	// Exit if the list is empty
	if (head == nullptr) return;

	// (Note that making this a *& breaks things since we want current to be a copy)
	Node<T>* current = head;
	if (head->value == value)
	{
		// If the head contains the value, delete it and make the next node the head 
		head = head->next;
		delete current;
	}
	else
	{
		// Search for the value
		Node<T>* previous = nullptr;
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

template<typename T>
using NodeFunction = void(*)(Node<T>*&);

template<typename T>
inline void ForEach(NodeFunction<T> function, Node<T>*& node)
{
	if (node != nullptr)
	{
		Node<T>*& next = node->next;
		function(node);
		ForEach(function, next);
	}
}

template<typename T>
inline void Display(Node<T>*& node)
{
	cout << node->value << endl;
}

template<typename T>
inline void Destroy(Node<T>*& node)
{
	delete node;
	node = nullptr;
}
