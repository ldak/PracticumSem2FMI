//
// Created by MILEN_PC on 24.5.2023 г..
//

#include "Row.h"

Row::Row(const MyVector<SharedPtr<BasicCell>> &cells): cells(cells.size()) {
    for (int i = 0; i < cells.size(); ++i) {
        this->cells.push_back(cells[i]->clone());
    }
}

Row::Row(MyVector<SharedPtr<BasicCell>> &&cells) {
    this->cells = std::move(cells);
}

void Row::copyFrom(const Row &other) {
    for (int i = 0; i < other.cells.size(); ++i) {
        this->cells.push_back(other.cells[i]->clone());
    }
}

void Row::moveFrom(Row &other) {
    this->cells = std::move(other.cells);
}

void Row::free() {
    cells.clear();
}

Row::Row(const Row &other): cells(other.cells.size()) {
    this->copyFrom(other);
}

Row& Row::operator=(const Row &other) {
    if (this!= &other){
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Row::Row(Row &&other)  noexcept {
    moveFrom(other);
}

Row& Row::operator=(Row &&other)  noexcept {
    if (this!= &other){
        this->free();
        this->moveFrom(other);
    }
    return *this;
}

Row::~Row() {
    this->free();
}

std::istream &operator>>(std::istream &in, Row &row) {
    CellsFactory* factory = CellsFactory::getInstance();
    while(!in.eof()){
        char buffer[1024];
        in.getline(buffer, 1024, ',');
        row.cells.push_back(factory->createCell(buffer));
    }
    return in;
}

