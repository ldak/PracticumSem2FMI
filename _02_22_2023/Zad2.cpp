//
// Created by MILEN_PC on 2/22/2023.
//

#include "iostream"

struct student {
    char name[16];
    char surname[16];
    char fn[6];
    double grade;
    enum class color {brown, black, blond, red, white} hairColor;
};

bool areEqual(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

char* colorToString(student::color color) {
    switch (color) {
        case student::color::brown:
            return new char[6]{"brown"};
        case student::color::black:
            return new char[6]{"black"};
        case student::color::blond:
            return new char[6]{"blond"};
        case student::color::red:
            return new char[4]{"red"};
        case student::color::white:
            return new char[6]{"white"};
    }
}

student::color stringToColor(const char* color) {
    if (areEqual(color, new char[6]{"brown"})) {
        return student::color::brown;
    } else if (areEqual(color, new char[6]{"black"})) {
        return student::color::black;
    } else if (areEqual(color, new char[6]{"blond"})) {
        return student::color::blond;
    } else if (areEqual(color, new char[4]{"red"})) {
        return student::color::red;
    } else if (areEqual(color, new char[6]{"white"})) {
        return student::color::white;
    }
    return student::color::blond;
}

void printStudent(student s){
    std::cout << "Name: " << s.name << " " << s.surname << std::endl;
    std::cout << "FN: " << s.fn << std::endl;
    std::cout << "Grade: " << s.grade << std::endl;
    std::cout << "Hair color: " << colorToString(s.hairColor) << std::endl;
}

student initStudent(const char name[16], const char surname[16] , const char fn[6] , double grade, const char* hairColor ) {
    student s;
    for (int i = 0; i < 16; i++) {
        s.name[i] = name[i];
        s.surname[i] = surname[i];
    }
    for (int i = 0; i < 6; i++) {
        s.fn[i] = fn[i];
    }
    s.grade = grade;
    s.hairColor = stringToColor(hairColor);
    return s;
}

student consoleToStudent(){
    char name[16];
    char surname[16];
    char fn[6];
    double grade;
    char hairColor[6];
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter surname: ";
    std::cin >> surname;
    std::cout << "Enter fn: ";
    std::cin >> fn;
    std::cout << "Enter grade: ";
    std::cin >> grade;
    std::cout << "Enter hair color: ";
    std::cin >> hairColor;
    char fdsa[16]  = "fda";
    return initStudent(name, surname, fn, grade, hairColor);
}
//
//int main() {
//
//    student s = consoleToStudent();
//    printStudent(s);
//    return 0;
//}

