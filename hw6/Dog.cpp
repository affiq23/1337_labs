#include "Dog.h"

Dog::Dog()
{
   MyDogNumber = NoOfDogCounts;
   NoOfDogCounts++;
}
string Dog::speak()
{
   return "Name:" + Name + ",Age:" + Age + ",Weight:" + Weight + ",Breed:" + Breed + ",Color:" + Color + ",Health:" + Health + ",Sound:" + Sound;
}

Dog::~Dog()
{
}