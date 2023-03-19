#include <iostream>

using namespace std;

struct NumberNode
{
	int value = 0;
	NumberNode* next = nullptr;
};

using NodeFunction = void(*)(NumberNode*);

void ForEach(NumberNode* node, NodeFunction function)
{
	if (node != nullptr)
	{
		function(node);
		ForEach(node->next, function);
	}
}

void Display(NumberNode* node)
{
	cout << node->value << endl;
}

int main()
{
	NumberNode* head =
		new NumberNode { 0,
		new NumberNode { 1,
		new NumberNode { 2,
		new NumberNode { 3 }
	}} };

	ForEach(head, Display);

	return 0;
}

//NumberNode* head = new NumberNode{ 3, nullptr };
//head = new NumberNode{ 2, head };
//head = new NumberNode{ 1, head };
//head = new NumberNode{ 0, head };
