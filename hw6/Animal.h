#ifndef ANIMAL_H // file guards to make sure header file is only used once
#define ANIMAL_H
#include <iostream>
using namespace std;

class Animal
{
    public:
        Animal(); // constructor
        string type;
        string name;
        string age;
        string weight;
        string breed;
        string color;
        string health;
        string sound;
        int nbrAnimals; // number of dog objects created
        static int myAnimalNumber; // counting objects created
        string introduction();
        ~Animal(); //destructor

};
#endif