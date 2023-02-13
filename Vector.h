#pragma once
#include <cassert>

template<typename T>
class Vector
{
public:
	Vector()
	{
		mData = new T[mCapacity];
	}

	// Add an element to the end of the vector
	void Push(T value)
	{
		// Re-allocate and copy before appending if we're at capacity
		if (mSize == mCapacity)
		{
			mCapacity++;

			T* newMemory = new T[mCapacity];
			for (size_t i = 0; i < mSize; i++)
				newMemory[i] = mData[i];

			delete[] mData;
			mData = newMemory;
		}

		mData[mSize++] = value;
	}

	// Remove an element from the end of the vector
	void Pop()
	{
		assert(mSize > 0);	// ensure there's elements to remove
		mData[--mSize].~T();// call T's destructor to ensure whatever we remove gets deallocated
	}

	// Add an arbitrary element
	void Insert(const T& element, size_t index)
	{
		assert(index < mSize);
		if (index == mSize - 1)
			Push(element);
		else
		{
			// You try!
		}
	}

	// Remove an arbitrary element
	void Erase(size_t index)
	{
		assert(mSize > 0 && index < mSize);
		if (index == mSize - 1)
			Pop();
		else
		{
			// You try!
		}
	}

	// Access any element
	T& operator[](size_t index)
	{
		assert(index < mSize);
		return mData[index];
	}

	// Access the first element
	T& Front()
	{
		assert(mSize > 0);
		return mData[0];
	}

	// Access the last element
	T& Back()
	{
		assert(mSize > 0);
		return mData[mSize - 1];
	}

	// Get the number of elements
	size_t Size()
	{
		return mSize;
	}

private:
	int* mData = nullptr;
	size_t mSize = 0;		// <-- number of elements
	size_t mCapacity = 2;	// <-- total size
};
