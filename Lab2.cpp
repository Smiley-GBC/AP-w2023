#include <iostream>
#include <string>

using namespace std;

struct Achievement
{
	string title;
	string description;
	int score;
};

struct Game
{
	string name;
	string publisher;
	string developer;
	Achievement* achievements;
	int achievementCount;
};

struct Platform
{
	string name;
	string manufacturer;
	Game* games;
	int gameCount;
};

void Run();

struct Test
{
	Test()
	{
		counter++;
		number = counter;
		cout << "Object " << number << " created" << endl;
	}

	~Test()
	{
		cout << "Object " << number << " destroyed" << endl;
	}

	int number;
	static int counter;
};

int Test::counter = 0;

int main()
{
	Run();
	return 0;
}

void Run()
{
	int platformCount = 0;
	cout << "How many consoles would you like to create?" << endl;
	cin >> platformCount;
	Platform* platforms = new Platform[platformCount];

	// Step 1. Gather input
	for (int i = 0; i < platformCount; i++)
	{
		Platform& platform = platforms[i];
		cout << "What is the name of platform " << i + 1 << "?" << endl;
		cin >> platform.name;
		cout << "Who makes the " << platform.name << "?" << endl;
		cin >> platform.manufacturer;
		cout << "How many games are on the " << platform.name << "?" << endl;
		cin >> platform.gameCount;
		platform.games = new Game[platform.gameCount];

		for (int j = 0; j < platform.gameCount; j++)
		{
			Game& game = platform.games[j];
			cout << "What is the name of game " << j + 1 << "?" << endl;
			cin >> game.name;
			cout << "Who publishes the " << game.name << "?" << endl;
			cin >> game.publisher;
			cout << "Who develops the " << game.name << "?" << endl;
			cin >> game.developer;
			cout << "How many achievements does " << game.name << " have ?" << endl;
			cin >> game.achievementCount;
			game.achievements = new Achievement[game.achievementCount];

			for (int k = 0; k < game.achievementCount; k++)
			{
				Achievement& achievement = game.achievements[k];
				cout << "What the title of achievement " << k + 1 << "?" << endl;
				cin >> achievement.title;
				cout << "What is the description of " << achievement.title << "?" << endl;
				cin >> achievement.description;
				cout << "What is the score of achievement " << achievement.title << "?" << endl;
				cin >> achievement.score;
			}
		}
	}

	// Step 2. Generate output
	for (int i = 0; i < platformCount; i++)
	{
		Platform& platform = platforms[i];
		cout << "Name: " << platform.name << endl;
		cout << "Manufacturer: " << platform.manufacturer << endl;
		cout << "Number of games: " << platform.gameCount << endl << endl;
		for (int j = 0; j < platform.gameCount; j++)
		{
			Game& game = platform.games[j];
			cout << "Name: " << game.name << endl;
			cout << "Publisher: " << game.publisher << endl;
			cout << "Developer: " << game.developer << endl;
			cout << "Number of acheivements: " << game.achievementCount << endl << endl;

			for (int k = 0; k < game.achievementCount; k++)
			{
				Achievement& achievement = game.achievements[k];
				cout << "Title: " << achievement.title << endl;
				cout << "Description " << achievement.description << endl;
				cout << "Score: " << achievement.score << endl;
			}
			delete[] game.achievements;
		}
		delete[] platform.games;
	}
	delete[] platforms;
}
