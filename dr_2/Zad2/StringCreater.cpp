//
// Created by MILEN_PC on 4/19/2023.
//

#include "StringCreator.h"

void StringCreator::copyFrom(const StringCreator &other) {
    this->pieces = new StringPiece*[other.capacity]{nullptr};
    for (size_t i = 0; i < other.lastIndex; ++i) {
        this->pieces[i] = new StringPiece(*other.pieces[i]);
    }
    this->lastIndex = other.lastIndex;
    this->capacity = other.capacity;

}

void StringCreator::free() {
    for (int i = 0; i < this->lastIndex; ++i) {
        delete this->pieces[i];
    }
    delete[] this->pieces;
}

StringCreator::StringCreator(size_t capacity) {
    this->pieces = new StringPiece*[capacity]{nullptr};
    this->lastIndex = 0;
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
    if (this->lastIndex == this->capacity)
        this->resize();
    this->pieces[this->lastIndex++] = new StringPiece(piece);
}

void StringCreator::swapPieces(size_t index1, size_t index2) {
    if (index1>= capacity || index2 >= capacity)
        throw std::out_of_range("Swapping non-existing pieces");

    StringPiece* temp = this->pieces[index1];
    this->pieces[index1] = this->pieces[index2];
    this->pieces[index2] = temp;
}

void StringCreator::removePiece(size_t index) {
    if (this->capacity <= index)
       throw std::length_error("Deleting non-existing index");

    delete this->pieces[index];
    this->pieces[index] = nullptr;
    if (index == this->lastIndex - 1)
        this->lastIndex--;

}

void StringCreator::setPiece(size_t index, const char *piece) {
    if (this->capacity <= index)
        throw std::length_error("Setting at non-existing index");

    if (this->pieces[index] == nullptr)
        this->pieces[index] = new StringPiece(piece);
    else
        this->pieces[index]->setData(piece);
}

int StringCreator::length() const {
    int length = 0;
    for (int i = 0; i < this->lastIndex ; ++i) {
        length+= this->pieces[i] != nullptr ? this->pieces[i]->getSize() : CONSTS::EMPTY_STRING_SIZE;
    }
    return length;
}

static void addPieceData(char* data, int &index, StringPiece* piece) {
    if (piece == nullptr) {
        for (int j = 0; j < CONSTS::EMPTY_STRING_SIZE; ++j) {
            data[index++] = ' ';
        }
        return;
    }

    for (int j = 0; j < piece->getSize(); ++j) {
        data[index++] = piece->operator[](j);
    }
}

MyString StringCreator::getString() const {
    char* data = new char[this->length() + 1];
    int index = 0;
    for (int i = 0; i < this->lastIndex ; ++i) {
        addPieceData(data, index, this->pieces[i]);
    }
    data[index] = '\0';

    return MyString(std::move(data));
}

StringPiece &StringCreator::operator[](size_t index) {
    return *this->pieces[index];
}

void StringCreator::resize() {
    this->capacity *= 2;
    StringPiece** temp = new StringPiece*[this->capacity];
    for (size_t i = 0; i < this->lastIndex; ++i) {
        temp[i] = this->pieces[i];
    }
    delete[] this->pieces;
    this->pieces = temp;

}

StringCreator::StringCreator(StringCreator &&rhs) noexcept {
    moveFrom(std::move(rhs));
}

StringCreator &StringCreator::operator=(StringCreator &&other) noexcept {
    if (this != &other){
        this->free();
        this->moveFrom(std::move(other));
    }
    return *this;
}


void StringCreator::moveFrom(StringCreator &&other) {
    this->lastIndex = other.lastIndex;
    this->capacity = other.capacity;
    this->pieces = other.pieces;
    other.pieces = nullptr;
}
