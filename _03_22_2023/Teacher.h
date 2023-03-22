//
// Created by MILEN_PC on 3/22/2023.
//

#ifndef PRACTUCUMSEM2_TEACHER_H
#define PRACTUCUMSEM2_TEACHER_H


class Teacher {
    private:
        char name[20]{};
        int yearsOfExperience;
        int age;
    public:
        explicit Teacher(const char* name, int experience, int age);
        const char* getName() const;
        void setName(char* name);
        int getAge() const;
        void setAge(int age);
        int getYearsOfExperience() const;
        void setYearsOfExperience(int experience);

};


#endif //PRACTUCUMSEM2_TEACHER_H
