/*
#include <iostream>
using std::cout;

// Don't write cursed code like this.
// This will cause an infinite while loop!
void loop()
{
	//#define true false
	#define if while
	bool value = true;
	if (value)
		cout << "true";
}

// Similarly, we want our operators to actually do what they say!
struct Test {
	void operator++()
	{
		value--;
	}

	void operator--()
	{
		value++;
	}

	int value;
};

int main()
{
	Test t1, t2;
	t1.value = 1;
	t2.value = 2;
	++t1;
	--t2;
	printf("%i %i\n", t1.value, t2.value);

	return 0;
}//*/