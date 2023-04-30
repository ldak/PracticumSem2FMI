//
// Created by MILEN_PC on 4/19/2023.
//

#include <stdexcept>
#include "StringPiece.h"

void StringPiece::setData(const char *str) {
    this->start = 0;
    this->end = strlen(str) - 1;
    if (this->end >= 16)
        throw std::invalid_argument("String is too long");
    int i =0;
    while(str[i] != '\0'){
        this->data[i] = str[i];
        i++;
    }

}

const char *StringPiece::getData() const {
    int size = this->getSize();
    char* temp = new char[size + 1];
    temp[size] = '\0';
    for (int i = this->start; i != this->end + 1 ; i = (i + 1) % CONSTS::STRING_PIECE_SIZE) {
        temp[i] = this->data[i];
    }
    return temp;
}

void StringPiece::operator<<(const char *str) {
    int length = strlen(str);
    if (length + this->getSize() > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");
    int i =0;
    while(str[i] != '\0'){
        this->data[this->end + i] = str[i];
        i++;
    }
    this->end += length;
}

void operator>>(const char* str, StringPiece &piece) {
    int length = strlen(str) - 1;
    int size = piece.getSize();
    if (length + size > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");

    piece.start = (piece.start + CONSTS::STRING_PIECE_SIZE - length) % CONSTS::STRING_PIECE_SIZE;
    for (int i = 0; i < length; i++) {
        piece.data[(piece.start + i) % CONSTS::STRING_PIECE_SIZE] = str[i];
    }
}

void StringPiece::removeFirst(int i) {
    if (i > this->getSize())
        throw std::invalid_argument("String is too short");
    this->start = (this->start + i) % CONSTS::STRING_PIECE_SIZE;
}

void StringPiece::removeLast(int i) {
    if (i > this->getSize())
        throw std::invalid_argument("String is too short");
    this->end -= i;
}

char StringPiece::operator[](int i) const {
    return this->data[(this->start + i) % CONSTS::STRING_PIECE_SIZE];
}

char &StringPiece::operator[](int i) {
    return this->data[(this->start + i) % CONSTS::STRING_PIECE_SIZE];
}

StringPiece::StringPiece(const char *str) {
    this->setData(str);
}

int StringPiece::getSize() const {
    return this->start <= this->end
        ? this->end - this->start + 1
        : CONSTS::STRING_PIECE_SIZE - this->start + this->end + 1;
}

static int reverse(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

static int numLength(int num) {
    int length = 0;
    while (num != 0) {
        length++;
        num /= 10;
    }
    return length;
}


void StringPiece::operator<<(int num) {
    if (numLength(num) + this->getSize() > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");

    int reversed = reverse(num);
    while(reversed != 0){
        this->data[this->end++] = reversed % 10 + '0';
        reversed /= 10;
    }

}

void operator>>(int num, StringPiece &piece) {
    int length = numLength(num);
    if (length + piece.getSize() > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");

    piece.start = (piece.start + CONSTS::STRING_PIECE_SIZE - length) % CONSTS::STRING_PIECE_SIZE;

    for (int i = 0; i < length; i++) {
        piece.data[(piece.start + i) % CONSTS::STRING_PIECE_SIZE] = num % 10 + '0';
        num /= 10;
    }
}

StringPiece::StringPiece() {
    this->start = 0;
    this->end = 0;

}



