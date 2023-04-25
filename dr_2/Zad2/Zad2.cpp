#include "StringCreator.h"

//
// Created by MILEN_PC on 4/19/2023.
//
int main() {
    StringCreator sc(2);

    sc.addPiece("test");
    sc.addPiece();
    sc.addPiece("football");


    sc[1] << " friends ";
    " Hello " >> sc[1];
    10 >> sc[2];

    MyString result1 = sc.getString(); // "test Hello friends 10football"
    std::cout << result1 << std::endl;

    sc.swapPieces(1,2);
    MyString result2 = sc.getString(); // "test10football Hello friends"
    std::cout << result2 << std::endl;

    sc.removePiece(1);
    MyString result3 = sc.getString(); // "test10
    std::cout << result3 << std::endl;

    return 0;
}