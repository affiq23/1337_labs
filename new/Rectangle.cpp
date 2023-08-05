#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(){
    width = 0;
    length = 0;
}

int Rectangle::getLength(){
    return length;
}

void Rectangle::setLength(int x){
    length = x;
}