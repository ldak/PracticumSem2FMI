//
// Created by MILEN_PC on 3/22/2023.
//

#include "MarkdownTableParser.h"

void MarkdownTableParser::printTable() const{
    for (int i = 0; i < this->columnCount; ++i) {
        std::cout << "|";
        this->columns[i].printColumn();
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
            this->columns[j].printValueAligned(this->rows[i].getValue(j));
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
        this->columns[i].printColumn(ofs);
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
            this->columns[j].printValueAligned(this->rows[i].getValue(j), ofs);
        }
        ofs << "|" << std::endl;
    }
}

void MarkdownTableParser::readFromFile(std::ifstream &ifs) {
    if (!ifs.is_open())
        return;

    while(!ifs.eof()){
        char *value = new char[20];
        if(ifs.get() == '\n')
            break;
        ifs.getline(value, 20, '|');
//        std::cout << value << std::endl;
        this->columns[this->columnCount++].setName(value);
//        this->columns[this->columnCount-1].printColumn();
    }
    int i = 0;
    while(!ifs.eof()){
        if(ifs.get() == '\n' || ifs.eof())
            break;
        char *value = new char[20];
        ifs.getline(value, 20, '|');
//        std::cout << value << std::endl;
        this->columns[i].setAlignment(value);
    }

    while(!ifs.eof()){
        if(ifs.get() == '\n' || ifs.eof())
            break;
        char *row = new char[20];
        ifs.getline(row, 300);
        std::stringstream ss(row);
        int i = 0;
        while(!ss.eof()){
            if(ss.get() == '\n' || ss.eof())
                break;
            char* value = new char[20];
            ss.getline(value,40, '|');
            this->rows[this->rowCount].setValue( value, i);
            int length = this->rows[this->rowCount].getValueLength(i);
            if (length + 2 > this->columns[i].getColumnSize())
                this->columns[i].setColumnSize(length + 2);
            i++;
        }
        this->rowCount++;
    }

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

void MarkdownTableParser::addRow(const Row& row) {
    this->rows[this->rowCount++] = row;
    for (int i = 0; i < this->columnCount; ++i) {
        int length = this->rows[this->rowCount].getValueLength(i);
        if (this->columns[i].getColumnSize() < length + 2)
            this->columns[i].setColumnSize(length + 2);
    }
}
