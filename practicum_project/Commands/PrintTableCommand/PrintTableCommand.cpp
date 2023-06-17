//
// Created by MILEN_PC on 17.6.2023 г..
//

#include "PrintTableCommand.h"

SharedPtr<BasicCommand> PrintTableCommand::clone() const {
    return SharedPtr<BasicCommand>(new PrintTableCommand(*this));
}

void PrintTableCommand::execute(SharedPtr<TableParser> &table, MyString &tableFile) {
    if (!table.exists()){
        std::cout << "You need to open table first!" << std::endl;
        return;
    }
    std::cout << "Table file: " << tableFile << std::endl;
    std::cout << "Table: " << std::endl;
    table->print(std::cout);

}
