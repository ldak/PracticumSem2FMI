//
// Created by MILEN_PC on 24.5.2023 г..
//

#include "HelperFunctions.h"

int HelperFunctions::findLength(int a){
    int length = 0;
    while (a != 0) {
        a /= 10;
        length++;
    }
    return length;
}

int HelperFunctions::findLength(double a){
    int realPart = (int)a;
    double floatPart = a - realPart;
    int length = findLength(realPart);
    while(floatPart != (int)floatPart){
        floatPart *= 10;
        length++;
    }
    return length;
}