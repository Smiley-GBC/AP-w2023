#include "C_List.h"
#include "Cpp_List.h"

void TestC();
void TestCpp();

int main()
{
	//TestC();
	TestCpp();
	return 0;
}

void TestC()
{
	Node* head = nullptr;

	AddSorted(head, 3);
	AddSorted(head, 2);
	AddSorted(head, 1);
	AddSorted(head, 0);
	cout << "List after add:\n";
	ForEach(Display, head);

	Remove(head, 3);
	Remove(head, 0);
	Remove(head, 2);
	Remove(head, 1);
	cout << "List after remove:\n";
	ForEach(Display, head);
}

void TestCpp()
{
	SortedList list;

	list.Add(3);
	list.Add(2);
	list.Add(1);
	list.Add(0);
	cout << "List after add:\n";
	list.Display();

	list.Remove(3);
	list.Remove(0);
	list.Remove(2);
	list.Remove(1);
	cout << "List after remove:\n";
	list.Display();
}

// Right-to-left initialization
//Node* head = new Node{ 3, nullptr };
//head = new Node{ 2, head };
//head = new Node{ 1, head };
//head = new Node{ 0, head };

// Left-to-right initialization
//Node* head =
//	new Node { 0,
//	new Node { 1,
//	new Node { 2,
//	new Node { 3 }
//}} };

// Per-node operations
//ForEach(head, Display);
//ForEach(head, Destroy);
