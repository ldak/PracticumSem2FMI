//
// Created by MILEN_PC on 4/19/2023.
//

#include "StringCreator.h"

void StringCreator::copyFrom(const StringCreator &other) {
    this->pieces = new StringPiece[other.capacity];
    for (size_t i = 0; i < other.count; ++i) {
        this->pieces[i] = other.pieces[i];
    }
    this->count = other.count;
    this->capacity = other.capacity;

}

void StringCreator::free() {
    delete[] this->pieces;
}

StringCreator::StringCreator(size_t capacity) {
    this->pieces = new StringPiece[capacity];
    this->count = 0;
    this->capacity = capacity;
}

StringCreator::StringCreator(const StringCreator &other) {
    this->copyFrom(other);
}

StringCreator &StringCreator::operator=(const StringCreator &other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

StringCreator::~StringCreator() {
    this->free();
}

void StringCreator::addPiece(const char *piece) {
    if (this->count == this->capacity)
        this->resize();
    this->pieces[this->count++] = StringPiece(piece);
}

void StringCreator::swapPieces(size_t index1, size_t index2) {
    StringPiece temp = this->pieces[index1];
    this->pieces[index1] = this->pieces[index2];
    this->pieces[index2] = temp;
}

void StringCreator::removePiece(size_t index) {
    this->pieces[index].setData("");

}

void StringCreator::setPiece(size_t index, const char *piece) {
    this->pieces[index].setData(piece);
}

int StringCreator::length() const {
    int length = 0;
    for (int i = 0; i < this->count ; ++i) {
        length+= this->pieces[i].getSize() != 0 ? this->pieces[i].getSize() : CONSTS::EMPTY_STRING_SIZE;
    }
    return length;
}

MyString StringCreator::getString() const {
    char* data = new char[this->length() + 1];
    int index = 0;
    for (int i = 0; i < this->count ; ++i) {
        for (int j = 0; j < this->pieces[i].getSize(); ++j) {
            data[index++] = this->pieces[i].getData()[j];
        }
        if (this->pieces[i].getSize() != 0) {
            continue;
        }
        for (int j = 0; j < CONSTS::EMPTY_STRING_SIZE; ++j) {
            data[index++] = ' ';
        }
    }
    data[index] = '\0';

    return MyString(data);
}

StringPiece &StringCreator::operator[](size_t index) {
    return this->pieces[index];
}

void StringCreator::resize() {
    this->capacity *= 2;
    StringPiece* temp = new StringPiece[this->capacity];
    for (size_t i = 0; i < this->count; ++i) {
        temp[i] = this->pieces[i];
    }
    this->free();
    this->pieces = temp;

}
