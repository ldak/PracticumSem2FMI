//
// Created by MILEN_PC on 17.6.2023 г..
//

#include "SaveTableAsCommand.h"
#include <fstream>

void SaveTableAsCommand::execute(SharedPtr<TableParser> &table, MyString &tableFile) {
    if (!table.exists()){
        std::cout << "You need to open table first!" << std::endl;
        return;
    }
    char buffer[1024]{'\0'};
    std::cout << "Enter file name: ";
    std::cin.getline(buffer, 1024);
    std::ofstream out(buffer);
    if(!out.is_open()){
        std::cout << "Cannot open file " << buffer << std::endl;
    }
    out << *table;
    tableFile = buffer;
    out.close();
}

SharedPtr<BasicCommand> SaveTableAsCommand::clone() const {
    return SharedPtr<BasicCommand>();
}
