//
// Created by MILEN_PC on 24.5.2023 г..
//

#include "HelperFunctions.h"
#include <iostream>
#include <cmath>

int HelperFunctions::findLength(int a){
    int length = a <= 0 ? 1 : 0;
    while (a != 0) {
        a /= 10;
        length++;
    }

    return length;
}

int HelperFunctions::findLength(double a){
    if (a == (int)a)
        return findLength((int)a);

    int length = a < 0 ? 1 : 0;
    a = std::abs(a);
    long long precision = std::cout.precision();
    //real part without last digit
    int realPart = ((int)a)/10;
    if (realPart != 0)
        length += findLength(realPart);
    //floating part with real part first digit
    double floatPart = a - realPart*10;
    //using stream precision to round
    int roundedFloatPart = round(floatPart * pow(10, precision));
    //ending 0 are not printed
    while(roundedFloatPart % 10 == 0)
        roundedFloatPart /=10;

    int floatPartLength = findLength(roundedFloatPart);
    length += floatPartLength;

    // if we have float part
    if(floatPartLength > 1)
        //plus 1 for '.' symbol
        length += 1;


    return length;
}