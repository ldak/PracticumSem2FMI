//
// Created by MILEN_PC on 24.5.2023 г..
//

#ifndef PRACTUCUMSEM2_TABLEPARSER_H
#define PRACTUCUMSEM2_TABLEPARSER_H


#include "../../Utils/MyVector/MyVector.hpp"
#include "../Row/Row.h"

class TableParser {
private:
    MyVector<Row> rows;
public:
    void print();

};


#endif //PRACTUCUMSEM2_TABLEPARSER_H
