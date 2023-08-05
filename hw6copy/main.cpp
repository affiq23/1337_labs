#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "Dog.h"
#include "Cat.h"
#include "Animal.h"
#include "Animal.cpp"
#include "Dog.cpp"
#include "Cat.cpp"
using namespace std;

int Dog::NoOfDogCounts = 0;
int Cat::NoOfCatCounts = 0;
vector<Animal *> animals;
vector<Dog *> dogs;
vector<Cat *> cats;
ifstream csvFile;
ofstream reportFile;

void readDataIn(string fileName)
{
    string line;
    string name;
    string atype;
    string age;
    string weight;
    string color;
    string sound;
    string health;
    string breed;

    csvFile.open(fileName);
    if (!csvFile)
    {
        cout << "Error in file reading" << endl;
    }
    getline(csvFile, line); // skip header line
    getline(csvFile, line); // Get the frist line from the file, if any.
    while (csvFile)
    { // Continue if the line was sucessfully read.
        // Process the line.
        atype = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        name = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        age = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        weight = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        breed = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        color = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        health = line.substr(0, line.find(','));
        sound = line.erase(0, line.find(',') + 1);

        Animal *newAnimal;
        if (atype == "cat")
        {
            newAnimal = new Cat();
        }
        else if (atype == "dog")
        {
            newAnimal = new Dog();
        }
        else
        {
            newAnimal = new Animal();
        }

        
        newAnimal->Age = age;
        newAnimal->Breed = breed;
        newAnimal->Color = color;
        newAnimal->Health = health;
        newAnimal->Name = name;
        newAnimal->Sound = sound;
        newAnimal->Type = atype;
        newAnimal->Weight = weight;

        animals.push_back(newAnimal);
        if (atype == "cat")
        {
            cats.push_back((Cat *)newAnimal);
        }
        else if (atype == "dog")
        {
            dogs.push_back((Dog *)newAnimal);
        }
        getline(csvFile, line);
    }
    csvFile.close();
}

void printToFile()
{
    reportFile.open("reportFile.txt");
    if (reportFile)
    {
        reportFile << "Total Animals created:" << animals.size() << ",Total cats created:" << cats.size() << ",Total dogs created:" << dogs.size() << endl;
        reportFile << "Animals" << endl;

        for (int i = 0; i < animals.size(); i++)
        {
            reportFile << animals[i]->Animal::speak() << endl;
        }

        reportFile << "Cats" << endl;
        for (int i = 0; i < cats.size(); i++)
        {
            reportFile << cats[i]->Cat::speak() << endl;
        }

        reportFile << "Dogs" << endl;
        for (int i = 0; i < dogs.size(); i++)
        {
            reportFile << dogs[i]->Dog::speak() << endl;
        }
        reportFile.close();
    }
}

void printToConsole()
{
    cout << "Total Animals created:" << animals.size() << ", Total cats created:" << cats.size() << ",Total dogs created:" << dogs.size() << endl;
    cout << "Animals" << endl;
    for (int i = 0; i < animals.size(); i++)
    {
        cout << animals[i]->Animal::speak() << endl;
    }

    cout << "Cats" << endl;
    for (int i = 0; i < cats.size(); i++)
    {
        cout << cats[i]->Cat::speak() << endl;
    }

    cout << "Dogs" << endl;
    for (int i = 0; i < dogs.size(); i++)
    {
        cout << dogs[i]->Dog::speak() << endl;
    }
}

int main()
{

    readDataIn("animalFile.csv");
    printToConsole();
    printToFile();

    return 0;
}