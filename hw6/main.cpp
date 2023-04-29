/*
    NAME: AFFIQ MOHAMMED
    DATE CREATED: 4/27/23
    NAME OF PROGRAM: HW6-CS1337-Affiq-Mohammed
    CHANGELOG:

    4/27/23 - started program, created Animal, Cat, Dog header files; included file guards since program is using multiple header files;
              wrote introduction methods for each object type; not sure how to read in csv data
    4/29/23 - started on writing main method and reading in data; tried to use substring but was too complicated, so switched to stringstream;


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

        getline(inputString, fileType, ',');
        getline(inputString, fileName, ',');
        getline(inputString, fileAge, ',');
        getline(inputString, fileWeight, ',');
        getline(inputString, fileBreed, ',');
        getline(inputString, fileColor, ',');
        getline(inputString, fileHealth, ',');
        getline(inputString, fileSound, ',');

        Animal *newAnimal;
        if (fileType == "cat")
        {
            newAnimal = new Cat();
        }
        else if (fileType == "dog")
        {
            newAnimal = new Dog();
        }
        else
        {
            newAnimal = new Animal();
        }

        // checking if data values from file are empty; setting them to UNKNOWN for cohesiveness
        if (fileName.empty())
        {
            fileName = "UNKNOWN";
        }
        if (fileAge.empty())
        {
            fileAge = "UNKNOWN";
        }
        if (fileWeight.empty())
        {
            fileWeight = "UNKNOWN";
        }
        if (fileBreed.empty())
        {
            fileBreed = "UNKNOWN";
        }
        if (fileColor.empty())
        {
            fileColor = "UNKNOWN";
        }
        if (fileHealth.empty())
        {
            fileHealth = "UNKNOWN";
        }
        if (fileSound.empty())
        {
            fileSound = "UNKNOWN";
        }

        transform(fileName.begin(), fileName.end(), fileName.begin(), ::toupper);
        transform(fileBreed.begin(), fileBreed.end(), fileBreed.begin(), ::toupper);
        transform(fileColor.begin(), fileColor.end(), fileColor.begin(), ::toupper);
        transform(fileHealth.begin(), fileHealth.end(), fileHealth.begin(), ::toupper);
        transform(fileSound.begin(), fileSound.end(), fileSound.begin(), ::toupper);

        newAnimal->name = fileName;
        newAnimal->age = fileAge;
        newAnimal->weight = fileWeight;
        newAnimal->breed = fileBreed;
        newAnimal->color = fileColor;
        newAnimal->health = fileHealth;
        newAnimal->sound = fileSound;

        animals.push_back(newAnimal);
        if (fileType == "cat")
        {
            cats.push_back((Cat *)newAnimal);
        }
        if (fileType == "dog")
        {
            dogs.push_back((Dog *)newAnimal);
        }

        line = " ";
    }
    inputFile.close();
}

void reportToFile()
{

   // int animalNum = Animal::myAnimalNumber;
    //int catNum = Cat::myCatNumber;
    //int dogNum = Dog::myDogNumber;

    outputFile.open("outputFile.txt");
    if (outputFile)
    {

       // outputFile << "REPORT 1 - TOTAL ANIMALS: " << Animal::myAnimalNumber << " | TOTAL CATS: " << Cat::myCatNumber << " | TOTAL DOGS: " << Dog::myDogNumber << endl;
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

    if (fileOpened)
    {
        reportToFile();
    }
    else
    {
        cout << "File could not be opened. Please try again." << endl;
    }
    return 0;
}