#include "Year.h"
#include "Month.h"

Year::Year(const int year) {
    this->year = year;
    this->generateMonths();
}

Year::~Year() {
    this->months.clear();
}

const int Year::getYearNumber() const {
    return this->year;
}

std::vector<Month> &Year::getMonths() {
    return this->months;
}

void Year::generateMonths() {
    for (int i = 1; i < 13; i++) {
        int leapDay = 0;
        if (i == 2 && this->isLeapYear()) {
            leapDay = 1;
        }
        Month month(i, daysInMonths[i - 1] + leapDay);
        this->months.push_back(month);
    }
}

const bool Year::isLeapYear() const {
    return (this->year % 4 == 0 && this->year % 100 != 0)
           || (this->year % 400 == 0 && this->year % 4000 != 0);
}
