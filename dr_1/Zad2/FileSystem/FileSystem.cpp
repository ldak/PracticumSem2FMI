//
// Created by MILEN_PC on 3/31/2023.
//

#include <cstring>
#include "FileSystem.h"

FileSystem::FileSystem(unsigned filesCount) {
    this->filesCount = 0;
    this->files = new File[filesCount];
}

FileSystem::FileSystem(const FileSystem &other) {
    copyFrom(other);
}

FileSystem &FileSystem::operator=(const FileSystem &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

FileSystem::~FileSystem() {
    free();
}

void FileSystem::addFile(const char *fileName,
                         unsigned hour,
                         unsigned minute,
                         unsigned second,
                         unsigned day,
                         unsigned month,
                         unsigned year,
                         const char *rights) {

    this->files[this->filesCount++] = File(fileName, hour, minute, second, day, month, year, rights);

}

void FileSystem::editFile(const char *fileName,
                          const char *content,
                          unsigned hour,
                          unsigned minute,
                          unsigned second,
                          unsigned day,
                          unsigned month,
                          unsigned year,
                          char role) {

    int index = this->findFile(fileName);
    if (index == -1){
        std::cout << "Error! File not found!" << std::endl;
        return;
    }

    this->files[index].edit(content, hour, minute, second, day, month, year, role);

}

void FileSystem::addTextToFile(const char *fileName, const char *content, unsigned int hour, unsigned int minute,
                               unsigned int second, unsigned int day, unsigned int month, unsigned int year,
                               char role) {
    int index = this->findFile(fileName);
    if (index == -1){
        std::cout << "Error! File not found!" << std::endl;
        return;
    }

    this->files[index].addText(content, hour, minute, second, day, month, year, role);
}


void FileSystem::deleteFile(const char *fileName, char role) {
    int index = this->findFile(fileName);
    if (index == -1){
        std::cout << "Error! File not found!" << std::endl;
        return;
    }
    if (!this->files[index].canDelete(role)){
        std::cout << "Error! You don't have permission to delete this file!" << std::endl;
        return;
    }
    for (int i = index + 1; i < this->filesCount; ++i) {
        this->files[i - 1] = this->files[i];
    }
    this->filesCount--;
}


void FileSystem::changeFileRights(const char *fileName, char role, char right) {
    int index = this->findFile(fileName);
    if (index == -1){
        std::cout << "Error! File not found!" << std::endl;
        return;
    }
    this->files[index].changeRight(role, right);

}

void FileSystem::copyFrom(const FileSystem &other) {
    this->filesCount = other.filesCount;
    this->files = new File[other.filesCount];
    for (size_t i = 0; i < other.filesCount; ++i) {
        this->files[i] = other.files[i];
    }
}

void FileSystem::free() {
    delete[] this->files;
    this->filesCount = 0;
}

void FileSystem::printFileInfo(const char *fileName, char role) const {
    int index = this->findFile(fileName);
    if (index == -1){
        std::cout << "Error! File not found!" << std::endl;
        return;
    }
    this->files[index].printInfo(role);

}

void FileSystem::printFileContent(const char *fileName, char role) const {
    int index = this->findFile(fileName);
    if (index == -1){
        std::cout << "Error! File not found!" << std::endl;
        return;
    }
    this->files[index].printContent(role);
}

void FileSystem::printAllFiles() const {
    for (int i = 0; i < this->filesCount; ++i) {
        std::cout << this->files[i].getName() << std::endl;
    }

}

void FileSystem::sort(SortOptions option) {
    for (int i = 0; i < this->filesCount ; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < this->filesCount; ++j) {
            if (this->files[j].isBefore(this->files[minIndex], option)){
                minIndex = j;
            }
        }
        File temp = this->files[i];
        this->files[i] = this->files[minIndex];
        this->files[minIndex] = temp;
    }
}


int FileSystem::findFile(const char *fileName) const {
    for (int i = 0; i < this->filesCount; ++i) {
        if (strcmp(this->files[i].getName(), fileName) == 0) {
            return i;
        }
    }
    return -1;
}
