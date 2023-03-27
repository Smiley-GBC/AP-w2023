#pragma once
// Static queue - array implementation
#include <iostream>

class StaticQueue
{
public:
	StaticQueue(int s)
	{
		queueArray = new int[s];	// Dynamically allocated array of ints of size s
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
		if (isFull())
		{
			//cout << "The queue is full.\n";
			exit(1);	// Don't do this
		}
		else
		{
			// Calculate the new rear position
			rear = (rear + 1) % queueSize;	// <-- Used to wrap around a set of items -- "Array bounding"
			// Insert the new item
			queueArray[rear] = value;
			// Update the item count
			numItems++;
		}
	}

	// Take something off the queue
	int Dequeue()
	{
		
	}

	bool isEmpty() const
	{

	}

	bool isFull() const
	{

	}

	void clear()
	{

	}

private:
	int* queueArray;	// Array
	int queueSize;		// Capacity
	int front;			// Front of the queue
	int rear;			// Rear  of the queue
	int numItems;		// Number of items in the queue
};