#include <iostream>
#include <string>

using namespace std;

struct Achievement
{
	string title;
	string description;
	float score;
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

int main()
{
	Platform* platforms;
	int platformCount;
	cout << "How many platforms would you like to make?" << endl;
	cin >> platformCount;
	platforms = new Platform[platformCount];
	for (int i = 0; i < platformCount; i++)
	{
		Platform& platform = platforms[i];
		cout << "What is the name of platform " + std::to_string(i) + "?" << endl;
		cin >> platform.name;
		cout << "Who makes the " + platform.name + "?" << endl;
		cin >> platform.manufacturer;
		cout << "How many games does " + platform.manufacturer + "'s " + platform.name + " have?" << endl;
		cin >> platform.gameCount;

		platform.games = new Game[platform.gameCount];
		for (int j = 0; j < platform.gameCount; j++)
		{
			Game& game = platform.games[j];
			cout << "What is the name of game " + std::to_string(j) + "?" << endl;
			cin >> game.name;
			cout << "Who is the publisher of " + game.name << endl;
			cin >> game.publisher;
			cout << "Who are the developers of " + game.name << endl;
			cin >> game.developer;
			cout << "How many achievements can you unlock in " + game.name << endl;
			cin >> game.achievementCount;

			game.achievements = new Achievement[game.achievementCount];
			for (int k = 0; k < game.achievementCount; k++)
			{
				Achievement& achievement = game.achievements[k];
				cout << "What is the title of achievement " + std::to_string(k) + "?" << endl;
				cin >> achievement.title;
				cout << "Please briefly describe achievement " + achievement.title << endl;
				cin >> achievement.description;
				cout << "How many points is achievement " + achievement.title + " worth?" << endl;
				cin >> achievement.score;
			}
		}
	}

	cout << endl;
	cout << "******************" << endl;
	cout << "    Summary" << endl;
	cout << "******************" << endl;
	cout << endl;

	for (int i = 0; i < platformCount; i++)
	{
		Platform& platform = platforms[i];
		cout << "PLATFORMS:" << endl;
		cout << "Manufacturer: " + platform.name << endl;
		cout << "Name: " + platform.name << endl;
		cout << "GAMES:" << endl;
		for (int j = 0; j < platform.gameCount; j++)
		{
			Game& game = platform.games[j];
			cout << "Name: " + game.name << endl;
			cout << "Publisher: " + game.publisher << endl;
			cout << "Developer: " + game.developer << endl;
			cout << "ACHIEVEMENTS:" << endl;
			for (int k = 0; k < game.achievementCount; k++)
			{
				Achievement& achievement = game.achievements[k];
				cout << "Title: " + achievement.title << endl;
				cout << "Description: " + achievement.description << endl;
				cout << "Score: " + std::to_string(achievement.score) << endl;
			}
		}
	}

	cout << "Summary complete. Press any key to quit." << endl;
	return cin.get();
}