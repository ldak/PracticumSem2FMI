//
// Created by MILEN_PC on 3/30/2023.
//

#ifndef PRACTUCUMSEM2_VALUE_H
#define PRACTUCUMSEM2_VALUE_H
#include "ConfigConst.h"
#include "HelperFunctions.h"


class Value {
private:
    char value[VALUE_LENGTH];
public:
    void setValue(const char* value);
    const char* getValue() const;
};


#endif //PRACTUCUMSEM2_VALUE_H
