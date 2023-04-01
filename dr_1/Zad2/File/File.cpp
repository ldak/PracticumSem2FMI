//
// Created by MILEN_PC on 3/31/2023.
//

#include <cstring>
#include "File.h"

File::File(const char *fileName, unsigned hour, unsigned minute, unsigned second, unsigned day, unsigned month,
           unsigned year, const char *rights) {
    this->setName(fileName);
    this->setCreationDate(hour, minute, second, day, month, year);
    this->setRights(rights);
}



void File::edit(const char *content, unsigned hour, unsigned minute, unsigned second, unsigned day,
                unsigned month, unsigned year, char role) {
    if (!this->rightsManager.canWrite(role)) {
        std::cout << "Error! You don't have permission to edit this file!" << std::endl;
        return;
    }
    this->setContent(content);
    this->setLastModifiedDate(hour, minute, second, day, month, year);
}


void File::addText(const char *content, unsigned int hour, unsigned int minute, unsigned int second, unsigned int day,
                   unsigned int month, unsigned int year, char role) {
    if (!this->rightsManager.canWrite(role)) {
        std::cout << "Error! You don't have permission to edit this file!" << std::endl;
        return;
    }

    this->addContent(content);
    this->setLastModifiedDate(hour, minute, second, day, month, year);

}


const char *File::getName() const {
    return this->fileName;
}

void File::setName(const char *name) {
    strcpy(this->fileName, name);
}

void File::setContent(const char *content) {
    strcpy(this->content, content);
    this->size = strlen(content);
}

void File::setCreationDate(unsigned hour, unsigned minute, unsigned second, unsigned day, unsigned month,
                      unsigned year) {
    this->creationDate = DateTime(hour, minute, second, day, month, year);

}

void File::setLastModifiedDate(unsigned hour, unsigned minute, unsigned second, unsigned day,
                               unsigned month, unsigned year) {
    this->lastModifiedDate = DateTime(hour, minute, second, day, month, year);
}

void File::setRights(const char *rights) {
    this->rightsManager = RightsManager(rights);
}

void File::addContent(const char *content) {
    int i = 0;
    while(content[i] != '\0'){
        this->content[this->size + i] = content[i];
        i++;
    }
    this->content[this->size + i] = '\0';
    this->size = strlen(this->content);
}

void File::changeRight(char role, char right) {
    this->rightsManager.changeRight(role, right);

}

void File::printInfo() {
    std::cout << "File name: " << this->fileName << std::endl;
    std::cout << "File size: " << this->size << std::endl;
    std::cout << "File creation date: ";
    this->creationDate.print();
    std::cout << "File last modified date: ";
    this->lastModifiedDate.print();
    std::cout << "File rights: ";
    this->rightsManager.print();
}

void File::printContent() {
    std::cout << "File content: " << std::endl;
    std::cout << this->content << std::endl;
}

bool File::canDelete(char role) {
    return this->rightsManager.canExecute(role);
}

bool File::isBefore(const File& other, SortOptions option) const {
    if (option == SortOptions::NAME)
        return strcmp(this->fileName, other.fileName) < 0;

    if (option == SortOptions::CREATION_DATE)
        return this->creationDate.isBefore(other.creationDate);

    if (option == SortOptions::MODIFICATION_DATE)
        return this->lastModifiedDate.isBefore(other.lastModifiedDate);

    if (option == SortOptions::SIZE)
        return this->size < other.size;

    return false;
}


