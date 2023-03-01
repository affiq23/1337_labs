/*
 - 2/22/23:     Started program
                Wrote generateVector() function, which takes input from user and creates vector
                Have to implement boundary check if largestNum is greater than 20

- 2/27/23:      Wrote showVector function to display contents and vector and size
                Created new copy of vectorOne
                Was able to sort vectorOne (original vector) using sort algorithm and display it

- 3/1/23:       Implementing binary search function to search vector
                Was able to call it and print out where position of number user asked for is
                Vector is returning similar numbers ever time; might be a problem to look into
                Added loop to ask user for multiple numbers
                Final thing left is to check how many times a number occurs in the vector

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// functionality to check if functions are working as intended
void show(string msg)
{
    cout << "SHOWING: " << msg << endl;
}

// function that generates new vector when called
vector<int> generateVector()
{
    int sizeVec;
    int largestNum;
    vector<int> vecOne;

    show("Called generateVector");
    cout << "What size vector do you want?" << endl;
    cin >> sizeVec;
    cout << "What is the largest value number you want generated?" << endl;
    cin >> largestNum;

    while (largestNum > 20)
    {
        if (largestNum > 20)
        {
            cout << "Sorry. Pick another number less than 20. ";
            cin >> largestNum;
        }
    }

    for (int i = 0; i < sizeVec; i++)
    {
        int j = (rand() % largestNum) + 1;
        vecOne.push_back(j);
    }
    show("Populated generateVector");

    return vecOne;
}

// function that prints contents of vector passed in to console
void showVector(vector<int> vector, string msg)
{
    cout << msg << endl;
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << "| ";
    }
    cout << endl;
    cout << "Vector size: " << vector.size() << endl;
    cout << "Vector capacity: " << vector.capacity() << endl;
}

// function that copies vector passed in into a new vector
vector<int> copyVector(vector<int> orgVector)
{
    vector<int> vectorTwo = orgVector;
    return vectorTwo;
}

// function that performs a binary search on vector passed in
int binarySearch(vector<int> vec, int size, int value)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {

        mid = (low + high) / 2;

        if (value == vec.at(mid))
        {
            return mid;
        }
        else if (value > vec.at(mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// function that prints out if and where position of number was
void displayBinarySearch(int position, int searchValue)
{
    if (position != -1)
    {
        cout << "The number " << searchValue << " was found at position " << position << ".";
    }
    else
    {
        cout << "The number could not be found.";
    }
}

int main()
{

    int value;
    bool flag = true;

    vector<int> vectorOne = generateVector(); // creates vector

    vector<int> vectorTwo = copyVector(vectorOne); // creates copy of original vector
    // showVector(vectorOne, "print vector unsorted");

    sort(vectorOne.begin(), vectorOne.end()); // sorts vector
    showVector(vectorOne, "print vector sorted");
    // showVector(vectorTwo, "print vector new");
    cout << endl;

    for (int i = 0; i < 5; i++) // looping to ask the user to check multiple numbers
    {

        cout << "Enter some number you wish to search for in the original vector: " << endl; // asking user for input
        cin >> value;

        int position = binarySearch(vectorOne, vectorOne.size(), value); // calling binarySearch function
        displayBinarySearch(position, value);                            // checking if position exists and printing it out
        cout << endl;
    }

    return 0;
}