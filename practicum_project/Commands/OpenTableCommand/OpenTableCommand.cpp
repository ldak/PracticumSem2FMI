//
// Created by MILEN_PC on 16.6.2023 г..
//

#include "OpenTableCommand.h"

void OpenTableCommand::execute(SharedPtr<TableParser>& table, MyString &tableFile) {
    char buffer[1024]{'\0'};
    std::cout << "Enter file to read the table from: ";
    std::cin.getline(buffer, 1024);
    std::ifstream file(buffer);
    if(!file.is_open()){
        std::cout << "File not found!" << std::endl;
        return;
    }
    tableFile = buffer;
    table = new TableParser();
    try{
        file >> (*table);
    }catch (std::exception& e){
        std::cout << e.what() << std::endl;
        return;
    }
    file.close();
}

SharedPtr<BasicCommand> OpenTableCommand::clone() const {
    return SharedPtr<BasicCommand>();
}
