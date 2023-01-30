/*
#include "NumberArray.h"

// Our copy-assignment operator should match our copy-constructor
// Note that objects have already been initialized when calling operator=
int main()
{
	NumberArray a0, a2;
	a0.setValue(2);
	NumberArray a1(a0);

	a0.print();
	a1.print();

	a0.setValue(3);
	a1 = a0 = a2;

	return 0;
}//*/