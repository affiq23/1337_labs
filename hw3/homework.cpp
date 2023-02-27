/*
 - 2/22/23:     Started program
                Wrote generateVector() function, which takes input from user and creates vector
                Have to implement boundary check if largestNum is greater than 20
- 2/27/23:      Wrote showVector function to display contents and vector and size
                Created new copy of vectorOne
                Was able to sort vectorOne (original vector) using sort algorithm and display it
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(string msg)
{
    cout << "SHOWING: " << msg << endl;
}

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

vector<int> copyVector(vector<int> orgVector)
{
    vector<int> vectorTwo = orgVector;
    return vectorTwo;
}

int main()
{

    vector<int> vectorOne = generateVector(); //creates vector

    vector <int> vectorTwo = copyVector(vectorOne); //creates copy of original vector
    showVector(vectorOne, "print vector unsorted");
    
    sort(vectorOne.begin(), vectorOne.end());
    showVector(vectorOne, "print vector sorted");
    showVector(vectorTwo, "print vector new");

    return 0;
}