#include <iostream>

using namespace std;

int main()
{
	int number = 5;
	int* numberPointer = nullptr;
	if (numberPointer == nullptr)
		numberPointer = &number;
	printf("%i\n", *numberPointer);
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
	return 0;
}
