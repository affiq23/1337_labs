//
//  main.cpp
//  countEvens
//
//  Created by Affiq Mohammed on 10/26/22.
//

#include <iostream>
#include <iomanip>
using namespace std;

    double multiplyThem(double first, double second) {
       return first * second;
    }

    double multiplyThem(double first, double second, double third = 1.0) {
       return first * second * third;
   }

    int main() {
       double result = multiplyThem(5.0, 6.0);
   }
