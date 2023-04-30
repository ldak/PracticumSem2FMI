//
// Created by MILEN_PC on 4/19/2023.
//

#include <stdexcept>
#include "StringPiece.h"

void StringPiece::setData(const char *str) {
    this->start = 0;
    int strLength = strlen(str);
    this->end = strLength == 0 ? 0 : strLength - 1;
    if (this->end >= 16)
        throw std::invalid_argument("String is too long");
    int i = 0;
    while (str[i] != '\0') {
        this->data[i] = str[i];
        i++;
    }

}

const char *StringPiece::getData() const {
    int size = this->getSize();
    char *temp = new char[size + 1];
    temp[size] = '\0';
    for (int i = this->start; i <= this->end; i = (i + 1) % CONSTS::STRING_PIECE_SIZE) {
        temp[i] = this->data[i];
    }
    return temp;
}

void StringPiece::operator<<(const char *str) {
    int strSize = strlen(str);

    int pieceSize = this->getSize();
    if (strSize + pieceSize > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");
    int i = 0;
    while (str[i] != '\0') {
        this->operator[](pieceSize + i) = str[i];
        i++;
    }
    if(pieceSize == 0)
        this->end = (this->end + strSize - 1) % CONSTS::STRING_PIECE_SIZE;
    else
        this->end = (this->end + strSize) % CONSTS::STRING_PIECE_SIZE;

}

void operator>>(const char *str, StringPiece &piece) {
    int length = strlen(str);
    int size = piece.getSize();
    if (length + size > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");

    piece.start = (piece.start + CONSTS::STRING_PIECE_SIZE - length) % CONSTS::STRING_PIECE_SIZE;
    for (int i = 0; i < length; i++) {
        piece[i] = str[i];
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
    this->end = (CONSTS::STRING_PIECE_SIZE + this->end - i) % CONSTS::STRING_PIECE_SIZE;
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
    if (this->start == this->end)
        return 0;
    if(this->start < this->end)
        return this->end -this->start + 1;

    return CONSTS::STRING_PIECE_SIZE - this->start + this->end + 1;
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
    int numSize = numLength(num);
    if (numSize == 0)
        return;

    int pieceSize = this->getSize();
    if (numSize + pieceSize > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");

    int i = 0;
    while (i < numSize) {
        this->operator[](pieceSize + i++) = (num / (int) pow(10, numSize - i - 1)) % 10 + '0';
    }

    if(pieceSize == 0)
        this->end = (this->end + numSize - 1) % CONSTS::STRING_PIECE_SIZE;
    else
        this->end = (this->end + numSize) % CONSTS::STRING_PIECE_SIZE;

}

void operator>>(int num, StringPiece &piece) {
    int length = numLength(num);
    if (length + piece.getSize() > CONSTS::STRING_PIECE_SIZE)
        throw std::invalid_argument("String is too long");

    piece.start = (piece.start + CONSTS::STRING_PIECE_SIZE - length) % CONSTS::STRING_PIECE_SIZE;

    for (int i = 0; i < length; i++) {
        int a = (num / (int) pow(10, length - i - 1)) % 10;
        piece[i] = a + '0';
    }
}

StringPiece::StringPiece() {
    this->start = 0;
    this->end = 0;

}



