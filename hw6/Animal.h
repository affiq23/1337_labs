#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;
class Animal
{
   public:
   Animal();
   ~Animal();
   string speak();
   string Type;
   string Name;
   string Age;
   string Weight;
   string Breed;
   string Color;
   string Health;
   string Sound;
};
#endif