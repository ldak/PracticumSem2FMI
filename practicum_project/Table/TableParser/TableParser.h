//
// Created by MILEN_PC on 24.5.2023 г..
//

#ifndef PRACTUCUMSEM2_TABLEPARSER_H
#define PRACTUCUMSEM2_TABLEPARSER_H


#include "../../Utils/MyVector/MyVector.hpp"
#include "../Row/Row.h"
#include <iostream>
#include <sstream>

class TableParser {
private:
    MyVector<Row> rows;
    MyVector<int> alignments;
    void setFunctionCellRefs();
    void setAlignments();
public:

    friend std::istream &operator>>(std::istream &in, TableParser &tableParser);
    friend std::ostream &operator<<(std::ostream &out, TableParser &tableParser);

    WeakPtr<BasicCell> getCell(int i, int i1);
};

std::istream &operator>>(std::istream &in, TableParser &tableParser);
std::ostream &operator<<(std::ostream &out, TableParser &tableParser);

#endif //PRACTUCUMSEM2_TABLEPARSER_H
