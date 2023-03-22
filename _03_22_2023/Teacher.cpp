//
// Created by MILEN_PC on 3/22/2023.
//

#include "Teacher.h"

#include <cstring>

Teacher::Teacher(const char *name, int experience, int age) {
    strcpy(this->name, name);
    this->yearsOfExperience = experience;
    this->age = age;

}

const char *Teacher::getName() const{
    return this->name;
}

void Teacher::setName(char *name) {
    strcpy(this->name, name);
}

int Teacher::getAge() const {
    return this->age;
}

void Teacher::setAge(int age) {
    this->age = age;
}

int Teacher::getYearsOfExperience() const{
    return this->yearsOfExperience;
}

void Teacher::setYearsOfExperience(int experience) {
    this->yearsOfExperience = experience;
}

