//
// Created by MILEN_PC on 4/19/2023.
//

#ifndef PRACTUCUMSEM2_STRINGPIECE_H
#define PRACTUCUMSEM2_STRINGPIECE_H


#include "Consts.h"
#include "cstring"

class StringPiece {
    char data[CONSTS::STRING_PIECE_SIZE];
    int size = 0 ;
public:
    StringPiece();
    StringPiece(const char *str);
    void setData(const char* str);
    const char* getData() const;
    void removeFirst(int i);
    void removeLast(int i);
    char operator[](int i) const;
    char& operator[](int i);
    int getSize() const;

    void operator <<(const char * str);
    friend void operator >>(const char* str, StringPiece& piece);

    void operator <<(int num);
    friend void operator >>(int num, StringPiece& piece);
};
void operator >>(const char* str, StringPiece& piece);
void operator >>(int num, StringPiece& piece);


#endif //PRACTUCUMSEM2_STRINGPIECE_H
