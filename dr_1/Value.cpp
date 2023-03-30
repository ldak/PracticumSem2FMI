//
// Created by MILEN_PC on 3/30/2023.
//

#include "Value.h"

void Value::setValue(const char *value) {
    strcpyWithoutSpaces(this->value, value);
}

const char* Value::getValue() const {
    return this->value;
}
