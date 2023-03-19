struct NumberNode
{
	int value = 0;
	NumberNode* next = nullptr;
};

int main()
{
	// Right-to-left initialization
	//NumberNode* head = new NumberNode{ 3, nullptr };
	//head = new NumberNode{ 2, head };
	//head = new NumberNode{ 1, head };
	//head = new NumberNode{ 0, head };

	// Left-to-right initialization
	NumberNode* head =
		new NumberNode { 0,
		new NumberNode { 1,
		new NumberNode { 2,
		new NumberNode { 3 }
	}} };

	return 0;
}
