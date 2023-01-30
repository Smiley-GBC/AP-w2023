#pragma once
#include <iostream>
#include "Objects.h"

using std::endl;
using std::cout;
using std::cin;
using std::ostream;
using std::istream;

// Again, this does the same thing as
// istream& operator>>(istream& in, Platform& platform), its just a regular function!
//void InputPlatform(Platform& platform)
//{
//	cout << "What is the name of your platform?" << endl;
//	cin >> platform.name;
//	cout << "Who makes the " << platform.name << "?" << endl;
//	cin >> platform.manufacturer;
//	cout << "How many games are on the " << platform.name << "?" << endl;
//	cin >> platform.gameCount;
//	platform.games = new Game[platform.gameCount];
//}

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