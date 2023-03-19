#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cassert>

using namespace std;

// Example 1 -- File Essentials
/*
int main()
{
	// When working with a file stream
	// 1. Declare the filestream object
	// 2. "Open" the filestream to a desired file
	// 3. Work on the file
	// 4. "Close" the filestream

	// 1.
	fstream inOutFile;
	string word;	// Used to read a word (or line) from the file.

	// 2.
	inOutFile.open("inout.txt");
	// Check if the filestream opened
	if (!inOutFile)
	{
		// Note that ofstream must be used to create files
		ofstream out("inout.txt");
		cout << "The file was not found." << endl;
		cout << "Now creating inout.txt" << endl;
		//return 1;
		// Just create the file instead of exiting the program!!!
	}

	// 3. 
	while (inOutFile >> word)
	{
		cout << word << endl;
	}

	// EOF (End of file) flag is set. Must clear to perform other operations
	inOutFile.clear();
	inOutFile << "Smiley" << endl;

	// 4.
	inOutFile.close();

	return 0;
}//*/

// Example 2 -- Stream formatting
/*
string dollarFormat(double amount);
 
int main()
{
	const int ROWS = 3, COLS = 2;

	// 2D Array
	double amount[ROWS][COLS] = {	184.5,	7, 
									59.15,	64.32, 
									7.29,	1289.1234 };

	// Format table of dollar amount to be right justified and column widith of 10
	cout << right;
	for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLS; column++)
		{
			cout << setw(10) << dollarFormat(amount[row][column]);
		}
		cout << endl;
	}

	return 0;
}

string dollarFormat(double amount)
{
	// Create ostringstream object
	ostringstream outStr;

	// Set up format information and write to outStr
	outStr << showpoint << fixed << setprecision(2);	// Forces 2 decimal places
	outStr << '$' << amount;	// '$' + amount

	return outStr.str();
}//*/

// Example 3 -- File Flags
/*
void showState(fstream&);

int main()
{
	fstream testFile("flags.dat", ios::out);
	if (testFile.fail())
	{
		cout << "Cannot open the file.\n";
		return 1;
	}

	// The file has opened successfully.
	int num = 10;
	cout << "Writing to the file.\n";
	testFile << num;
	showState(testFile);
	testFile.close();

	// Open the same file in input mode
	testFile.open("flags.dat", ios::in);
	if (testFile.fail())
	{
		cout << "Cannot open the file.\n";
	}
	// Read the file
	cout << "Reading from the file.\n";
	testFile >> num;
	showState(testFile);
	// Are any error bits true? (Besides good) -- Yes! EOF bit

	// Invalid read
	cout << "Forcing a bad read operation.\n";
	testFile >> num;
	showState(testFile);

	testFile.close();
	return 0;
}

void showState(fstream& file)
{
	cout << "File Status:\n";
	cout << "eof bit: " << file.eof() << endl;		// End of file bit
	cout << "fail bit: " << file.fail() << endl;	// Fail bit
	cout << "bad bit: " << file.bad() << endl;		// Bad bit
	cout << "good bit: " << file.good() << endl;	// Good bit
	file.clear();
}//*/

// Example 4 -- Words vs Lines
/*
int main()
{
	fstream file;
	
	file.open("address.txt", ios::in);
	if (file.fail())
	{
		cout << "File open error!" << endl;
		return 1;
	}

	// Read the file and print to the screen
	string input;
	do
	{
		//file >> input;		// Incorrect formatting
		getline(file, input);	// Correct formatting
		cout << input << endl;
	} while (!file.fail());

	file.close();
	return 0;
}//*/

