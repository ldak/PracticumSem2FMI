//
// Created by MILEN_PC on 3/22/2023.
//

#ifndef PRACTUCUMSEM2_MARKDOWNTABLEPARSER_H
#define PRACTUCUMSEM2_MARKDOWNTABLEPARSER_H


#include "Column.h"
#include "Row.h"
#include <fstream>
#include <iostream>


class MarkdownTableParser {
private:
    Column columns[COLUMN_COUNT];
    int rowCount = 0;
    int columnCount = 0;

    void printTable(std::ofstream &ofs) const;
    void setColumnNames(std::ifstream &ifs);
    void setColumnAlignment(std::ifstream &ifs);
    void setRowsValues(std::ifstream &ifs);

public:
    void printTable() const;
    void writeToFile(std::ofstream &ofs) const;
    void readFromFile(std::ifstream &ifs);

    void changeColumnName(const char *oldName, const char *newName);

    void addRow(const char* row);

    void setRowValues(const char *string, int i);
};


#endif //PRACTUCUMSEM2_MARKDOWNTABLEPARSER_H
