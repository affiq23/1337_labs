#ifndef DOG_H // file guards to make sure header file is only used once
#define DOG_H
#include <iostream>
#include "Animal.h"

class Dog : public Animal
{

public:
    Dog(); // constructor
    int initialDogNum;
    static int numDogs;
    string introduction();
    ~Dog(); // destructor
};
#endif