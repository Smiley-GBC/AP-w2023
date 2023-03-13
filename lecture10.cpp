#include <iostream>
using namespace std;

void Message(int count)
{
	// "recursive case (condition in which recursion continues) --> do recursion
	if (count > 0)
	{
		cout << "Recursion #" << count << endl;
		Message(count - 1);
	}

	// "base case" (condition in which recursion ends) --> do nothing
	else
	{
		cout << "No more recursion :(" << endl;
	}
}

int Frequency(char ch, string inputString, int position)
{
	// Base case - We have reached the end of the string
	if (position == inputString.length())
	{
		return 0;
	}

	if (inputString[position] == ch)
	{
		return 1 + Frequency(ch, inputString, position + 1);
	}
	else
	{
		return Frequency(ch, inputString, position + 1);
	}
}

unsigned long long int Factorial(unsigned long long int num)
{
	if (num == 0)
	{
		return 1;
	}
	else
	{
		return num * Factorial(num - 1);
	}
}

int GCD(int x, int y)
{
	// base case: x is perfectly divisible by y
	if (x % y == 0)
	{
		return y;
	}
	// recursive case: not perfectly divisible so loop until remainder between x & y works
	else
	{
		return GCD(y, x % y);
	}
}

int Fib(int n)
{
	if (n <= 0)
	{
		return 0;		// Base case
	}
	else if (n == 1)
	{
		return 1;		// Base case
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}

int LinearSearch(const int arr[], int first, int last, int value)
{
	// Did not find value in array
	if (first >= last)
	{
		return -1;
	}

	// Found the value!
	if (arr[first] == value)
	{
		return first;
	}

	// Increment first and keep searching...
	else
	{
		return LinearSearch(arr, ++first, last, value);
	}
}

int BinarySearch(const int arr[], int first, int last, int value)
{
	int middle;		// Mid point of search

	// Base case
	if (first > last)
	{
		return -1;	// Did not find value in array
	}

	middle = (first + last) / 2;

	if (arr[middle] == value)
	{
		// We found the value
		return middle;
	}

	// Value not found
	if (arr[middle] < value)
	{
		// Upper half
		return BinarySearch(arr, middle + 1, last, value);
	}
	else
	{
		// Lower half
		return BinarySearch(arr, first, middle - 1, value);
	}
}

void MoveDisks(int n, string source, string dest, string temp)
{
	if (n > 0) // <-- Base case
	{
		// Move n-1 disks from source to temp use dest as a temp peg
		MoveDisks(n - 1, source, temp, dest);

		// Move a dist from source to dest
		cout << "Move a disk from " << source << " to " << dest << endl;

		// Move n-1 disks from temp to dest using source as the temp peg
		MoveDisks(n - 1, temp, dest, source);
	}
}

int main()
{
	//int large[10000000];
	//Message(3);
	
	//cout << "There are " << Frequency('n', "Connor", 0)
	//	<< "N's " << "in Connor (the wizard)" << endl;
	//cout << "0! = " << Factorial(0) << endl;
	//cout << "1! = " << Factorial(1) << endl;
	//cout << "2! = " << Factorial(2) << endl;
	//cout << "3! = " << Factorial(3) << endl;
	//cout << "4! = " << Factorial(4) << endl;
	//cout << "5! = " << Factorial(5) << endl;

	int gcd = GCD(10, 6);
	int fib = Fib(5);

	int arr[]{ 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
	int valueIndex = BinarySearch(arr, 0, 9, 69);

	return 0;
}