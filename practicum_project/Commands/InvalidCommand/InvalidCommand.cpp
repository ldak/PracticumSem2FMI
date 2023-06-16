//
// Created by MILEN_PC on 16.6.2023 г..
//

#include "InvalidCommand.h"

void InvalidCommand::execute(SharedPtr<TableParser>& table, MyString &tableFile) {
    std::cout << "Invalid command!" << std::endl;

}

SharedPtr<BasicCommand> InvalidCommand::clone() const {
    return new InvalidCommand(*this);
}
