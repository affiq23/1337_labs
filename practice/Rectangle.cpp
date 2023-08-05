#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double length;

public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};

// setWidth assigns a value to the width member
void Rectangle::setWidth(double w)
{
    width = w;
}

// setLength assigns a value to the length member
void Rectangle::setLength(double len)
{
    length = len;
}

// getWidth returns the value in the width member
double Rectangle::getWidth() const
{
    return width;
}

// getLength returns the value in the length member
double Rectangle::getLength() const
{
    return length;
}

// getArea returns the product of width times length
double Rectangle::getArea() const
{
    return length * width;
}

int main()
{
    Rectangle box;     // define an instance of the Rectangle class
    double rectWidth;  // local variable for width
    double rectLength; // local variable for length

    // get the width and length from the user
    cout << "This program will calculate the area of a\n";
    cout << "rectangle. What is the width? ";
    cin >> rectWidth;
    cout << "What is the length? ";
    cin >> rectLength;

    // store the length and width in the box object
    box.setWidth(rectWidth);
    box.setLength(rectLength);

    // display the rectangle's data
    cout << "Here is the rectangle's data: \n";
    cout << "width: " << box.getWidth() << endl;
    cout << "length: " << box.getLength() << endl;
    cout << "area: " << box.getArea() << endl;
    
    cout << endl;

    Rectangle* pRect = nullptr;
    Rectangle otherR;

    pRect = &otherR;
    pRect->setLength(10);
    cout << pRect->getLength();
    return 0;
}