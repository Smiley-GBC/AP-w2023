#include <cassert>
#include <iostream>
#include <string>
using namespace std;

template<typename T, size_t size>
class Array
{
public:
	T& operator[](size_t index)
	{
		assert(index < size);
		return mData[index];
	}

private:
	T mData[size]{};
};

class IntVector
{
public:
	IntVector()
	{
		mData = new int[mCapacity];
	}

	void Push(int value)
	{
		if (mSize == mCapacity)
		{
			mCapacity++;

			int* newMemory = new int[mCapacity];
			for (size_t i = 0; i < mSize; i++)
				newMemory[i] = mData[i];

			delete[] mData;
			mData = newMemory;
		}

		mData[mSize] = value;
		mSize++;
	}

	//int Pop()
	//{
	//	int copy = mData[mSize];
	//	mSize--;
	//	return copy;
	//}

	int operator[](size_t index)
	{
		assert(index < mSize);
		return mData[index];
	}

	size_t Size()
	{
		return mSize;
	}

private:
	int* mData = nullptr;
	size_t mSize = 0;		// <-- number of elements
	size_t mCapacity = 2;	// <-- total size
};

int main()
{
	IntVector v;
	v.Push(1);
	v.Push(2);
	v.Push(3);
	v.Push(4);

	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << endl;
	}

	//Array<float, 2> decimals;
	//Array<int, 200> integers;
	//integers[15] = 2;
	return 0;
}

// "using" allows us to give a type an alias. The following lines are identical to the compiler.
//using Number = int;
//int a;
//Number a;
// Note to self, the STL is a dark dark place