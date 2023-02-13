#include <cassert>

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
