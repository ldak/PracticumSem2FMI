//
// Created by MILEN_PC on 3/22/2023.
//

#include "Column.h"


Column::Column() {

}

Column::Column(const char *name) {
    strcpyWithoutSpaces(this->name, name);
}

void Column::setAlignment(Alignment align) {
    this->alignment = align;
}

void Column::setName(const char *name) {
    strcpyWithoutSpaces(this->name, name);
    if (this->columnSize < strLength(this->name) + 2)
        this->columnSize = strLength(this->name) + 2;
}

const char *Column::getName() const {
    return this->name;
}

void Column::setColumnSize(int columnSize) {
    this->columnSize = columnSize;
}

void Column::printColumn() const {
    printValueAligned(this->name);
}

void Column::printValueAligned(const char* value) const{
    alignString(value, this->columnSize, this->alignment);
}

void Column::printColumn(std::ofstream& ofs) const {
    if (!ofs.is_open())
        return;
    printValueAligned(this->name, ofs);
}

void Column::printValueAligned(const char *value, std::ofstream& ofs) const {
    if (!ofs.is_open())
        return;
    alignString(value, this->columnSize, this->alignment, ofs);
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
    char* alignCopy = new char[20];
    strcpyWithoutSpaces(alignCopy, align);
    if (strCompare(alignCopy, ":---") == 0) {
        this->alignment = Alignment::LEFT;
    } else if (strCompare(alignCopy, "---:") == 0) {
        this->alignment = Alignment::RIGHT;
    } else if (strCompare(alignCopy, ":----:") == 0) {
        this->alignment = Alignment::CENTER;
    }
}

int Column::getColumnSize() const{
    return this->columnSize;
}




