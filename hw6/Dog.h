#ifndef DOG_H // file guards to make sure header file is only used once
#define DOG_H
#include <iostream>
#include "Animal.h"

class Dog : public Animal
{
    public:
        Dog(); // constructor
        string introduction();
        ~Dog(); //destructor

};
#endif