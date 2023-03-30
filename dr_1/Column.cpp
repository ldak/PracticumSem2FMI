//
// Created by MILEN_PC on 3/22/2023.
//

#include "Column.h"


Column::Column() = default;

Column::Column(const char *name) {
    this->setName(name);
}

void Column::setAlignment(Alignment align) {
    this->alignment = align;
}

void Column::setName(const char *name) {

    this->name.setValue(name);
    int nameLength = string_helper::strLength(this->name.getValue());
    this->setColumnSize(nameLength + 2);
}

const char *Column::getName() const {
    return this->name.getValue();
}

void Column::setColumnSize(int columnSize) {
    if (this->columnSize < columnSize)
        this->columnSize = columnSize;
}

void Column::printColumnName() const {
    this->printValueAligned(this->name.getValue());
}

void Column::printColumnValue(int index) const {
    this->printValueAligned(this->values[index].getValue());
}


void Column::printValueAligned(const char* value) const{
    string_helper::alignString(value, this->columnSize, this->alignment);
}

void Column::printColumnName(std::ofstream& ofs) const {
    if (!ofs.is_open())
        return;
    this->printValueAligned(this->name.getValue(), ofs);
}

void Column::printColumnValue(int index, std::ofstream& ofs) const {
    if (!ofs.is_open())
        return;
    this->printValueAligned(this->values[index].getValue(), ofs);
}

void Column::printValueAligned(const char *value, std::ofstream& ofs) const {
    if (!ofs.is_open())
        return;
    string_helper::alignString(value, this->columnSize, this->alignment, ofs);
}

void Column::printAlignment(std::ofstream &ofs) const{
    if (!ofs.is_open())
        return;
    const char* align;
    switch (this->alignment) {
        case Alignment::LEFT:
            align = ":---";
            break;
        case Alignment::RIGHT:
            align = "---:";
            break;
        case Alignment::CENTER:
            align = ":----:";
            break;
    }
    printValueAligned(align, ofs);
}

void Column::setAlignment(const char *align) {
    char* alignCopy = new char[VALUE_LENGTH];
    string_helper::strcpyWithoutSpaces(alignCopy, align);
    if (string_helper::strCompare(alignCopy, ":---") == 0) {
        this->alignment = Alignment::LEFT;
    } else if (string_helper::strCompare(alignCopy, "---:") == 0) {
        this->alignment = Alignment::RIGHT;
    } else if (string_helper::strCompare(alignCopy, ":----:") == 0) {
        this->alignment = Alignment::CENTER;
    }
    delete[] alignCopy;
}

int Column::getColumnSize() const{
    return this->columnSize;
}

void Column::setValue(char *string, int i) {
    this->values[i].setValue(string);
    int valueLength = string_helper::strLength(this->values[i].getValue());
    this->setColumnSize(valueLength + 2);
}



