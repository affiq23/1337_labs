#include "Cat.h"
#include <iostream>

Cat::Cat(){
   
}

string Cat::introduction(){ // uses member variables from Animal class
    return "I'm a cat! My name is " + name + ". I'm " + age + " years old. I weigh " + weight + " pounds. My breed is " + breed + ". My color is " + color + ". I'm in " + health + " health, and I make a " + sound + " sound!";
}

Cat::~Cat()
{
    
}