// Example 5 -- Characters and Seeking
/*
int main()
{
	char ch;
	fstream ioFile("rewind.xyz", ios::out);
	// Files are treated as text unless specified otherwise.
	// Just cause Windows doesn't know what a .xyz file is doesn't matter!

	// Test Open
	if (!ioFile)
	{
		cout << "Error in trying to create the file";
		return 1;
	}

	// Write to the file
	ioFile << "I am very hungry." << endl << "No, you are hungry AND thirsty" << endl;
	ioFile.close();

	// Open the file
	ioFile.open("rewind.xyz", ios::in);
	if (!ioFile)
	{
		cout << "Error in opening the file";
		return 1;
	}

	// Read the file and print to the screen
	ioFile.get(ch);
	while (!ioFile.fail())
	{
		cout.put(ch);
		ioFile.get(ch);
		//std::this_thread::sleep_for(chrono::milliseconds(50));
		// use this if you want to look cool
	}

	// Rewind the file
	ioFile.clear();
	ioFile.seekg(10L, ios::beg);
	//ioFile.seekg(-30, ios::end);
	// Similar to beg, we can go backwards from the end.
	// In fact, we can go any direction we want, we just risk an EOF error!
	ioFile.seekg(-5L, ios::cur);

	// Read the file and print to the screen
	ioFile.get(ch);
	while (!ioFile.fail())
	{
		cout.put(ch);
		ioFile.get(ch);
	}

	ioFile.close();
	return 0;
}//*/

// Example 6 -- Simple Binary Dump
/*
int main()
{
	fstream file("Binary101.bin", ios::out | ios::binary);
	if (!file)
	{
		cout << "Error creating file.";
		return 1;
	}

	// Integer data to write to the binary file
	int outBuffer[] = { 1,2,3,4,5,6,7,8,9,10 };
	int count = sizeof(outBuffer) / sizeof(outBuffer[0]);	// Determines how many elements are in the array

	// Write the data and close the file
	cout << "Now writing the data to the file.\n";
	file.write(reinterpret_cast<char*>(outBuffer), sizeof(outBuffer));
	file.close();

	// READ IN THE BINARY FILE!
	file.open("Binary101.bin", ios::in | ios::binary);
	if (!file)
	{
		cout << "Error opening file.";
		return 1;
	}

	array<int, 10> inBuffer;
	cout << "Reading back the data.\n";
	file.read(reinterpret_cast<char*>(inBuffer.data()), sizeof(inBuffer));
	file.close();

	// Its best to load everything into memory FIRST, then modify stuff
	for (int i = 0; i < count; i++)
		inBuffer[i] = rand() % 10;
	std::sort(inBuffer.begin(), inBuffer.end());
	std::reverse(inBuffer.begin(), inBuffer.end());

	return 0;
}//*/

#define MAX_LENGTH 256
struct Entity
{
	char name[MAX_LENGTH];
	int health;
	int armor;
	float damage;
	float speed;
};

const int SZ_NAME = MAX_LENGTH;
const int SZ_HEALTH = sizeof(int);
const int SZ_ARMOR = sizeof(int);
const int SZ_DAMAGE = sizeof(float);
const int SZ_SPEED = sizeof(float);

// Example 7 -- Custom Type Memory Manipulation
/*
int main()
{
	Entity src, dst;
	sprintf_s(src.name, "Connor");
	src.health = 100;
	src.armor = 10;
	src.damage = 25.2f;
	src.speed = 7.5f;

	// Usually copying the entire object is enough
	//memcpy(&dst, &src, sizeof Entity);

	//Copying individual fields isn't worth it unless they're huge (like 100+ megabytes)!
	//memcpy(reinterpret_cast<char*>(&dst) + SZ_NAME, &src.health, SZ_HEALTH);

	return 0;
}//*/

// Write entity to file
void SerializeEntity(Entity& entity, size_t filePosition, fstream& file)
{
	assert(file.good());
	file.seekp(filePosition);
	file.write(reinterpret_cast<char*>(&entity), sizeof Entity);
}

// Read entity from file
void DeserializeEntity(Entity& entity, size_t filePosition, fstream& file)
{
	assert(file.good());
	file.seekg(filePosition);
	file.read(reinterpret_cast<char*>(&entity), sizeof Entity);
}

// Example 8 -- Single Object Serialization and Deserialization
/*
int main()
{
	Entity src, dst;
	sprintf_s(src.name, "Connor");
	src.health = 100;
	src.armor = 10;
	src.damage = 25.2f;
	src.speed = 7.5f;

	fstream file("Single Entity.bin", ios::out | ios::binary | ios::trunc);
	SerializeEntity(src, 0, file);
	file.close();

	file = fstream("Single Entity.bin", ios::in | ios::binary);
	DeserializeEntity(dst, 0, file);
	file.close();

	return 0;
}//*/

