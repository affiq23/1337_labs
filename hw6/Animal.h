#ifndef ANIMAL_H // file guards to make sure header file is only used once
#define ANIMAL_H
#include <iostream>
using namespace std;

class Animal
{

public:
    Animal(); // constructor
    string type;
    string name;
    string age;
    string weight;
    string breed;
    string color;
    string health;
    string sound;
    string introduction();
    ~Animal(); // destructor
};
#endif

Employee* empPtr;
int x;
cin >> x;

if(x > 10){
    empPtr = newEmployee;
    Employee e1, e2, e3;
    Employee e4 = e1;
    Employee* ePtr = new Employee[10];
    printWage(e1);
}

delete empPtr;
cout << "exiting";