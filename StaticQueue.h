#pragma once
#include <cassert>

// Static queue - array implementation
class StaticQueue
{
public:
	StaticQueue(int s)
	{
		// Dynamically allocated array of ints of size s
		queueArray = new int[s];
		// We can call memset to zero-initialize our dynamic array!
		//memset(queueArray, 0, sizeof(int) * s);
		queueSize = s;
		front = -1;
		rear = -1;
		numItems = 0;
	}

	~StaticQueue()
	{
		delete[] queueArray;
	}

	// Put something on the queue
	void Enqueue(int value)
	{
		assert(!IsFull());

		// Calculate the new rear position
		rear = (rear + 1) % queueSize;
		// Insert the new item
		queueArray[rear] = value;
		// Update the item count
		numItems++;
	}

	// Take something off the queue
	int Dequeue()
	{
		assert(!IsEmpty());

		// Move front
		front = (front + 1) % queueSize;
		// Retrieve the front item
		numItems--;

		return queueArray[front];
	}

	int Front()
	{
		return queueArray[front + 1];
	}

	bool IsEmpty() const
	{
		return numItems <= 0;
	}

	bool IsFull() const
	{
		return numItems >= queueSize;
	}

	void Clear()
	{
		front = rear = -1;
		numItems = 0;
	}

private:
	int* queueArray;	// Array
	int queueSize;		// Capacity
	int front;			// Front of the queue
	int rear;			// Rear  of the queue
	int numItems;		// Number of items in the queue
};