// Example 9 -- Multiple Objects Serialization and Deserialization
/*
int main()
{
	std::array<Entity, 10> src, dst;
	for (Entity& entity : src)
	{
		sprintf_s(entity.name, "Connor");
		entity.health = 100;
		entity.armor = 10;
		entity.damage = 25.2f;
		entity.speed = 7.5f;
	}

	// Instead of calling SerializeEntity, its more efficient to write everything at once (1 vs 10 file operations)
	fstream file("Multiple Entities.bin", ios::out | ios::binary | ios::trunc);
	file.write(reinterpret_cast<char*>(src.data()), sizeof src);
	file.flush();

	// Instead of calling DeserializeEntity, its more efficient to read everything at once (1 vs 10 file operations)
	file = fstream("Multiple Entities.bin", ios::in | ios::binary);
	file.read(reinterpret_cast<char*>(dst.data()), sizeof dst);
	file.close();

	return 0;
}//*/

// Write data to file
void Serialize(void* data, streamsize dataSize, streampos filePosition, fstream& file)
{
	assert(file.good());
	file.seekp(filePosition);
	file.write(reinterpret_cast<char*>(data), dataSize);
}

// Read data from file
void Deserialize(void* data, streamsize dataSize, streampos filePosition, fstream& file)
{
	assert(file.good());
	file.seekg(filePosition);
	file.read(reinterpret_cast<char*>(data), dataSize);
}

// Example 10 -- Generic Serialization and Deserialization (binary final boss)
/*
int main()
{
	Entity src, dst;
	sprintf_s(src.name, "Connor");
	src.health = 100;
	src.armor = 10;
	src.damage = 25.2f;
	src.speed = 7.5f;
	fstream file;

	file.open("Arbitrary.bin", ios::out | ios::binary | ios::trunc);
	Serialize(&src, sizeof Entity, 0, file);
	file.close();

	file.open("Arbitrary.bin", ios::in | ios::binary);
	Deserialize(&dst, sizeof Entity, 0, file);
	file.close();

	// We can read & write ANY attribute as long as the file position and data size is correct!
	// That being said, doing so is often overkill unless the data is extremely large.
	// For example, if an Entity was 100 megabytes but we only wanted a 10 kilobyte field, we'd need to do this.

	src.speed = 999.9f;
	file.open("Arbitrary.bin", ios::out | ios::binary | ios::trunc);
	Serialize(&src.speed, sizeof src.speed, sizeof Entity - sizeof src.speed, file);
	file.close();

	file.open("Arbitrary.bin", ios::in | ios::binary);
	Deserialize(&dst.speed, sizeof src.speed, sizeof Entity - sizeof src.speed, file);
	file.close();

	// P.S. The thing I meant to do in class (separate a string by spaces)
	std::string sentence = "Programming is fun";
	std::istringstream iss(sentence);
	std::string word;
	while (std::getline(iss, word, ' '))
		std::cout << word << std::endl;

	return 0;
}//*/

///////////////////////
// Additional Examples
///////////////////////

//Reading two strings in C vs C++
/*
#include <stdio.h>
#include <string.h>
int main() // C version
{
	FILE* file = nullptr;
	file = fopen("lines.txt", "r+");
	char word1[64];
	char word2[64];
	fscanf(file, "%s %s\n", word1);
	return 0;
}

int main() // C++ version
{
	ifstream file("lines.txt");
	string word1, word2;
	file >> word1 >> word2;
	return 0;
}//*/

// Using Text Instead of Binary for Objects (more work than binary cause we have to >> for each property)!
/*
int main()
{
	Entity src, dst;
	sprintf_s(src.name, "Connor");
	src.health = 100;
	src.armor = 10;
	src.damage = 25.2f;
	src.speed = 7.5f;

	fstream file("TextEntity.txt", ios::out);
	file << src.health << " "
		<< src.armor << " "
		<< src.damage << " "
		<< src.speed << endl;
	file.close();

	file = fstream("TextEntity.txt", ios::in);
	file >> dst.health
		>> dst.armor
		>> dst.damage
		>> dst.speed;
	file.close();

	return 0;
}//*/

// We can define a "macro" which replaces all instances of
// reinterpret_cast<char*> with something simpler like ByteCast to save those precious keystrokes!
//#define ByteCast reinterpret_cast<char*>
