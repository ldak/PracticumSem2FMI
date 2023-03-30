//
// Created by MILEN_PC on 3/22/2023.
//

#ifndef PRACTUCUMSEM2_COLLUMN_H
#define PRACTUCUMSEM2_COLLUMN_H

#include "ConfigConst.h"
#include <fstream>
#include "HelperFunctions.h"
#include "Value.h"


class Column {
private:
    Value name{};
    Value values[ROW_COUNT]{};
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

    void printColumnName() const;
    void printColumnValue(int index) const;
    void printColumnName(std::ofstream& ofs) const;
    void printColumnValue(int index, std::ofstream &ofs) const;

    void printValueAligned(const char* value) const;
    void printValueAligned(const char* value, std::ofstream& ofs) const;

    void printAlignment(std::ofstream &ofs) const;

    int getColumnSize() const;

    void setValue(char *string, int i);

    void changeValue(char *oldValue, char *newValue);

    bool isValueEqual(char *value, int i);
};


#endif //PRACTUCUMSEM2_COLLUMN_H
