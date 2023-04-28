#ifndef CAT_H
#define CAT_H
#include "Animal.h"
class Cat : public Animal
{
public:
   Cat();
   ~Cat();
   int MyCatNumber;
   static int NoOfCatCounts;
   string speak();
};
#endif