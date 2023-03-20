/*
#include "C_List.h"
#include "Cpp_List.h"

void TestC();
void TestCpp();

int main()
{
	TestC();
	TestCpp();
	return 0;
}

void TestC()
{
	Node<int>* head = nullptr;

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
	List<int> list;

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
}//*/