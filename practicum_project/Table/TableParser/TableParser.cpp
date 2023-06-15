//
// Created by MILEN_PC on 24.5.2023 г..
//

#include "TableParser.h"

std::istream &operator>>(std::istream &in, TableParser &tableParser){
    while(!in.eof()) {
        char buffer[10024];
        in.getline(buffer, 10024);
        std::stringstream ss(buffer);
        Row row;
        ss >> row;
        tableParser.rows.push_back(row);
    }
}

std::ostream &operator<<(std::ostream &out, TableParser &tableParser) {
}

