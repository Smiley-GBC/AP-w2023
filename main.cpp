#include <iostream>

using namespace std;


void function()
{
	printf("I AM A FUNCTION!!!!\n");
}

int main()
{
	int number = 7;
	//int* numberPointer = nullptr;
	//if (numberPointer == nullptr)
	//	numberPointer = &number;
	//printf("%i\n", *numberPointer);

	// if-statements only evaluate booleans
	// It's best to only pass booleans. However,
	// 0 evaluates to false and anything non-zero evaluates to true:
	//int condition = 9023485023945098; <-- true
	//int falseCondition = 0 <-- false
	//bool condition = number == 6;
	//if (condition)
	//	printf("True!\n");
	//else
	//	printf("False\n");

	// In if-blocks, only the true statement is executed.
	// Statements are evaluated sequentially (top-down).
	if (number == 4)
		printf("4\n");
	else if (number == 5)
		printf("5\n");
	else if (number == 6)
		printf("6\n");
	else if (number == 7)
		printf("7\n");
	else if (number == 8)
		printf("8\n");
	else
		printf("Your number is not 4 or 5\n");

	// Just like normal variables, pointers should be default-initialized.
	// Otherwise, you get corrupted memory
	//int goodNumber = 5;
	//int badNumber;
	//int* goodPointer = nullptr;
	//int* badPointer;

	//printf("%i\n", *goodPointer);<-- runtime failure -- not allowed!!!
	//printf("%i\n", *badPointer); <-- compiler doesn't allow this (which is good)

	//int a = 4, b = 3, c = 2, d = 1;
	//int* arr[4]{ &a, &b, &c, &d };
	//a = 9;
	//*arr[0] = 9;

	//printf("%i %i %i %i\n", a, b, c, d);
	//printf("%i %i %i %i\n", *arr[0], *arr[1], *arr[2], *arr[3]);
	
	cin.get();
	return 0;
}
