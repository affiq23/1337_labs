#ifndef CAT_H // file guards to make sure header file is only used once
#define CAT_H
#include <iostream>
#include "Animal.h"

class Cat : public Animal
{
public:
    Cat(); // constructor
    int initialCatNum;
    static int numCats;
    string introduction();
    ~Cat(); // destructor
};
#endif