//
// Created by MILEN_PC on 3/22/2023.
//

#include "MarkdownTableParser.h"

void MarkdownTableParser::printTable() const{
    for (int i = 0; i < this->columnCount; ++i) {
        std::cout << "|";
        this->columns[i].printColumnName();
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i < this->columnCount ; ++i) {
        std::cout << "| ";
        for (int j = 0; j < this->columns[i].getColumnSize() - 2; ++j) {
            std::cout << "-";
        }
        std::cout << " ";
    }
    std::cout << "|" << std::endl;

    for (int i = 0; i < this->rowCount; ++i) {
        for (int j = 0; j <this->columnCount ; ++j) {
            std::cout << "|";
            this->columns[j].printColumnValue(i);
        }
        std::cout << "|" << std::endl;
    }
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
        char *value = new char[20];
        if (ifs.get() == '\n')
            break;
        ifs.getline(value, 20, '|');
//        std::cout << value << std::endl;
        this->columns[this->columnCount++].setName(value);
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
        char *value = new char[20];
        ifs.getline(value, 20, '|');
        this->columns[i].setAlignment(value);
    }
}
void MarkdownTableParser::setRowsValues(std::ifstream &ifs) {
    if (!ifs.is_open())
        return;
    while(!ifs.eof()){
        if(ifs.get() == '\n' || ifs.eof())
            break;
        char *row = new char[300];
        ifs.getline(row, 300);
        this->setRowValues(row, this->rowCount);
        this->rowCount++;
    }
}

void MarkdownTableParser::setRowValues(const char *row, int i) {
    std::stringstream ss(row);
    int j = 0;
    while(!ss.eof()){
        if(ss.get() == '\n')
            break;
        char* value = new char[20];
        ss.getline(value,40, '|');
        this->columns[j].setValue(value, i);
        j++;
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

void MarkdownTableParser::changeColumnName(const char *oldName, const char *newName) {
    for (int i = 0; i < this->columnCount; ++i) {
        const char* name = this->columns[i].getName();
        if (strCompare(name, oldName) == 0){
            this->columns[i].setName(newName);
            return;
        }
    }

}

void MarkdownTableParser::addRow(const char* row) {
    this->setRowValues(row, this->rowCount);
    this->rowCount++;
}




