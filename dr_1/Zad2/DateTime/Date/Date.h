/**
 * Source: https://github.com/Angeld55/Object-oriented_programming_FMI/tree/master/Week%2005/Date
 */

#pragma once
#include <iostream>

class Date
{
	unsigned MAX_DAYS[12] =
	{
		31,28,31,30,31, 30, 31, 31, 30, 31, 30, 31
	};
	unsigned day = 1;
	unsigned month = 1;
	unsigned year = 1;

	bool isLeapYear() const;

	mutable bool isModified = true;
	mutable int dayOfWeek = -1;

public:
    Date() = default;
	Date(unsigned day, unsigned month, unsigned year);
	unsigned getDay() const;
	unsigned getMonth() const;
	unsigned getYear() const;

	void setDay(unsigned day);
	void setMonth(unsigned month);
	void setYear(unsigned year);

	bool isEqualTo(const Date& d) const;
    bool isBefore(const Date& other) const;

	void print() const;
	void goToNextDay();
	int getDayOfWeek() const;

};
