/*
#include <iostream>
using namespace std;

struct Insect
{
	int legs = 4;
	int antenna = 2;
	int wings = 2;
};

struct Bee : public Insect
{
	void Sting()
	{
		cout << "OUCHHH!!" << endl;
	}
};

// Inheritance can be thought of as a copy-paste from base to derived
struct InheritedGrassHopper : public Insect
{
	int grasshopperValue = 999;

	void Jump()
	{
		cout << "WHOOOOOOOOOOOHOOOOOOOOOOO" << endl;
	}
};

struct GrassHopper
{
	int legs = 4;
	int antenna = 2;
	int wings = 2;
	int grasshopperValue = 999;

	void Jump()
	{
		cout << "WHOOOOOOOOOOOHOOOOOOOOOOO" << endl;
	}
};

struct Transform
{
	float x;
	float y;

	void Update()
	{

	}
};

struct Sprite
{
	float r;
	float g;
	float b;

	void Update()
	{

	}

	int test;
};

struct Collider
{
	float width;
	float height;

	void Update()
	{

	}

	int test;
};

struct GameObject : public Transform, public Sprite, public Collider
{
	string name;
};

struct A
{
	A()
	{
		//cout << "Base class constructor (A) called" << endl;
	}

	A(int val) : secretValue(val)
	{
		//cout << "Overloaded base class constructor (A) called" << endl;
	}

	~A()
	{
		//cout << "Base class destructor (A) called" << endl;
	}

	void Output()
	{
		//cout << "AAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
	}

	virtual string Name()
	{
		return name;
	}

public:
	int value = 1;
	string name;

protected:
	int secretValue = 2;
};

struct B : public A
{
	string title;

	B()// : A() <-- happens automatically with derived default constructors
	{
		//cout << "Derived class constructor (B) called" << endl;
	}

	B(int val) : A(val)
	{
		//cout << "Overloaded base class constructor (B) called" << endl;
	}

	~B()
	{
		//cout << "Derived class destructor (B) called" << endl;
	}

	void Output()
	{
		cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" << endl;
	}

	string Name()
	{
		return title + " " + A::Name();
	}

	void BMethod()
	{

	}
};

// Overloading differs in signatures whereas overriding differs in object context!
//void Output()
//{
//	cout << "CCCCCCCCCCCC" << endl;
//}
//
//void Output(string text)
//{
//	cout << text << endl;
//}

int main()
{
	//GameObject object;
	//object.name = "Connor";
	//object.width = 60;
	//object.height = 40;
	//object.r = 255;
	//object.x = 100.0f;
	
	// Note that type-conversions ONLY work with pointers (overrides still work without pointers)
	//A a;
	//B b;
	//a.Output();
	//b.Output();
	//a.name = "Smiley";
	//b.name = "Smiley";
	//b.title = "Professor";
	//cout << a.Name() << endl;
	//cout << b.Name() << endl;

	A* a = new A;
	B* b = new B;
	a->name = "Connor";
	b->title = "Professor";
	b->name = "Smiley";
	//cout << a->Name() << endl;
	//cout << b->Name() << endl;

	// To be continued...
	A* b1 = b;
	cout << b1->Name() << endl;
	//A* b2 = new B;
	//b1->BMethod(); // invalid because we're treating the "B" as an "A".

	// Constructors can be overloaded just like functions.
	// Objects are destroyed in the opposite order they're created in!
	// Destructors cannot be overloaded
	//{
	//	B b(5);
	//	//b.value; // accessible since its part of A and its public
	//	//b.secretValue; // inaccessible since its protected
	//}

	// "Deadly Diamond (member or method conflict via multi-inheritance)"
	//object.test = 5;
	//object.Update();

	//InheritedGrassHopper ig;
	//GrassHopper gh;
	//Bee b;
	//b.Sting();
	//b.antenna;
	//
	//ig.grasshopperValue;
	//ig.antenna;
	//ig.Jump();
	//gh.Jump();

	return 0;
}//*/
