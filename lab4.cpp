/*
#include "Streams.h"
#include "Vector2.h"

void RunUpdatedLab1Solution();

int main()
{
	// add & sub test
	{
		Vector2 a, b;
		a.x = 1.0f;
		b.x = 2.0f;
		a.y = 3.0f;
		b.y = 4.0f;
		a = a + b;
		a = a - b;
	}

	// mul & div test
	{
		Vector2 a{ 5.0f, 10.0f };
		Vector2 b{ 5.0f, 2.0f };
		Vector2 c = a * b;
		Vector2 d = a / b;
	}

	// member-wise test
	{
		Vector2 a{ 1.0f, 1.0f };
		a += {2.0f, 2.0f};
		a -= {2.0f, 2.0f};
		a *= {2.0f, 2.0f};
		a /= {2.0f, 2.0f};
	}

	{
		Vector2 a{ 1.0f, 2.0f };
		float x = a[0];
		float y = a[1];
		a %= Vector2{ 2.0f, 2.0f };

		Vector2 b{ 3.0f, 4.0f };
		++b;
	}

	// Prefix means we execute the addition first, whereas postfix means we execute the addition after
	// if we did value2 = value1++, value2 would equal zero cause its assigned before value1 is incremented!
	//int value1 = 0;
	//int value2 = 0;
	//value2 = ++value1;

	{
		Vector2 a{ 1.0f, 2.0f };
		Vector2 b = a++;
		Vector2 c = --b;
	}

	{
		// cin and cout are just console streams. Files are also streams which are just groups of data.
		// Hence, we can pass them to functions to modify/use them!
		//std::string str;
		//std::getline(cin, str);
		// 
		// Again, all >> and << is, is syntactic sugar for our Input & Output functions!
		//Input(cin, a);
		//Output(cout, a);
		//Vector2 a;
		//cin >> a;
		//cout << a;
		//Vector2 b = a++;
	}

	// Again just like native types, comparison operators are binary operators which return booleans!
	//int a = 1;
	//int b = 2;
	//bool equal = a == b;
	//bool greater = a > b;
	//bool less = a < b;

	Vector2 a{ 1.0f, 1.0f };
	Vector2 b{ 1.0f, 2.0f };
	bool equal = a != b;
	
	return 0;
}

void RunUpdatedLab1Solution()
{
	int platformCount = 0;
	cout << "How many consoles would you like to create?" << endl;
	cin >> platformCount;
	Platform* platforms = new Platform[platformCount];

	// Step 1. Gather input
	for (int i = 0; i < platformCount; i++)
	{
		Platform& platform = platforms[i];
		cin >> platform;
		//InputPlatform(platform);
		// There's nothing special about the stream extraction operator, it just looks nice.
		for (int j = 0; j < platform.gameCount; j++)
		{
			Game& game = platform.games[j];
			cin >> game;
			for (int k = 0; k < game.achievementCount; k++)
			{
				Achievement& achievement = game.achievements[k];
				cin >> achievement;
			}
		}
	}

	// Step 2. Generate output
	for (int i = 0; i < platformCount; i++)
	{
		Platform& platform = platforms[i];
		cout << platform;
		for (int j = 0; j < platform.gameCount; j++)
		{
			Game& game = platform.games[j];
			cout << game;
			for (int k = 0; k < game.achievementCount; k++)
			{
				Achievement& achievement = game.achievements[k];
				cout << achievement;
			}
			delete[] game.achievements;
		}
		delete[] platform.games;
	}
	delete[] platforms;
}//*/
