#pragma once

class NumberArray
{
private:
	double* aPtr;
	int arraySize;
public:
	// Function prototypes
	NumberArray();							// Default constructor
	NumberArray(const NumberArray&);		// Copy constructor
	NumberArray& operator=(const NumberArray&);// copy assignment (note the return type)
	NumberArray(int size, double value);
	~NumberArray();							// Destructor

	void print() const;
	void setValue(double value);
};