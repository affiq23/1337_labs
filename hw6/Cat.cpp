#include "Cat.h"
#include <iostream>

Cat::Cat()
{
    initialCatNum = numCats;
    numCats++;
    sound = "MEOW";
}

string Cat::introduction()
{ // uses member variables from Animal class
        return "I'm a cat! Name: " + name + " | Age: " + age + " | Weight: " + weight + " | Breed: " + breed + " | Color: " + color + " | Health: " + health + " | Sound: " + sound;
}


Cat::~Cat()
{
}