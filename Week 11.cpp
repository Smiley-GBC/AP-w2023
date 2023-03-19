#include <iostream>

using namespace std;

struct NumberNode
{
	int value = 0;
	NumberNode* next = nullptr;
};

void Display(NumberNode* node)
{
	if (node != nullptr)
	{
		cout << node->value << endl;
		Display(node->next);
	}
}

int main()
{
	NumberNode* head =
		new NumberNode { 0,
		new NumberNode { 1,
		new NumberNode { 2,
		new NumberNode { 3 }
	}} };

	Display(head);

	return 0;
}

//NumberNode* head = new NumberNode{ 3, nullptr };
//head = new NumberNode{ 2, head };
//head = new NumberNode{ 1, head };
//head = new NumberNode{ 0, head };
