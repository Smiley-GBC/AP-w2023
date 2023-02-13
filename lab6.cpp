#include <cassert>

class DecimalArray
{
public:
	float& operator[](size_t index)
	{
		assert(index < mSize);
		return mData[index];
	}

private:
	float mData[16];
	const size_t mSize = 16;
};

class IntegerArray
{
public:
	float& operator[](size_t index)
	{
		assert(index < mSize);
		return mData[index];
	}

private:
	float mData[16];
	const size_t mSize = 16;
};

int main()
{
	DecimalArray decimals;
	IntegerArray integers;
	integers[16] = 2;
	return 0;
}
