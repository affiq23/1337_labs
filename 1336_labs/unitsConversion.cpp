//
//  main.cpp
//  unitsConversion
//
//  Created by Affiq Mohammed on 10/26/22.
//

#include <iostream>
#include <iomanip>


using namespace std;

double inchesToCentimeters(double in){
    double cM = in * 2.54;
    return cM;
}

double centimetersToInches(double cM){
    double in = cM / 2.54;
    return in;
}

double inchesToFeet(double in){
    double ft = in / 12;
    return ft;
}

double feetToInches(double ft){
    double in = ft * 12;
    return in;
}


int main() {
    char operation;
    double input;
    std::cin >> operation;
    std::cin >> input;
    std::cout << std::fixed << std::setprecision(2);

    switch(operation) {
        case 'c':
            cout << inchesToCentimeters(input) << endl;
            break;
        case 'C':
            cout << inchesToCentimeters(feetToInches(input)) << endl;
            break;
        case 'f':
           cout << inchesToFeet(input) << endl;
            break;
        case 'F':
            cout <<  inchesToFeet(centimetersToInches(input)) << endl;
            break;
        case 'i':
            cout << feetToInches(input) << endl;
            break;
        case 'I':
            cout << centimetersToInches(input) << endl;
            break;
        default:
            std::cout << "Unknown operation " << operation << std::endl;
    }
    return 0;
}
