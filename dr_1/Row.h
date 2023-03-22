//
// Created by MILEN_PC on 3/22/2023.
//

#ifndef PRACTUCUMSEM2_ROW_H
#define PRACTUCUMSEM2_ROW_H
//#include "HelperFunctions.h"
#include <sstream>
#include "HelperFunctions.h"

class Row {
private:
    char values[10][20];
public:

    const char *getValue(int index) const;

    void setValue(char *string, int index);
    int getValueLength(int index);
};


#endif //PRACTUCUMSEM2_ROW_H
