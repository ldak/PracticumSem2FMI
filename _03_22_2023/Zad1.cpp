//
// Created by MILEN_PC on 3/22/2023.
//

#include "Teacher.h"
#include <iostream>

int main(){
    Teacher* t = new Teacher("hello", 2, 22);

    std::cout << t->getAge() << ' ' << t->getName() << ' ' << t->getYearsOfExperience();
}