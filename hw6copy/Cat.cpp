#include "Cat.h"

Cat::Cat()
{
   MyCatNumber = NoOfCatCounts;
   NoOfCatCounts++;
}


string Cat::speak()
{
   return "Name:" + Name + ",Age:" + Age + ",Weight:" + Weight + ",Breed:" + Breed + ",Color:" + Color+",Health:"+Health + ",Sound:" + Sound;
}

Cat::~Cat()
{
}
