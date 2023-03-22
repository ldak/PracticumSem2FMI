//
// Created by MILEN_PC on 3/22/2023.
//
#include <iostream>
#include "MarkdownTableParser.h"
#include <fstream>



int main(){
    MarkdownTableParser parser;
    std::ifstream ifs("table.md");

    parser.readFromFile(ifs);
    std::cout << "table --------------" << std::endl;
    parser.printTable();
    ifs.close();

    std::ofstream ofs("table2.md");
    parser.writeToFile(ofs);

}