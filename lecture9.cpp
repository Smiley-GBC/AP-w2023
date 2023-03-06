#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Example 1
///*
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
		// File was not found or opened correctly
		cout << "The file was not found." << endl;
		return 1;
	}

	// 3. 
	while (inOutFile >> word)
	{
		cout << word << endl;
	}

	// EOF (End of file) flag is set. Must clear to perform other operations
	inOutFile.clear();

	inOutFile << "Wallace" << endl;

	// 4.
	inOutFile.close();

	return 0;
}//*/

// Example 2
/*
string dollarFormat(double amount)
 
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

// Example 3
/*
void showState(fstream&);

int main()
{
	fstream testFile("stuff.dat", ios::out);
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
	testFile.open("stuff.dat", ios::in);
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

// Example 4
/*
int main()
{
	fstream file;
	string input;

	// Open the file
	file.open("wallace.txt", ios::in);
	if (file.fail())
	{
		cout << "File open error!" << endl;
		return 1;
	}

	// Read the file and print to the screen
	// file >> input;
	getline(file, input);	// Default delim character is '\n'
	while (!file.fail())
	{
		cout << input << endl;
		// file >> input;
		getline(file, input);
	}

	// Close the file
	file.close();

	return 0;
}//*/

// Example 5
/*
int main()
{
	char ch;
	fstream ioFile("rewind.txt", ios::out);

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
	ioFile.open("rewind.txt", ios::in);
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
	}

	// Rewind the file
	ioFile.clear();
	ioFile.seekg(10L, ios::beg);

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

// Example 6
/*
int main()
{
	fstream file("anything.wewant", ios::out | ios::binary);
	if (!file)
	{
		cout << "Error creating file.";
		return 1;
	}

	// Integer data to write to the binary file
	int buffer[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(buffer) / sizeof(buffer[0]);	// Determines how many elements are in the array

	// Write the data and close the file
	cout << "Now writing the data to the file.\n";
	file.write(reinterpret_cast<char*>(buffer), sizeof(buffer));
	file.close();

	// READ IN THE BINARY FILE!

	file.open("anything.wewant", ios::in | ios::binary);
	if (!file)
	{
		cout << "Error opening file.";
		return 1;
	}

	cout << "Reading back the data.\n";
	file.read(reinterpret_cast<char*>(buffer), sizeof(buffer));

	// Write out the array to the console
	for (int i = 0; i < size; i++)
	{
		cout << buffer[i] << " ";
	}

	file.close();

	return 0;
}
//*/