//
// Created by MILEN_PC on 3/31/2023.
//

#include <cstring>
#include "FileSystem.h"

FileSystem::FileSystem(unsigned filesCount) {
    this->filesCount = filesCount;
    this->files = new File[filesCount];
}

FileSystem::FileSystem(const FileSystem &other) {
    copyFrom(other);
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

int FileSystem::findFile(const char *fileName) const {
    for (int i = 0; i < this->filesCount; ++i) {
        if (strcmp(this->files[i].getName(), fileName) == 0) {
            return i;
        }
    }
    return -1;
}

