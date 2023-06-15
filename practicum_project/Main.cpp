//
// Created by MILEN_PC on 14.5.2023 г..
//
#include <fstream>
#include "Table/TableParser/TableParser.h"

int main (){
//    try{
        TableParser parser;
        std::ifstream ifs("Maika_ti.txt");
        ifs >> parser;
        std::cout << parser;
//    }catch (std::exception &e){
//        std::cout << e.what() << std::endl;
//    }

    return 0;
}