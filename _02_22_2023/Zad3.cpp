//
// Created by MILEN_PC on 2/22/2023.
//
#include "Zad2.cpp"

const int GROUP_SIZE = 3;

struct studentsGroup{
    student students[GROUP_SIZE];
    double averageGrade;
};

studentsGroup createGroupFromConsole(){
    studentsGroup group;
    double averageGrade = 0;
    for (int i = 0; i < GROUP_SIZE; ++i) {
        group.students[i] = consoleToStudent();
        averageGrade += group.students[i].grade;
    }
    group.averageGrade = averageGrade / GROUP_SIZE;
    return group;
}

int countStudentsWithScholarship(studentsGroup& group, double minGrade){
    int count = 0;
    for (int i = 0; i < GROUP_SIZE; ++i) {
        if(group.students[i].grade > minGrade){
            count++;
        }
    }
    return count;
}

int main(){
    studentsGroup group = createGroupFromConsole();
    std::cout << "Average grade: " << group.averageGrade << std::endl;
    std::cout << "Students with scholarship: " << countStudentsWithScholarship(group, 4.5) << std::endl;
    return 0;
}