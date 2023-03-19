#include <iostream>

using namespace std;

struct NumberNode
{
	int value = 0;
	NumberNode* next = nullptr;
};

using NodeFunction = void(*)(NumberNode*&);

void ForEach(NumberNode*& node, NodeFunction function)
{
	if (node != nullptr)
	{
		NumberNode* next = node->next;
		function(node);
		ForEach(next, function);
	}
}

void Display(NumberNode*& node)
{
	cout << node->value << endl;
}

void Destroy(NumberNode*& node)
{
	delete node;
	node = nullptr;
}

class NumberList
{
protected:
	NumberNode* head = nullptr;
};

int main()
{
	NumberList numberList;

	return 0;
}

// Right-to-left initialization
//NumberNode* head = new NumberNode{ 3, nullptr };
//head = new NumberNode{ 2, head };
//head = new NumberNode{ 1, head };
//head = new NumberNode{ 0, head };

// Left-to-right initialization
//NumberNode* head =
//	new NumberNode { 0,
//	new NumberNode { 1,
//	new NumberNode { 2,
//	new NumberNode { 3 }
//}} };

// Per-node operations
//ForEach(head, Display);
//ForEach(head, Destroy);
