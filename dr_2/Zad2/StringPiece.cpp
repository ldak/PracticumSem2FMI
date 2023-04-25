//
// Created by MILEN_PC on 4/19/2023.
//

#include <stdexcept>
#include "StringPiece.h"

void StringPiece::setData(const char *str) {
    this->size = strlen(str);
    if (this->size > 16)
        throw std::invalid_argument("String is too long");
    int i =0;
    while(str[i] != '\0'){
        this->data[i] = str[i];
        i++;
    }

}

const char *StringPiece::getData() const {
    return this->data;
}

void StringPiece::operator<<(const char *str) {
    int length = strlen(str);
    if (length + this->size > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");
    int i =0;
    while(str[i] != '\0'){
        this->data[this->size + i] = str[i];
        i++;
    }
    this->size += length;
}

void operator>>(const char* str, StringPiece &piece) {
    int length = strlen(str) - 1;
    int size = piece.getSize();
    if (length + size > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");
    for (int i = size + length; i >= 0 ; --i) {
        piece[i] = piece[i - length];
        if (i <= length)
            piece[i] = str[i];
    }
    piece.size = size + length;
    int a = piece.size;
}

void StringPiece::removeFirst(int i) {
    for (int j = 0; j < this->size - i; ++j) {
        this->data[j] = this->data[j + i];
    }
    this->size -= i;
}

void StringPiece::removeLast(int i) {
    this->size -= i;
}

char StringPiece::operator[](int i) const {
    return this->data[i];
}

char &StringPiece::operator[](int i) {
    return this->data[i];
}

StringPiece::StringPiece(const char *str) {
    this->setData(str);
}

int StringPiece::getSize() const {
    return this->size;
}

static int reverse(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

void StringPiece::operator<<(int num) {
    int reversed = reverse(num);
    while(reversed != 0){
        this->data[this->size++] = reversed % 10 + '0';
        reversed /= 10;
    }

}

static int numLength(int num) {
    int length = 0;
    while (num != 0) {
        length++;
        num /= 10;
    }
    return length;
}

void operator>>(int num, StringPiece &piece) {
    int length = numLength(num);
    for (int i = piece.getSize() + length; i >= 0; --i) {
        piece[i] = piece[i - length];
        if (i < length){
            piece[i] = num % 10 + '0';
            num /= 10;
        }
    }
    piece.size += length;

}

StringPiece::StringPiece() {
    this->size = 0;

}



