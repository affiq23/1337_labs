#include "Animal.h"

Animal::Animal()
{
}


Animal::~Animal()
{
}

string Animal::speak()
{
   return "Name: " + Name + ", Age: " + Age + ", Weight: " + Weight + ", Breed: " + Breed + ", Color: " + Color + ", Health: " + Health + ", Sound: " + Sound;
}
