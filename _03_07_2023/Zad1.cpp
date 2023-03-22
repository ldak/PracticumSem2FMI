#include "iostream"
#include "fstream"

struct Class{
    struct Student{
        char firstName[16];
        char lastName[16];
        char fn[6];
        double grade;
        enum class color {brown, black, blond, red, white} hairColor;
    };
    Student students[1024]{};
    int studentsCount = 0;
};

void writeClassToFile(std::ofstream &ofs, Class &class1){
    if (!ofs.is_open()){
        return;
    }
    for (int i = 0; i < class1.studentsCount; ++i) {
        ofs.write((char*)&class1.students[i], sizeof(Class::Student));
    }
}



int main(){
    Class class1;

    std::ofstream ofs("students.csv", std::ios::out | std::ios::binary);
    writeClassToFile(ofs, class1);


    return 0;
}
