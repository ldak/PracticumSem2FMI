//
// Created by MILEN_PC on 3/31/2023.
//

#include "DateTime.h"

DateTime::DateTime(unsigned hour, unsigned minute, unsigned second, unsigned day, unsigned month, unsigned year) {
    this->date = Date(day, month, year);
    this->time = Time(hour, minute, second);
}

void DateTime::print() {
    this->date.print();
    std::cout << " ";
    this->time.print(false);
    std::cout << std::endl;

}

bool DateTime::isBefore(const DateTime& other) const {
    if (this->date.isBefore(other.date))
        return true;

    if(this->date.isEqualTo(other.date) && this->time.isBefore(other.time))
        return true;

    return false;
}
