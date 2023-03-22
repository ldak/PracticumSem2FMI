//
// Created by MILEN_PC on 3/8/2023.
//
#include "iostream"
#include "fstream"


void writeToFile(){
    std::ofstream file("file.txt");
    int a, b, c;
    std::cin >> a >> b >> c;
    file << a*b*c << ' ' << a+b+c;
    file.close();
}

void readFromFile(){
    std::ifstream file("file.txt");
    int a, b;
    file >> a >> b;
    std::cout << a << ' ' << b;
}

int main(){
    writeToFile();
    readFromFile();

    return 0;
}