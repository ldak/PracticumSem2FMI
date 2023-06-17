//
// Created by MILEN_PC on 17.6.2023 г..
//

#ifndef PRACTUCUMSEM2_PRINTTABLECOMMAND_H
#define PRACTUCUMSEM2_PRINTTABLECOMMAND_H


#include "../BasicComand/BasicCommand.h"

class PrintTableCommand : public BasicCommand {
public:
    SharedPtr<BasicCommand> clone() const override;
    void execute(SharedPtr<TableParser> &table, MyString &tableFile) override;
};


#endif //PRACTUCUMSEM2_PRINTTABLECOMMAND_H
