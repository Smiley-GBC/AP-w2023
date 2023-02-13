#include <cassert>
#include <string>
using namespace std;

template<typename T, size_t size>
class Array
{
public:
	T& operator[](size_t index)
	{
		assert(index < size);
		return mData[index];
	}

private:
	T mData[size]{};
};

int main()
{
	Array<float, 2> decimals;
	Array<int, 200> integers;
	integers[15] = 2;
	return 0;
}

// "using" allows us to give a type an alias. The following lines are identical to the compiler.
//using Number = int;
//int a;
//Number a;
// Note to self, the STL is a dark dark place