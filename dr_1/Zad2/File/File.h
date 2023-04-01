//
// Created by MILEN_PC on 3/31/2023.
//

#ifndef PRACTUCUMSEM2_FILE_H
#define PRACTUCUMSEM2_FILE_H


#include "../DateTime/DateTime.h"
#include "../Consts/ConfigConsts.h"
#include "../RightsManager/RightsManager.h"
#include "../SortOptions/SortOptions.h"

class File {
private:
    char fileName[Consts::FILE_NAME]{};
    char content[Consts::FILE_CONTENT]{'\0'};
    unsigned size = 0;
    DateTime creationDate;
    DateTime lastModifiedDate;
    RightsManager rightsManager{};

    void addContent(const char* content);
public:
    File() = default;
    File(const char* fileName,
         unsigned hour,
         unsigned minute,
         unsigned second,
         unsigned day,
         unsigned month,
         unsigned year,
         const char* rights);

    void edit(const char* content,
              unsigned hour,
              unsigned minute,
              unsigned second,
              unsigned day,
              unsigned month,
              unsigned year,
              char role);

    void addText(const char* content,
                 unsigned hour,
                 unsigned minute,
                 unsigned second,
                 unsigned day,
                 unsigned month,
                 unsigned year,
                 char role);



    void setName(const char* name);
    void setContent(const char* content);
    void setCreationDate(unsigned hour,
                         unsigned minute,
                         unsigned second,
                         unsigned day,
                         unsigned month,
                         unsigned year);
    void setLastModifiedDate(unsigned hour,
                             unsigned minute,
                             unsigned second,
                             unsigned day,
                             unsigned month,
                             unsigned year);
    void setRights(const char* rights);
    const char* getName() const;

    void changeRight(char role, char right);

    void printInfo();

    void printContent();

    bool canDelete(char role);

    bool isBefore(const File& file, SortOptions option) const;
};


#endif //PRACTUCUMSEM2_FILE_H
