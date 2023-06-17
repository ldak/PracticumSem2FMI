//
// Created by MILEN_PC on 17.6.2023 г..
//

#ifndef PRACTUCUMSEM2_EDITTABLECOMMAND_H
#define PRACTUCUMSEM2_EDITTABLECOMMAND_H


#include "../BasicComand/BasicCommand.h"

class EditTableCommand : public BasicCommand{
public:
    void execute(SharedPtr<TableParser> &table, MyString &tableFile) override;
    SharedPtr<BasicCommand> clone() const override;
};


#endif //PRACTUCUMSEM2_EDITTABLECOMMAND_H
