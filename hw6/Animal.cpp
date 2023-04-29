#include "Animal.h" // to access Animal class
#include <iostream>

Animal::Animal()
{
    myAnimalNumber = nbrAnimals;
    myAnimalNumber++;
}

string Animal::introduction()
{ // returns member variables in string as introduction method
    return "My name is " + name + ". I'm " + age + " years old. I weigh " + weight + " pounds. My breed is " + breed + ". My color is " + color + ". I'm in " + health + " health , and I make a " + sound + " sound!";
}

Animal::~Animal() // destructor
{
}