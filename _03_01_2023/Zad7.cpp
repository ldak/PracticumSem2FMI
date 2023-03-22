//
// Created by MILEN_PC on 3/8/2023.
//
#include "iostream"
#include "fstream"

struct System{
    struct User{
        char email[128];
        char password[32];
    };
    User users[100]{};
    int usersCount = 0;
};

void loadSystem(System& system, std::fstream& file){
    if (!file.is_open()){
        return;
    }
    int& i = system.usersCount;
    while (!file.eof()){
        file >> system.users[i].email;
        file >> system.users[i].password;
        i++;
    }
}

void printMenu(){

}

void saveSystem(const System& system, std::fstream& file){
    if (!file.is_open()){
        return;
    }
    for (int i = 0; i < system.usersCount; ++i) {
        file << system.users[i].email << " " << system.users[i].password << std::endl;
    }
}

int main(){
    System system;
    std::fstream file("users.txt");
    loadSystem(system, file);





    saveSystem(system, file);
    file.close();

    return 0;
}