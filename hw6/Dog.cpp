#include "Dog.h"
#include <iostream>

Dog::Dog()
{
    initialDogNum = numDogs;
    numDogs++;
}


string Dog::introduction()
{ // uses member variables from Animal class
    return "I'm a dog! Name: " + name + " | Age: " + age + " | Weight: " + weight + " | Breed: " + breed + " | Color: " + color + " | Health: " + health + " | Sound: " + sound;
}

Dog::~Dog()
{
}