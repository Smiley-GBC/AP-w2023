#pragma once
#include <cassert>

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
