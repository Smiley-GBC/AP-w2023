#include <iostream>
#include <string>

using namespace std;

// When in doubt, ask google! There's a lot of random c++ facts to keep in your head...
//https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
/*class Complex
{
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0)
	{
		real = r;   imag = i;
	}
	friend ostream& operator << (ostream& out, const Complex& c);
	friend istream& operator >> (istream& in, Complex& c);
};

ostream& operator << (ostream& out, const Complex& c)
{
	out << c.real;
	out << "+i" << c.imag << endl;
	return out;
}

istream& operator >> (istream& in, Complex& c)
{
	cout << "Enter Real Part ";
	in >> c.real;
	cout << "Enter Imaginary Part ";
	in >> c.imag;
	return in;
}*/

struct Achievement
{
	string title;
	string description;
	int score;

	// No need for this friend function declaration since all members are public.
	//friend ostream& operator<<(ostream& out, const Achievement& achievement);
};

ostream& operator<<(ostream& out, const Achievement& achievement)
{
	out << "Title: " + achievement.title << endl;
	out << "Description: " + achievement.description << endl;
	out << "Score: " + std::to_string(achievement.score) << endl;
	// out << "Score: " + achievement.score << endl; <-- error!
	// Note that string overloads operator+ to combine two strings!
	return out;
}

istream& operator>>(istream& in, Achievement& achievement)
{
	cout << "What the title of your achievement?" << endl;
	in >> achievement.title;
	cout << "What is the description of " << achievement.title + "?" << endl;
	in >> achievement.description;
	cout << "What is the score of achievement " << achievement.title + "?" << endl;
	in >> achievement.score;
	return in;
}

struct Game
{
	string name;
	string publisher;
	string developer;
	Achievement* achievements;
	int achievementCount;
};

istream& operator>>(istream& in, Game& game)
{
	cout << "What is the name of your game?" << endl;
	in >> game.name;
	cout << "Who publishes the " << game.name << "?" << endl;
	in >> game.publisher;
	cout << "Who develops the " << game.name << "?" << endl;
	in >> game.developer;
	cout << "How many achievements does " << game.name << " have?" << endl;
	in >> game.achievementCount;
	game.achievements = new Achievement[game.achievementCount];
	return in;
}

ostream& operator<<(ostream& out, const Game& game)
{
	out << "Name: " << game.name << endl;
	out << "Publisher: " << game.publisher << endl;
	out << "Developer: " << game.developer << endl;
	out << "Number of acheivements: " << game.achievementCount << endl << endl;
	return out;
}

struct Platform
{
	string name;
	string manufacturer;
	Game* games;
	int gameCount;
};

ostream& operator<<(ostream& out, const Platform& platform)
{
	cout << "Name: " << platform.name << endl;
	cout << "Manufacturer: " << platform.manufacturer << endl;
	cout << "Number of games: " << platform.gameCount << endl << endl;
	return out;
}

istream& operator>>(istream& in, Platform& platform)
{
	cout << "What is the name of your platform?" << endl;
	in >> platform.name;
	cout << "Who makes the " << platform.name << "?" << endl;
	in >> platform.manufacturer;
	cout << "How many games are on the " << platform.name << "?" << endl;
	in >> platform.gameCount;
	platform.games = new Game[platform.gameCount];
	return in;
}

void RunLab1Solution();

int main()
{
	RunLab1Solution();
	return 0;
}

void RunLab1Solution()
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
}
