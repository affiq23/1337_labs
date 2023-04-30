#include "Animal.h" // to access Animal class
#include <iostream>

Animal::Animal()
{
    // default values for empty info in csv
    type = "UNKNOWN";
    name = "UNKNOWN";
    age = "UNKNOWN";
    weight = "UNKNOWN";
    breed = "UNKNOWN";
    color = "UNKNOWN";
    health = "UNKNOWN";
    sound = "UNKNOWN";
}

string Animal::introduction()
{ // returns member variables in string as introduction method

    return "I'm an animal! Name: " + name + " | Age: " + age + " | Weight: " + weight + " | Breed: " + breed + " | Color: " + color + " | Health: " + health + " | Sound: " + sound;
}

Animal::~Animal() // destructor
{
}