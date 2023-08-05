#include <iostream>
#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle
{
    private:
        int length;
        int width;
    public:
        Rectangle();
        int getLength();
        void setLength(int x);
};
#endif // !RECTANGLE_H