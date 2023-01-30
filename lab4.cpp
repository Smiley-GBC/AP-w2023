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
}