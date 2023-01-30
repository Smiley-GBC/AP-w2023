/*
#include <iostream>
#include <string>
#include <thread>
#include <memory>

using namespace std;

struct Test
{
	Test()
	{
		heapMemory = new int[1024 * 1024];
		cout << "Memory allocated at address " << heapMemory << endl;
	}

	//Test(const Test& t)
	//{
	//	heapMemory = new int[1024 * 1024];
	//	cout << "Memory copied from address " << t.heapMemory << 
	//		" to address " << heapMemory << endl;
	//	//for all memory of t, copy to current object in actuality
	//	//memcpy(heapMemory, t.heapMemory, sizeof(int) * 1024 * 1024);
	//}

	~Test()
	{
		cout << "Deleted address " << heapMemory << endl;
		delete[] heapMemory;
	}

	// Option 1 for avoiding "this->" keystrokes
	//void SetValue(int aValue)
	//{
	//	value = aValue;
	//}
	//int value;

	// Option 2 for avoiding "this->" keystrokes
	void SetValue(int value)
	{
		mValue = value;
	}

	int GetValue() const
	{
		return mValue;
	}

private:
	int mValue;

	int stackMemory[1024];
	int* heapMemory;
};

struct Game;

struct Enemy
{
	Enemy()
	{
		health = baseHealth + 25;
	}

	void SetHealth(int h)
	{
		health = baseHealth + h;
	}

	int Health()
	{
		return health;
	}

	static void SetType(string t)
	{
		type = t;
	}

	static void SetBaseHealth(int h)
	{
		baseHealth = h;
	}

	void SetName(string n)
	{
		name = n;
	}

	void SayName()
	{
		cout << "Hello I am " << name << " the " << type << endl;
	}

private:
	// Friend classes give entire class access to privates
	// (Both PrintEnemyType() and SecondFunction() can access private enemy variables).
	friend Game;
	friend void PrintEnemyName(Enemy enemy);
	// Friend functions can access privates as well. 

	string name;
	static string type;

	static int baseHealth;
	int health;
};

void PrintEnemyName(Enemy enemy)
{
	cout << "Enemy named " << enemy.name << endl;
}

struct Game
{
	void PrintEnemyType(Enemy enemy)
	{
		cout << "Enemy of type " << enemy.type << endl;
	}

	void SecondFunction(Enemy enemy)
	{
		cout << "Proof of concept: " << enemy.name << endl;
	}
};

string Enemy::type = "Orc";
int Enemy::baseHealth = 100;

int main()
{
	Game g;

	Enemy enemy1;
	Enemy enemy2;
	Enemy enemy3;
	Enemy enemy4;

	// Static values & methods apply to *all* objects of type Enemy.
	Enemy::SetBaseHealth(200);
	Enemy::SetType("Undead");
	// (All 4 enemies now have 200 base health and are now "Undead")

	// Individual objects still get their own health and name.
	enemy1.SetHealth(10);
	enemy2.SetHealth(20);
	enemy3.SetHealth(30);
	enemy4.SetHealth(40);

	enemy1.SetName("Connor");
	enemy2.SetName("Igor");
	enemy3.SetName("Fernando");
	enemy4.SetName("Adrian");

	enemy1.SayName();
	enemy2.SayName();
	enemy3.SayName();
	enemy4.SayName();

	cout << enemy1.Health() << endl;
	cout << enemy2.Health() << endl;
	cout << enemy3.Health() << endl;
	cout << enemy4.Health() << endl;

	g.PrintEnemyType(enemy1); // Friend class test
	PrintEnemyName(enemy1);   // Friend function test

	//Test test;
	//test.SetValue(10);
	//test.GetValue();

	// Methods are const-qualified to prevent bad access
	//const Test cTest;
	//cTest.SetValue(10);
	//cTest.GetValue();

	// DO NOT RUN THIS IF YOU VALUE YOUR PC!!!!
	//while (true)
	//{
	//	new int[1024 * 1024];
	//}

	// -> operator accesses members of a pointer to an object in a convenient way.
	//Test test;
	//Test* testPtr = &test;
	//test.value;
	//(*testPtr).value;
	//testPtr->value;

	// Correct memory management (deleting memory variable before it goes out of scope).
	//while (true)
	//{
	//	Test test;
	//	std::this_thread::sleep_for(chrono::seconds(1));
	//	//int* memory = new int[1024 * 1024];
	//	//cout << "Memory allocated at address " << memory << endl;
	//	//
	//	//std::this_thread::sleep_for(chrono::seconds(1));
	//	//
	//	//cout << "Deleted address " << memory << endl;
	//	//delete[] memory;
	//}

	return 0;
}
//*/