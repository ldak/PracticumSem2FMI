//
// Created by MILEN_PC on 16.6.2023 г..
//

#include "OpenTableCommand.h"

void OpenTableCommand::execute(SharedPtr<TableParser>& table, MyString &tableFile) {
    std::ifstream file(tableFile.c_str());
    if(!file.is_open()){
        std::cout << "File not found!" << std::endl;
        return;
    }
    table = new TableParser();
    file >> (*table);
    file.close();
}

SharedPtr<BasicCommand> OpenTableCommand::clone() const {
    return SharedPtr<BasicCommand>();
}
