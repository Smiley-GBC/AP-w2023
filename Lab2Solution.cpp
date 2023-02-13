/*
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

struct Weapon;
struct Armor;
struct Character
{
	string name;
	string species = "Human";
	string story;
	float maxHealth = 100.0f;
	Weapon* weapon;
	Armor* armor;
};

struct Weapon
{
	string name;
	array<string, 2> abilities { "Melee", "Spell" };
	float damage = 25.0f;
};

struct Armor
{
	string name;
	string description;
	float durability = 50.0f;
};

ostream& operator<<(ostream& out, const Weapon& weapon)
{
	out << "Weapon name: " << weapon.name << endl;
	out << "Weapon damage: " << weapon.damage << endl;
	out << "Weapon abilities: ";
	for (const string& ability : weapon.abilities)
		out << ability << ", ";
	out << endl;
	return out;
}

ostream& operator<<(ostream& out, const Armor& armor)
{
	out << "Armor name: " << armor.name << endl;
	out << "Armor durability: " << armor.durability << endl;
	out << "Armor description: " << armor.description << endl;
	return out;
}

bool operator==(const Weapon& a, const Weapon& b)
{
	return a.damage == b.damage;
}

bool operator==(const Armor& a, const Armor& b)
{
	return a.durability == b.durability;
}

bool operator>(const Character& a, const Character& b)
{
	return a.maxHealth > b.maxHealth;
}

int main()
{
	array<Weapon, 2> weapons;
	weapons[0].damage = 1000.0f;
	weapons[0].name = "Excalibur";
	weapons[1].damage = 1.0f;
	weapons[1].name = "Wood sword";

	array<Armor, 2> armors;
	armors[0].durability = 1000.0f;
	armors[0].name = "Turle Shell";
	armors[0].description = "You are one with the tortoise";
	armors[1].durability = 1.0f;
	armors[1].name = "Broken Turle Shell";
	armors[1].description = "You are no longer one with the tortoise";

	size_t characterCount = 0Ui64;
	Character* characters;
	cout << "Welcome to character creation. Please enter the number of characters you wish to create (max 3)!" << endl;
	cin >> characterCount;

	// templated minimum function, press f12 to see for yourself --
	// _Right < _Left ? _Right : _Left
	characterCount = std::min(characterCount, 3Ui64);
	characters = new Character[characterCount];
	for (size_t i = 0; i < characterCount; i++)
	{
		Character& character = characters[i];//*(characters + i) <-- same as [i]
		cout << "What is the name of your character? " << endl;
		cin >> character.name;
		cout << "How much health does " << character.name << " have?" << endl;
		cin >> character.maxHealth;

		cout << endl << "Armor selection: " << endl;
		for (size_t weaponIndex = 0; weaponIndex < weapons.size(); weaponIndex++)
		{
			cout << "Press " << weaponIndex + 1 << " for " << weapons[weaponIndex].name << endl;
		}
		size_t weaponIndex = 0;
		cin >> weaponIndex;
		weaponIndex = std::max(1Ui64, std::min(weaponIndex, 2Ui64)) - 1;

		for (size_t armorIndex = 0; armorIndex < armors.size(); armorIndex++)
		{
			cout << "Press " << armorIndex + 1 << " for " << armors[armorIndex].name << endl;
		}
		size_t armorIndex = 0;
		cin >> armorIndex;
		armorIndex = std::max(1Ui64, std::min(armorIndex, 2Ui64)) - 1;

		character.weapon = &weapons[weaponIndex];
		character.armor = &armors[armorIndex];

		cout << character.name << " complete: " << endl << *character.weapon << *character.armor << endl;
	}

	size_t strongestIndex = 0;
	for (size_t i = 0; i < characterCount; i++)
	{
		if (characters[i] > characters[strongestIndex])
			strongestIndex = i;
	}
	cout << characters[strongestIndex].name << " is the strongest of them all!!!" << endl;

	delete[] characters;
	return 0;
}//*/
