//
// Created by MILEN_PC on 3/8/2023.
//
#include "iostream"
#include "fstream"

long long lengthOfFile(std::ifstream& file){
    if (!file.is_open()){
        return -1;
    }

    long long currentPos = file.tellg();
    file.seekg(0, std::ios::end);
    long long length = file.tellg();
    file.seekg(currentPos);
    return length;
}

int main() {
    std::ifstream file("file.txt");
    std::cout << lengthOfFile(file);

    return 0;
}