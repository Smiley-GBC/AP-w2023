#include <iostream>
#include "NumberArray.h"
using namespace std;

NumberArray::NumberArray()
{
	cout << "No size of array provided. Defaulting to size 10 and value 1." << endl;
	arraySize = 10;
	aPtr = new double[arraySize];
	setValue(1);
}

NumberArray::NumberArray(const NumberArray& obj)
{
	//aPtr = obj.aPtr;				// Doesn't solve our problem!
	arraySize = obj.arraySize;
	aPtr = new double[arraySize];	// Solves our problem
	for (int i = 0; i < arraySize; i++)
	{
		aPtr[i] = obj.aPtr[i];		// Explicitly assign each array element to the new array
	}
}

NumberArray& NumberArray::operator=(const NumberArray& obj)
{
	// Unlike the copy constructor, a NumberArray object may exist once the
	// copy assignment operator has been called, so ensure we don't leak memory!
	if (arraySize > 0)
		delete[] aPtr;

	arraySize = obj.arraySize;
	aPtr = new double[arraySize];	// Solves our problem
	for (int i = 0; i < arraySize; i++)
	{
		aPtr[i] = obj.aPtr[i];		// Explicitly assign each array element to the new array
	}
	return *this;
}

NumberArray::NumberArray(int size, double value)
{
	arraySize = size;
	aPtr = new double[arraySize];
	setValue(value);
}

NumberArray::~NumberArray()
{
	if (arraySize > 0)	// Ensure that there is an array that exists
	{
		delete[] aPtr;
		// aPtr = nullptr;
	}
}

void NumberArray::print() const
{
	cout << "Values: ";
	for (int i = 0; i < arraySize; i++)
	{
		cout << aPtr[i] << " ";
	}
	cout << endl;
}

void NumberArray::setValue(double value)
{
	for (int i = 0; i < arraySize; i++)
	{
		aPtr[i] = value;
	}
}