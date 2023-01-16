#include <iostream>

using namespace std;

int intFunction()
{
	printf("I am a function that returns an integer!\n");
	return 5;
}

void voidFunction()
{
	return;
	printf("I AM A FUNCTION!!!!\n");
}

float add(float a, float b)
{
	return a + b;
}

int main()
{
	//voidFunction();
	//unsigned char byte = 0;
	//for (int counter = 300; counter > 0; counter--)
	//{
	//	printf("%i\n", byte++);
	//}
	float c = add(1, 2);
	printf("%f\n", c);

	int counter = 0;
	while (true)
	{
		counter++;
		printf("Running!\n");
		if (counter == 4)
			break;
	}

	cout << sizeof (int) << endl;
	cout << sizeof (long long) << endl;
	cout << sizeof (float) << endl;
	cout << sizeof (double) << endl;

	float f = 1.2345f;
	double d = 5.4321;

	printf("%f %f\n", f, d);

	//int result = intFunction();
	//printf("Return value: %i\n", result);

	//int number = 7;
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
	//if (number == 4)
	//	printf("4\n");
	//else if (number == 5)
	//	printf("5\n");
	//else if (number == 6)
	//	printf("6\n");
	//else if (number == 7)
	//	printf("7\n");
	//else if (number == 8)
	//	printf("8\n");
	//else
	//	printf("Your number is not 4 through 8\n");

	//switch (number)
	//{
	//	case 4:
	//		printf("4\n");
	//		break;
	//
	//	case 5:
	//		printf("5\n");
	//		break;
	//
	//	case 6:
	//		printf("6\n");
	//		break;
	//
	//	case 7:
	//		printf("7\n");
	//		break;
	//
	//	case 8:
	//		printf("8\n");
	//		break;
	//
	//	default:
	//		printf("Your number is not 4 through 8\n");
	//}

	// You can only switch through number types (int and such)
	//string name = "connor";
	//if (name == "connor")
	//	cout << "blaaah";
	//else
	//	cout << "naaah";
	//switch (name)
	//{
	//default:
	//	break;
	//}

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