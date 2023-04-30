//
// Created by MILEN_PC on 4/19/2023.
//

#ifndef PRACTUCUMSEM2_STRINGCREATOR_H
#define PRACTUCUMSEM2_STRINGCREATOR_H


#include "StringPiece.h"
#include "MyString.h"

class StringCreator {
private:
    StringPiece** pieces;
    size_t count = 0;
    size_t capacity = 0;
    void copyFrom(const StringCreator& other);
    void free();
public:
    explicit StringCreator(size_t capacity);
    StringCreator(const StringCreator& other);
    StringCreator& operator=(const StringCreator& other);
    ~StringCreator();

    void addPiece(const char* piece = "");
    void swapPieces(size_t index1, size_t index2);
    void removePiece(size_t index);
    void setPiece(size_t index, const char* piece);
    int length() const;
    MyString getString() const;

    StringPiece& operator[](size_t index);


    void resize();
};



#endif //PRACTUCUMSEM2_STRINGCREATOR_H
