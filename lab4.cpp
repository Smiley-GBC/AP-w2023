#include "Streams.h"

int main()
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
	return 0;
}
