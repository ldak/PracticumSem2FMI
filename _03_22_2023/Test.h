//
// Created by MILEN_PC on 3/22/2023.
//

#ifndef PRACTUCUMSEM2_TEST_H
#define PRACTUCUMSEM2_TEST_H
#include "Exercise.h"
#include <fstream>

class Test {
private:
    Exercise exercises[20];
    int exercisesCount = 0;
    int minMarks;
public:
    Test();

    void addExercise(const Exercise& exercise);
    void changeMin(int minMarks);
    int getMax() const;
    void writeToFile(std::ofstream &ofs);
    void readFromFile(std::ifstream &ifs);


};


#endif //PRACTUCUMSEM2_TEST_H
