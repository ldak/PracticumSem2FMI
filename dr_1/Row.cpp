//
// Created by MILEN_PC on 3/22/2023.
//

#include "Row.h"

const char *Row::getValue(int index) const {
    return this->values[index];
}

void Row::setValue(char *string, int index) {
    strcpyWithoutSpaces(this->values[index], string);
}

int Row::getValueLength(int index) {
    return strLength(this->values[index]);
}



