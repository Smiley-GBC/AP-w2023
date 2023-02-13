#include <cassert>

template<typename T>
class Array
{
public:
	T& operator[](size_t index)
	{
		assert(index < mSize);
		return mData[index];
	}

private:
	T mData[16];
	const size_t mSize = 16;
};

int main()
{
	Array<float> decimals;
	Array<int> integers;
	integers[15] = 2;
	return 0;
}
