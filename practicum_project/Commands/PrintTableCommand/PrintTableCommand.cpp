//
// Created by MILEN_PC on 17.6.2023 г..
//

#include "PrintTableCommand.h"

SharedPtr<BasicCommand> PrintTableCommand::clone() const {
    return SharedPtr<BasicCommand>(new PrintTableCommand(*this));
}

void PrintTableCommand::execute(SharedPtr<TableParser> &table, MyString &tableFile) {
    std::cout << "Table file: " << tableFile << std::endl;
    std::cout << "Table: " << std::endl;
    table->print(std::cout);

}
