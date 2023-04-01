//
// Created by MILEN_PC on 3/31/2023.
//

#ifndef PRACTUCUMSEM2_DATETIME_H
#define PRACTUCUMSEM2_DATETIME_H


#include "../Date/Date.h"
#include "../Time/Time.h"

class DateTime {
private:
    Date date;
    Time time;
public:
    DateTime() = default;
    DateTime(unsigned hour, unsigned minute, unsigned second, unsigned day, unsigned month, unsigned year);


    void print();

    bool isBefore(const DateTime& time) const;
};


#endif //PRACTUCUMSEM2_DATETIME_H
