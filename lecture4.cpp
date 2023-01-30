/*
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

// We can overload the [] (access) operator to ensure memory is accessed correctly!
// That horrible "subscript out of range" error message comes from failed safety checks.
// Just use it incorrectly, let the compiler take you to the implementation, and see for yourself!
int main()
{
	array<int, 5>arr;
	vector<int>vec;
	vec[5345345];
	string name = "Connor";
	assert(name.length() == 6);
	for (int i = 0; i < name.length(); ++i)
	{
		cout << name[i];
	}
	name[60];
	return 0;
}*/
