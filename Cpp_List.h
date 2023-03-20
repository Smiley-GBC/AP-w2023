#include <iostream>
using namespace std;

class List
{
protected:
	struct Node
	{
		int value = 0;
		Node* next = nullptr;
	} *head = nullptr;

	using NodeMethod = void(List::*)(Node*&);

	void ForEach(NodeMethod method, Node*& node)
	{
		if (node != nullptr)
		{
			// https://stackoverflow.com/questions/2898316/using-a-member-function-pointer-within-a-class
			Node*& next = node->next;
			(this->*method)(node);
			ForEach(method, next);
		}
	}

public:
	~List()
	{
		ForEach(&List::destroy, head);
	}

	void Display()
	{
		ForEach(&List::display, head);
	}

	void Add(int value)
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

	void Remove(int value)
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

private:
	void display(Node*& node)
	{
		cout << node->value << endl;
	}

	void destroy(Node*& node)
	{
		delete node;
		node = nullptr;
	}
};
