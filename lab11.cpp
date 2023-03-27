/*
#include <iostream>
#include <string>
using namespace std;

// Taken from https://www.geeksforgeeks.org/insertion-sort/
template<typename T>
void Sort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

template<typename T>
int LinearSearch(const T arr[], int first, int last, T value)
{
    // Did not find value in array
    if (first >= last)
    {
        return -1;
    }
    // Found the value!
    if (arr[first] == value)
    {
        return first;
    }
    // Increment first and keep searching...
    else
    {
        return LinearSearch(arr, ++first, last, value);
    }
}

template<typename T>
int BinarySearch(const T arr[], int first, int last, T value)
{
    int middle; // Mid point of search
    // Base case
    if (first > last)
    {
        return -1; // Did not find value in array
    }
    middle = (first + last) / 2;
    if (arr[middle] == value)
    {
        // We found the value
        return middle;
    }
    // Value not found
    if (arr[middle] < value)
    {
        // Upper half
        return BinarySearch(arr, middle + 1, last, value);
    }
    else
    {
        // Lower half
        return BinarySearch(arr, first, middle - 1, value);
    }
}

template<typename T>
void Print(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

struct Dog
{
    float number;
};

bool operator>(const Dog& a, const Dog& b)
{
    return a.number > b.number;
}

bool operator<(const Dog& a, const Dog& b)
{
    return a.number < b.number;
}

bool operator==(const Dog& a, const Dog& b)
{
    return a.number == b.number;
}

ostream& operator<<(ostream& out, const Dog& dog)
{
    out << dog.number;
    return out;
}

string Reverse(string str)
{
    // reverse here
    return str;
}

int main()
{
    int arr[] = { 1337, 69, 9000, 420, 666 };
    int count = sizeof(arr) / sizeof(arr[0]);

    Dog dogs[] = { 1337, 69, 9000, 420, 666 };
    Dog bestDog = dogs[LinearSearch(dogs, 0, 5, { 9000 })];

    // Remember, we must sort our array in order to binary search!
    // (Be careful when you sort as sorting is more expensive than a linear search in this case)
    Sort(dogs, 5);
    Dog SecondBestDog = dogs[BinarySearch(dogs, 0, 5, { 420 })];

    //Sort(arr, count);
    //Sort(dogs, count);
    //Print(dogs, count);
    //Print(arr, count);

    //cout << "Please enter a string" << endl;
    //string text;
    //getline(cin, text);
    string text = "Dog";
    text = Reverse(text);

    return 0;
}//*/
