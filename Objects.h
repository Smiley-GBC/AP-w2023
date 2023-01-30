#pragma once
#include <string>

using std::string;

// No need for this friend function declaration since all members are public.
//friend ostream& operator<<(ostream& out, const Achievement& achievement);

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