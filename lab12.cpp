///*
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

void Example1();	// Auto-dequeue
void Example2();	// Iterators
void Example3();	// STL deque
void Example4();	// STL priority_queue

int main()
{
	Example4();

	return 0;
}

// Same as our custom Stack & Queue classes, but via STL!
void Example1()
{
	queue<int> numberQueue;
	numberQueue.push(1);
	numberQueue.push(2);
	numberQueue.push(3);

	stack<int> numberStack;
	numberStack.push(1);
	numberStack.push(2);
	numberStack.push(3);

	while (!numberQueue.empty())
	{
		int front = numberQueue.front();
		cout << front << endl;
		numberQueue.pop();
	}

	while (!numberStack.empty())
	{
		int top = numberStack.top();
		cout << top << endl;
		numberStack.pop();
	}

	// Stacks & queues do not have "iterators" so we cannot do a range-based for-loop
	//for (int number : numberStack)
}

void Example2()
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	// Iterators are "type-safe pointer arithmetic mechanisms"
	vector<int>::iterator autoBegin = numbers.begin();
	vector<int>::iterator autoEnd = numbers.end();
	for (vector<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++)
	{
		cout << (*itr) << endl;
	}

	// Manual loop
	int* manualBegin = numbers.data();
	int* manualEnd = numbers.data() + numbers.size();
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << *numbers.data() + i;
	}
	
	// Automatic loop (the compiler uses iterators to "magically" give you "number")
	for (int number : numbers)
	{
		cout << number << endl;
	}
}

void Example3()
{
	deque<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	// Just like STL stack & queue, we can pop from a deque until its empty
	// *THIS WILL EMPTY THE DEQUE*
	while (!numbers.empty())
	{
		int front = numbers.front();
		cout << front << endl;
		numbers.pop_front();
	}

	// STL deque exposes more methods (like .begin() and .end() for iterators) to the user
	for (int number : numbers)
	{
		cout << number << endl;
	}
}

void Example4()
{
	queue<int> unsortedNumbers;

	// "decltype" is just "auto" for function calls.
	auto compare = [](int a, int b) -> bool { return a > b; };
	priority_queue<int, std::vector<int>, decltype(compare)> sortedNumbers(compare);

	unsortedNumbers.push(3);
	unsortedNumbers.push(2);
	unsortedNumbers.push(1);

	sortedNumbers.push(3);
	sortedNumbers.push(2);
	sortedNumbers.push(1);

	while (!unsortedNumbers.empty())
	{
		cout << unsortedNumbers.front() << endl;
		unsortedNumbers.pop();
	}

	while (!sortedNumbers.empty())
	{
		cout << sortedNumbers.top() << endl;
		sortedNumbers.pop();
	}

	cout << "Done" << endl;
}

//*/