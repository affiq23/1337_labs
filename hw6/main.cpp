/*
    NAME: AFFIQ MOHAMMED
    DATE CREATED: 4/27/23
    NAME OF PROGRAM: HW6-CS1337-Affiq-Mohammed
    CHANGELOG:

    4/27/23 - started program, created Animal, Cat, Dog header files, all are basically the same; included file guards since program is using multiple header files;
              wrote introduction methods for each object type; not sure how to read in csv data; wrote class implementations, all pretty much the same with introduction method

    4/29/23 - started on writing main method and reading in data; tried to use substring but was too complicated, so switched to stringstream;
              not sure how to implement static variable to keep track of objects

    4/30/23 - finished implementing main part of program; used vector size to calculate how many animals, wasn't working when trying to do it with member variables;
              formatting issue with the size variable; doesn't print when value is unknown, I think it's an issue with stringstream
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Animal.cpp"
#include "Cat.cpp"
#include "Dog.cpp"
using namespace std;

bool fileOpened = true;
vector<Animal *> animals;
vector<Cat *> cats;
vector<Dog *> dogs;
ifstream inputFile;
ofstream outputFile;
int Cat::numCats = 0;
int Dog::numDogs = 0;


// to parse text from CSV file and add data to member variables of objects
void readInputData(string file)
{

    inputFile.open(file);
    if (!inputFile)
    {
        fileOpened = false; // checking if file is open properly
    }
    string line = "";

    getline(inputFile, line); // skips first line
    while (getline(inputFile, line))
    {
        // strings to be filled as CSV file is parsed
        string fileType;
        string fileName;
        string fileAge;
        string fileWeight;
        string fileBreed;
        string fileColor;
        string fileHealth;
        string fileSound;
        string temp;

        stringstream inputString(line); // to read the line

        // reading in file data seperated by comma
        getline(inputString, fileType, ',');
        getline(inputString, fileName, ',');
        getline(inputString, fileAge, ',');
        getline(inputString, fileWeight, ',');
        getline(inputString, fileBreed, ',');
        getline(inputString, fileColor, ',');
        getline(inputString, fileHealth, ',');
        getline(inputString, fileSound, ' ');

        // creating new Animal; checking if it is a Cat or Dog object
        Animal *newAnimal;
        if (fileType == "cat")
        {
            newAnimal = new Cat();
            Cat::numCats++;
        }
        else if (fileType == "dog")
        {
            newAnimal = new Dog();
            Dog::numDogs++;
        }
        else
        {
            newAnimal = new Animal();
        }

        // capitalizing all data values
        transform(fileName.begin(), fileName.end(), fileName.begin(), ::toupper);
        transform(fileBreed.begin(), fileBreed.end(), fileBreed.begin(), ::toupper);
        transform(fileColor.begin(), fileColor.end(), fileColor.begin(), ::toupper);
        transform(fileHealth.begin(), fileHealth.end(), fileHealth.begin(), ::toupper);
        transform(fileSound.begin(), fileSound.end(), fileSound.begin(), ::toupper);

        // checking if data values from file are empty before inserting into member variables
        if (!fileName.empty())
        {
            newAnimal->name = fileName;
        }
        if (!fileAge.empty())
        {
            newAnimal->age = fileAge;
        }
        if (!fileWeight.empty())
        {
            newAnimal->weight = fileWeight;
        }
        if (!fileBreed.empty())
        {
            newAnimal->breed = fileBreed;
        }
        if (!fileColor.empty())
        {
            newAnimal->color = fileColor;
        }
        if (!fileHealth.empty())
        {
            newAnimal->health = fileHealth;
        }
        if (!fileSound.empty())
        {
            newAnimal->sound = fileSound;
        }

        // adding new Animal object to animals vector
        animals.push_back(newAnimal);
        if (fileType == "cat") // checking if it also belongs in cats or dogs vector
        {
            cats.push_back((Cat *)newAnimal);
        }
        if (fileType == "dog")
        {
            dogs.push_back((Dog *)newAnimal);
        }
    }
    inputFile.close();
}

// prints data to console
void printToConsole()
{
    int others = (animals.size() - (cats.size() + dogs.size())); // to calculate how many other animals there are

    cout << "REPORT 1 - TOTAL ANIMALS: " << animals.size() << " | TOTAL CATS: " << cats.size() << " | TOTAL DOGS: " << dogs.size() << " | OTHER ANIMALS: " << others << endl;
    cout << endl;

    cout << "REPORT 2 - ANIMAL REPORT: " << endl;
    for (int i = 0; i < animals.size(); i++) // printing every animal in the vector
    {
        cout << animals[i]->Animal::introduction() << endl; // member variables are now updated in introduction method; pointing to method and printing that
    }
    cout << endl;

    cout << "REPORT 3 - CAT REPORT: " << endl;
    for (int i = 0; i < cats.size(); i++)
    {
        cout << cats[i]->Cat::introduction() << endl; // same for Cat specific method
    }
    cout << endl;

    cout << "REPORT 4 - DOG REPORT: " << endl;
    for (int i = 0; i < dogs.size(); i++)
    {
        cout << dogs[i]->Dog::introduction() << endl; // same for Dog specific method
    }
}

// exact same process as printToConsole method, just printing to text file
void reportToFile()
{

    int others = (animals.size() - (cats.size() + dogs.size()));

    outputFile.open("outputFile.txt");
    if (outputFile)
    {

        outputFile << "REPORT 1 - TOTAL ANIMALS: " << animals.size() << " | TOTAL CATS: " << cats.size() << " | TOTAL DOGS: " << dogs.size() << " | OTHER ANIMALS: " << others << endl;
        outputFile << endl;

        outputFile << "REPORT 2 - ANIMAL REPORT: " << endl;
        for (int i = 0; i < animals.size(); i++)
        {
            outputFile << animals[i]->Animal::introduction() << endl;
        }
        outputFile << endl;

        outputFile << "REPORT 3 - CAT REPORT: " << endl;
        for (int i = 0; i < cats.size(); i++)
        {
            outputFile << cats[i]->Cat::introduction() << endl;
        }
        outputFile << endl;

        outputFile << "REPORT 4 - DOG REPORT: " << endl;
        for (int i = 0; i < dogs.size(); i++)
        {
            outputFile << dogs[i]->Dog::introduction() << endl;
        }
        outputFile.close();
    }
}

int main()
{
    readInputData("animalFile.csv");
    if (fileOpened) // checking if file is able to be opened
    {
        reportToFile();
        printToConsole();
    }
    else
    {
        cout << "File could not be opened. Please try again." << endl;
    }

    return 0;
}