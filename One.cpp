#include <iostream>
#include <string>
#include <array>
using namespace std;

struct GameObject
{
	virtual int NormalAttack() = 0;
};

struct Player : public GameObject
{
	string name;
	int health = 1000;
	virtual int SpecialAttack() = 0;
	virtual int NormalAttack() override { return 50; }
};

struct Enemy : public GameObject
{
	int health = 1000;
	virtual void TauntPlayer() = 0;
	virtual int NormalAttack() override { return 25; }
};

struct Knight : public Player
{
	static string specialName;
	float specialAmount = 100.0f;
	virtual int SpecialAttack() override { return specialAmount; }
};

string Knight::specialName = "Sword Dance";

struct Wizard : public Player
{
	static string specialName;
	float specialAmount = 200.0f;
	virtual int SpecialAttack() override { return specialAmount; }
};

string Wizard::specialName = "Avada Kadabra";

struct Orc : public Enemy
{
	static string species;
	array<string, 2> taunts{ "You're ugly.", "Go home and be a family man!" };
	virtual void TauntPlayer() override { cout << taunts[rand() % 2] << endl; }
};

string Orc::species = "ORC";

struct Undead : public Enemy
{
	static string species;
	array<string, 2> taunts{ "You'd be better of in the grave!", "You belong in a museum!" };
	virtual void TauntPlayer() override { cout << taunts[2 - (rand() % 2)] << endl; }
};

string Undead::species = "UNDEAD";

int main()
{
	Player* player = nullptr;
	Enemy* enemy = nullptr;
	char playerType;
	cout << "Press W for Wizard, K for knight" << endl;
	cin >> playerType;
	if (toupper(playerType) == 'W') player = new Wizard;
	else player = new Knight;
	int roll = rand() % 2;
	if (roll == 1) enemy = new Orc;
	else enemy = new Undead;
	player->name = "Connor";
	
	while (player->health > 0 || enemy->health > 0)
	{
		enemy->TauntPlayer();
		enemy->health -= player->NormalAttack();
		enemy->TauntPlayer();
		enemy->health -= player->SpecialAttack();
		player->health -= enemy->NormalAttack();
		player->health -= enemy->NormalAttack();
		enemy->health -= player->SpecialAttack();
		enemy->TauntPlayer();
		enemy->health -= player->SpecialAttack();
		// TODO -- actually do game design
	}
	cout << player->name << " wins!" << endl;

	return 0;
}