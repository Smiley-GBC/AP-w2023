#include <iostream>
#include <string>
using namespace std;

struct Range
{
	int lower = numeric_limits<int>::min();	// Lower bound
	int upper = numeric_limits<int>::max();	// Upper bound
	int value = 0;

	struct TooLow
	{
		int value;

		void Message()
		{
			cout << "The value " << value << " is too low." << endl;
		}
	};

	struct TooHigh
	{
		int value;

		void Message()
		{
			cout << "The value " << value << " is too low." << endl;
		}
	};

	int Input()
	{
		cin >> value;

		if (value <= lower)
		{
			throw TooLow{ value };
		}
		else if (value >= upper)
		{
			throw TooHigh{ value };
		}

		return value;
	}
};

double Divide(double numerator, double denominator)
{
	if (denominator == 0)
	{
		//throw int(10);
		throw string("Task failed successfully");
	}
	else
	{
		return numerator / denominator;
	}
}

void Example1CustomDivision();
void Example2CustomBounds();
void Example3BadAllocation();

int main()
{
	Example1CustomDivision();
	//Example2CustomBounds();
	//Example3BadAllocation();
	return 0;
}

void Example1CustomDivision()
{
	int num1, num2;
	double quotient;

	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	try 
	{
		quotient = Divide(num1, num2);
		cout << "The quotient is " << quotient << endl;
	}
	catch (string exceptionString)
	{
		cout << exceptionString;
	}
	catch (int exInt)
	{
		cout << "ERROR! Something happened " << exInt << endl;
	}
}

void Example2CustomBounds()
{
	const int LOWER_BOUND = -10;
	const int UPPER_BOUND = 10;

	// Beware of brace initialization. Its easy to confuse upper vs lower fields!
	Range range{ LOWER_BOUND, UPPER_BOUND };

	int value = 0;
	cout << "Please enter a value between " << LOWER_BOUND << " and " << UPPER_BOUND << endl;
	try
	{
		value = range.Input();
	}
	catch (Range::TooLow e)
	{
		e.Message();
	}
	catch (Range::TooHigh e)
	{
		e.Message();
	}
}

void Example3BadAllocation()
{
	try
	{
		throw bad_alloc();
	}
	catch (bad_alloc b)
	{
		cout << b.what();
	}
}