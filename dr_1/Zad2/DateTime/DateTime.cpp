//
// Created by MILEN_PC on 3/31/2023.
//

#include "DateTime.h"

DateTime::DateTime(unsigned hour, unsigned minute, unsigned second, unsigned day, unsigned month, unsigned year) {
    this->date = Date(day, month, year);
    this->time = Time(hour, minute, second);
}
