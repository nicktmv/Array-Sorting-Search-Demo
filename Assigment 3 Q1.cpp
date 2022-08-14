#include <iostream>
#include <fstream>
#include "SelectionSort.h"
using namespace std;

//	Nick Timaskovs - K00260158
//	Assigment 3 - Q1


//  Function prototypes
void PrintArray(string arr[], int size);
int binarySearch(string names[], int size, string value);

int main()
{
    const int NUM_NAMES = 14;
    //Array of names
    string names[NUM_NAMES] = { "Jon", "Dot", "Eva", "Roy", "Guy", "Jan", "Tom", "Jim", "Ann", "Kim", "Ron", "Tim", "Kay", "Amy" }; 
    int size = sizeof(names) / sizeof(names[14]);
    cout << "Unsorted Array: " << endl;
    PrintArray(names, size);

    cout << endl << endl;
    cout << "Sorted array: " << endl;

    SelectionSort(names, size); // I used selection sort in this example
    PrintArray(names, size);
    cout << "" << endl;

    // Variables 
    string studentName;
    int results;

    // Prompt user to input to enter a name for the algorithm to search 
    cout << "Please enter a name to search: ";
    cin>>studentName;

    // Search for name
    results = binarySearch(names, NUM_NAMES, studentName);

    // If results contains -1 the name was not found.
    if (results == -1)
        cout <<studentName<< " does not exist in the array!\n";
    else
    {
        // Otherwise results contains the subscript of
        // the specified students ID in the array.
        cout << "That name is found at element " << results;
        cout << " in the array.\n";
    }

    system("PAUSE");
}

void PrintArray(string arr[], int size)
{
    for (int i = 0; i < size; i++) // simple print function which loops through the array
        cout << arr[i] << " ";
    cout << endl;
}

int binarySearch(string names[], int size, string value)
{
    int first = 0,              
        last = size - 1,        
        middle,                 
        position = -1;          
    bool moreToSearch = false;  // More to search flag

    while (!moreToSearch && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point of array
        if (names[middle] == value)      
        {
            moreToSearch = true;
            position = middle;
        }
        else if (names[middle] > value)  // If value is in first half
            last = middle - 1;
        else
            first = middle + 1;          // If value is in second half
    }
    return position;
}






