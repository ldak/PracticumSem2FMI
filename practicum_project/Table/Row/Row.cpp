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
    while(!in.eof() ){
        char buffer[1024];
        in.getline(buffer, 1024, ',');
//        if (in.eof())
//            break;
        row.cells.push_back(factory->createCell(buffer));
    }
    return in;
}

int Row::size() const {
    return this->cells.size();
}

SharedPtr<BasicCell>& Row::operator[](int index) {
    return this->cells[index];
}

const SharedPtr<BasicCell> &Row::operator[](int index) const {
    return this->cells[index];
}

void Row::setAlignments(MyVector<int>& vector) {
    for (int i = 0; i < this->cells.size(); ++i) {
        int cellAlignment = this->cells[i]->getLength();
        if (vector.size() == i){
            vector.push_back(cellAlignment);
            continue;
        }
        if (cellAlignment > vector[i]){
            vector[i] = cellAlignment;
        }
    }
}

void Row::print(std::ostream &os, MyVector<int> alignments) const {
    os << "| ";
    for (int i = 0; i < this->cells.size(); ++i) {
        this->cells[i]->print(os);
        for (int j = this->cells[i]->getLength(); j < alignments[i]; ++j) {
            os << ' ';
        }
        os << " | ";
    }
}



