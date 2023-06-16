//
// Created by MILEN_PC on 16.6.2023 г..
//

#ifndef PRACTUCUMSEM2_INVALIDCOMMAND_H
#define PRACTUCUMSEM2_INVALIDCOMMAND_H


#include "../BasicComand/BasicCommand.h"

class InvalidCommand : public BasicCommand{
    void execute(SharedPtr<TableParser>& table, MyString &tableFile) override;
    SharedPtr<BasicCommand> clone() const override;
};


#endif //PRACTUCUMSEM2_INVALIDCOMMAND_H
