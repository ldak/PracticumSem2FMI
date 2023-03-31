//
// Created by MILEN_PC on 3/31/2023.
//

#include <cstring>
#include "File.h"

File::File(const char *fileName, unsigned hour, unsigned minute, unsigned second, unsigned day, unsigned month, unsigned year, const char *rights) {
    strcpy(this->fileName, fileName);
    this->creationDate = DateTime(hour, minute, second, day, month, year);


}

const char* File::getName() const{
    return this->fileName;
}

void File::edit(const char *content, unsigned hour, unsigned minute, unsigned second, unsigned day,
                unsigned month, unsigned year, char role) {
    if(!this->rightsManager.canWrite(role)){
        std::cout << "Error! You don't have permission to edit this file!" << std::endl;
        return;
    }
    strcpy(this->content, content);
    this->lastModifiedDate = DateTime(hour, minute, second, day, month, year);
}
