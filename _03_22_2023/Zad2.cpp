#include "Exercise.h"
#include "Test.h"
#include <iostream>
//
// Created by MILEN_PC on 3/22/2023.
//
int main(){
    Test test;
//    Exercise exercise = Exercise("Hello", "Say hello hello", 20);
//    for (int i = 0; i <3 ; ++i) {
//        test.addExercise(exercise);
//    }
    std::ifstream ifs("fdas.dat");
    test.readFromFile(ifs);
    ifs.close();
    std::cout << test.getMax();

}