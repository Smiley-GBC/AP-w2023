/*#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class Discipline { NONE, GAME_DEVELOPER, SOFTWARE_ENGINEER, ANIMATOR };
enum class Classification { FRESHMAN, SOPHMORE, JUNIOR, SENIOR };

// Base class
class Person
{
private:
	string name;
public:
	Person()
	{
		// cout << "Person Constructor Called!" << endl;
		setName("");
	}
	Person(const string& name)
	{
		setName(name);
	}
	~Person()
	{
		// cout << "Person Destructor Called!" << endl;
	}
	void setName(const string& name)
	{
		this->name = name;
	}
	string getName() const
	{
		return name;
	}
};

class Student : public Person
{
private:
	Discipline major;
	Person* advisor;
public:
	Student() : Person("DEFAULT")
	{
		setMajor(Discipline::NONE);
		setAdvisor(new Person("N/A"));
	}
	Student(const string& name, Discipline major, Person* advisor) : Person(name)
	{
		setMajor(major);
		setAdvisor(advisor);
	}
	~Student() {}
	void setMajor(Discipline major)
	{
		this->major = major;
	}
	Discipline getMajor() const
	{
		return major;
	}
	void setAdvisor(Person* advisor)
	{
		this->advisor = advisor;
	}
	Person* getAdvisor() const
	{
		return advisor;
	}
};

class Faculty : public Person
{
private:
	Discipline department;
public:
	Faculty() : Person("DEFAULT")
	{
		setDepartment(Discipline::NONE);
	}
	Faculty(const string& name, Discipline department) : Person(name)
	{
		setDepartment(department);
	}
	~Faculty() {}

	void setDepartment(Discipline department)
	{
		this->department = department;
	}
	Discipline getDepartment() const
	{
		return department;
	}
};

class TFaculty : public Faculty
{
private:
	string title;
public:
	TFaculty() : Faculty()
	{
		setTitle("_");
	}
	TFaculty(string fname, Discipline d, string title) : Faculty(fname, d)
	{
		setTitle(title);
	}
	void setTitle(string title)
	{
		this->title = title;
	}
	string getTitle() const
	{
		return title;
	}
	string getName() const
	{
		return getTitle() + " " + Person::getName();
	}
};

const string type[] = { "None", "Game Developer", "Software Engineer", "Animator" };

int main()
{
	a0.print();
	a1.print();

	Person* p = new Person("Connor Smiley");
	Student* s = new Student("Jane Doe", Discipline::GAME_DEVELOPER, p);
	Faculty* f = new Faculty("Bob Dole", Discipline::SOFTWARE_ENGINEER);
	TFaculty* t = new TFaculty("Lisa Simpson", Discipline::ANIMATOR, "Lord Commander of the Nights Watch");

	cout << "Hello, " << p->getName() << endl;
	cout << "Hello, " << s->getName() << ". You are a " << type[static_cast<int>(s->getMajor())] << endl;
	cout << "Hello, " << f->getName() << ". Your department is " << type[static_cast<int>(f->getDepartment())] << endl;
	cout << "Hello, " << t->getName() << ". Your department is " << type[static_cast<int>(t->getDepartment())] << endl;

	delete t;
	delete f;
	delete s;
	delete p;

	t = nullptr;
	f = nullptr;
	s = nullptr;
	p = nullptr;

	return 0;
}
*/