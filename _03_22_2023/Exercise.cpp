//
// Created by MILEN_PC on 3/22/2023.
//

#include "Exercise.h"
#include <cstring>

Exercise::Exercise(const char *name, const char *description, int marks) {
    strcpy(this->name, name);
    strcpy(this->description, description);
    this->marks = marks;
}

void Exercise::setName(const char *name) {
    strcpy(this->name, name);

}

void Exercise::setDescription(const char *description) {
    strcpy(this->description, description);
}

void Exercise::setMarks(int marks) {
    this->marks = marks;

}

const char *Exercise::getName() const {
    return this->name;
}

const char *Exercise::getDescription() const {
    return this->description;
}

int Exercise::getMarks() const {
    return this->marks;
}

Exercise::Exercise() {

}
