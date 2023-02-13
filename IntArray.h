#pragma once
#include <iostream>
using namespace std;

class IntArray
{
private:
	int* aPtr;
	int arraySize;
	void subError() const;
	void subError(int) const;
	void arraySizeError() const;
public:
	IntArray(int);
	IntArray(const IntArray&);
	~IntArray();
	int size() const 
	{ 
		return arraySize; 
	}

	// Overload the [ ] operator
	int& operator[](int) const;
};