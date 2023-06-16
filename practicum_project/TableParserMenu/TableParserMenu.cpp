//
// Created by MILEN_PC on 16.6.2023 г..
//

#include "TableParserMenu.h"
#include "../Commands/CommandFactory/CommandFactory.h"

void TableParserMenu::printMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Open Table" << std::endl;
    std::cout << "2. Close Table" << std::endl;
    std::cout << "3. Save Table" << std::endl;
    std::cout << "4. Save Table As" << std::endl;
    std::cout << "5. Print Table" << std::endl;
    std::cout << "6. Edit Cell" << std::endl;
    std::cout << "7. Exit" << std::endl;

}

void TableParserMenu::programLoop() {
    CommandFactory* commandFactory = CommandFactory::getInstance();
    while(true){
        printMenu();
        SharedPtr<BasicCommand> command = commandFactory->createCommand();
        command->execute(this->table, this->fileName);
    }

}
