//
// Created by MILEN_PC on 3/22/2023.
//

#ifndef PRACTUCUMSEM2_COLLUMN_H
#define PRACTUCUMSEM2_COLLUMN_H

#include "ConfigConst.h"
#include <fstream>
#include "HelperFunctions.h"


class Column {
private:
    char name[VALUE_LENGTH]{};
    Alignment alignment = Alignment::LEFT;
    int columnSize = 0;
public:
    Column();
    explicit Column(const char* name);
    void setAlignment(Alignment align);
    void setAlignment(const char* align);
    void setName(const char* name);
    const char* getName() const;
    void setColumnSize(int columnSize);

    void printColumn() const;
    void printColumn(std::ofstream& ofs) const;
    void printValueAligned(const char* value) const;
    void printValueAligned(const char* value, std::ofstream& ofs) const;

    void printAlignment(std::ofstream &ofs) const;

    int getColumnSize() const;
};


#endif //PRACTUCUMSEM2_COLLUMN_H
