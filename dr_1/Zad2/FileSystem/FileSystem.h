//
// Created by MILEN_PC on 3/31/2023.
//

#ifndef PRACTUCUMSEM2_FILESYSTEM_H
#define PRACTUCUMSEM2_FILESYSTEM_H


#include "../File/File.h"

class FileSystem {
private:
    File* files;
    size_t filesCount;

    void copyFrom(const FileSystem& other);
    void free();

    int findFile(const char* fileName) const;
public:
    explicit FileSystem(unsigned filesCount);

    void addFile(const char* fileName,
                 unsigned hour,
                 unsigned minute,
                 unsigned second,
                 unsigned day,
                 unsigned month,
                 unsigned year,
                 const char* rights);

    void editFile(const char* fileName,
                  const char* content,
                  unsigned hour,
                  unsigned minute,
                  unsigned second,
                  unsigned day,
                  unsigned month,
                  unsigned year,
                  char role);


    FileSystem() = delete;
    FileSystem(const FileSystem& other);
    FileSystem& operator=(const FileSystem& other);
    ~FileSystem();


};


#endif //PRACTUCUMSEM2_FILESYSTEM_H
