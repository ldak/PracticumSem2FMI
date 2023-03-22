//
// Created by MILEN_PC on 3/22/2023.
//

#include "Test.h"

void Test::addExercise(const Exercise& exercise) {
    this->exercises[this->exercisesCount++] = exercise;
}

void Test::changeMin(int minMarks) {
    this->minMarks = minMarks;
}

int Test::getMax() const {
    int max = 0;
    for (int i = 0; i < this->exercisesCount; ++i) {
        max += this->exercises[i].getMarks();
    }
    return max;
}

void Test::writeToFile(std::ofstream &ofs) {
    if(!ofs.is_open())
        return;
    ofs.write((const char*)&this->minMarks, sizeof(this->minMarks));
    ofs.write((const char*)&this->exercisesCount, sizeof(this->exercisesCount));
    for (int i = 0; i < this->exercisesCount; ++i) {
        ofs.write((const char*)&this->exercises[i], sizeof(Exercise));
    }
}

void Test::readFromFile(std::ifstream &ifs) {
    if(!ifs.is_open())
        return;
    ifs.read((char*)&this->minMarks, sizeof(this->minMarks));
    ifs.read((char*)&this->exercisesCount, sizeof(this->exercisesCount));
    for (int i = 0; i < this->exercisesCount; ++i) {
        ifs.read((char*)&this->exercises[i], sizeof(Exercise));
    }

}

Test::Test() {

}


