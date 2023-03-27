///*
#pragma once
#include <iostream>
class DynamicQueue
{
private:
	class QueueNode
	{
		friend class DynamicQueue;
		int value;
		QueueNode* next;

		QueueNode(int value, QueueNode* next = nullptr)
		{
			this->value = value;
			this->next = next;
		}
	};

	// These track the front and rear of the queue
	QueueNode* front;
	QueueNode* rear;

public:
	// Constructor and destructor
	DynamicQueue()
	{
		front = rear = nullptr;
	}
	
	~DynamicQueue()
	{
		Clear();
	}

	void Enqueue(int value)
	{
		if (IsEmpty())
		{
			front = new QueueNode(value);
			rear = front;
		}
		else
		{
			rear->next = new QueueNode(value);		// Creates the new node at the end of rear
			rear = rear->next;						// Moves to the new rear node
		}
	}

	int Dequeue()
	{
		if (IsEmpty())
		{
			std::cout << "The queue the empty.\n";
			exit(1);
			return 0;
		}
		else
		{
			int value = front->value;
			QueueNode* temp = front;
			front = front->next;
			delete temp;
			return value;
		}
	}

	bool IsEmpty() const
	{
		return (front == nullptr);
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			Dequeue();
		}
	}
};//*/
