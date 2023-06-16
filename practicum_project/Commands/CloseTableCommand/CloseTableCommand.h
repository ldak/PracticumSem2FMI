//
// Created by MILEN_PC on 16.6.2023 г..
//

#ifndef PRACTUCUMSEM2_CLOSETABLECOMMAND_H
#define PRACTUCUMSEM2_CLOSETABLECOMMAND_H


#include "../BasicComand/BasicCommand.h"

class CloseTableCommand : public BasicCommand {
public:
    void execute(SharedPtr<TableParser> &table, MyString &tableFile) override;
    SharedPtr<BasicCommand> clone() const override;

};


#endif //PRACTUCUMSEM2_CLOSETABLECOMMAND_H
