//
// Created by MILEN_PC on 3/22/2023.
//

#include "MarkdownTableParser.h"

void MarkdownTableParser::printTable() const{
    this->printColumnNames();
    this->printTableDivisor();

    for (int i = 0; i < this->rowCount; ++i) {
       this->printRow(i);
    }
}

void MarkdownTableParser::printColumnNames() const{
    for (int i = 0; i < this->columnCount; ++i) {
        std::cout << "|";
        this->columns[i].printColumnName();
    }
    std::cout << "|" << std::endl;
}

void MarkdownTableParser::printTableDivisor() const{
    for (int i = 0; i < this->columnCount ; ++i) {
        std::cout << "| ";
        for (int j = 0; j < this->columns[i].getColumnSize() - 2; ++j) {
            std::cout << "-";
        }
        std::cout << " ";
    }
    std::cout << "|" << std::endl;
}

void MarkdownTableParser::printRow(int index) const {
    for (int j = 0; j <this->columnCount ; ++j) {
        std::cout << "|";
        this->columns[j].printColumnValue(index);
    }
    std::cout << "|" << std::endl;
}

void MarkdownTableParser::writeToFile(std::ofstream &ofs) const{
    if (!ofs.is_open())
        return;
    this->printTable(ofs);

}

void MarkdownTableParser::printTable(std::ofstream &ofs) const{
    for (int i = 0; i < this->columnCount; ++i) {
        ofs << "|";
        this->columns[i].printColumnName(ofs);
    }
    ofs << "|" << std::endl;

    for (int i = 0; i < this->columnCount; ++i) {
        ofs << "|";
        this->columns[i].printAlignment(ofs);
    }
    ofs << "|" << std::endl;
    for (int i = 0; i < this->rowCount; ++i) {
        for (int j = 0; j <this->columnCount ; ++j) {
            ofs << "|";
            this->columns[j].printColumnValue(i, ofs);
        }
        ofs << "|" << std::endl;
    }
}

void MarkdownTableParser::setColumnNames(std::ifstream &ifs) {
    if (!ifs.is_open())
        return;

    while (!ifs.eof()) {
        char *value = new char[VALUE_LENGTH*2];
        if (ifs.get() == '\n')
            break;
        ifs.getline(value, VALUE_LENGTH*2, '|');
//        std::cout << value << std::endl;
        this->columns[this->columnCount++].setName(value);
        delete[] value;
//        this->columns[this->columnCount-1].printColumn();
    }
}

void MarkdownTableParser::setColumnAlignment(std::ifstream &ifs) {
    if (!ifs.is_open())
        return;
    int i = 0;
    while(!ifs.eof()){
        if(ifs.get() == '\n' || ifs.eof())
            break;
        char *value = new char[VALUE_LENGTH*2];
        ifs.getline(value, 20, '|');
        this->columns[i++].setAlignment(value);
        delete[] value;
    }
}
void MarkdownTableParser::setRowsValues(std::ifstream &ifs) {
    if (!ifs.is_open())
        return;
    while(!ifs.eof()){
        if(ifs.get() == '\n' || ifs.eof())
            break;
        char *row = new char[VALUE_LENGTH*2*COLUMN_COUNT];
        ifs.getline(row, VALUE_LENGTH*2*COLUMN_COUNT);
        this->setRowValues(row, this->rowCount);
        this->rowCount++;
        delete[] row;
    }
}

void MarkdownTableParser::setRowValues(const char *row, int i) {
    std::stringstream ss(row);
    int j = 0;
    while(!ss.eof()){
//        if(ss.peek() == '\n')
//            break;
        char* value = new char[VALUE_LENGTH*2];
        ss.getline(value,VALUE_LENGTH*2, '|');
        this->columns[j].setValue(value, i);
        j++;
        delete[] value;
    }
}


void MarkdownTableParser::readFromFile(std::ifstream &ifs) {
    if (!ifs.is_open())
        return;
    this->columnCount = 0;
    this->setColumnNames(ifs);
    this->setColumnAlignment(ifs);
    this->rowCount = 0;
    this->setRowsValues(ifs);
}

int MarkdownTableParser::getColumnIndex(const char * name) const{
    for (int i = 0; i < this->columnCount; ++i) {
        const char* columnName = this->columns[i].getName();
        if (string_helper::strCompare(columnName, name) == 0){
            return i;
        }
    }
    return -1;
}

bool MarkdownTableParser::changeColumnName(const char *oldName, const char *newName) {
    int index = this->getColumnIndex(oldName);
    if (index == -1)
        return false;
    this->columns[index].setName(newName);
    return true;
}

bool MarkdownTableParser::addRow(const char* row) {
    if (this->rowCount == ROW_COUNT - 1)
        return false;
    this->setRowValues(row, this->rowCount);
    this->rowCount++;
    return true;
}

bool MarkdownTableParser::changeCellByNameAndRow(char *columnName, int i, char *value) {
    int index = this->getColumnIndex(columnName);
    if (index == -1)
        return false;
    this->columns[index].setValue(value, i + 1);
    return true;
}

bool MarkdownTableParser::changeCellByNameAndValue(char *columnName, char *oldValue, char *newValue) {
    int index = this->getColumnIndex(columnName);
    if (index == -1)
        return false;
    this->columns[index].changeValue(oldValue, newValue);
    return true;
}

void MarkdownTableParser::selectByValue(char *columnName, char *value) {
    int index = this->getColumnIndex(columnName);
    if (index == -1){
        std::cout << "Column not found" << std::endl;
        return;
    }
    this->printColumnNames();
    this->printTableDivisor();
    for (int i = 0; i < this->rowCount; ++i) {
        if (this->columns[index].isValueEqual(value, i))
            this->printRow(i);
    }
}




