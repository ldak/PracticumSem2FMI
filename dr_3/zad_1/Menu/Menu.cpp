//
// Created by MILEN_PC on 23.5.2023 г..
//

#include "Menu.h"


static int selectMode() {
    char mode;
    do {
        std::cout << "Choose mode: " << std::endl;
        std::cout << "1. Interval from [a, b]" << std::endl;
        std::cout << "2. Showing numbers" << std::endl;
        std::cin >> mode;
        std::cin.ignore();
    } while (mode != '1' && mode != '2');
    return mode - '0';
}

static void intervalsLoop(Set *set) {
    do {
        std::cout << "Enter interval [a, b]" << std::endl;
        std::cout << "Enter 0, 0 for exit" << std::endl;
        int a, b;
        std::cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        for (int i = a; i <= b; ++i) {
            if (set->contains(i)) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    } while (true);
}

static void programLoop(Set *set) {
    int i = 0;
    do {
        std::cout << "Enter 0 for exit" << std::endl;
        char number;
        std::cin >> number;
        if (number == '0') {
            break;
        }
        while (!set->contains(++i)) {}
        std::cout << "Next number is: " << i << std::endl;

    } while (true);

}


void Menu::startProgram(const MyString &fileName) {
    Set *set = SetLoader::loadFromFile(fileName);

    int mode = selectMode();
    if (mode == 1) {
        intervalsLoop(set);
    } else {
        programLoop(set);
    }
    delete set;
}