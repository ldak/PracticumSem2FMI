//
// Created by MILEN_PC on 3/31/2023.
//

#ifndef PRACTUCUMSEM2_FILE_H
#define PRACTUCUMSEM2_FILE_H


#include "../DateTime/DateTime.h"
#include "../Consts/ConfigConsts.h"
#include "../RightsManager/RightsManager.h"

class File {
private:
    char fileName[Consts::FILE_NAME]{};
    char content[Consts::FILE_CONTENT]{};
    unsigned size = 0;
    DateTime creationDate;
    DateTime lastModifiedDate;
    RightsManager rightsManager{};
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

    const char* getName() const;
};


#endif //PRACTUCUMSEM2_FILE_H
