//
// Created by MILEN_PC on 16.6.2023 г..
//

#ifndef PRACTUCUMSEM2_OPENTABLECOMMAND_H
#define PRACTUCUMSEM2_OPENTABLECOMMAND_H


#include "../BasicComand/BasicCommand.h"
#include <fstream>

class OpenTableCommand : public BasicCommand{
public:
    void execute(SharedPtr<TableParser>& table, MyString &tableFile) override;
    SharedPtr<BasicCommand> clone() const override;
};


#endif //PRACTUCUMSEM2_OPENTABLECOMMAND_H
