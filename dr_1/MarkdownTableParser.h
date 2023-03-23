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
    Row rows[ROW_COUNT];
    int rowCount = 0;
    int columnCount = 0;
    void printTable(std::ofstream &ofs) const;

public:
    void printTable() const;
    void writeToFile(std::ofstream &ofs) const;
    void readFromFile(std::ifstream &ifs);


    void changeColumnName(const char *oldName, const char *newName);

    void addRow(const Row& row);
};


#endif //PRACTUCUMSEM2_MARKDOWNTABLEPARSER_H
