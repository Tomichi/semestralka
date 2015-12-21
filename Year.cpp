/**
 * @file    Year.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class Year
 *
 * This file contains implementation of Year class
 */
#include "Year.h"
#include "Month.h"

Year::Year(const int year) {
    // Setup parameters
    this->year = year;
    this->generateMonths();
}

Year::~ Year() {
    // Clear month
    this->months.clear();
}

const int Year::getYearNumber() const {
    // Return number of year
    return this->year;
}

std::vector<Month> &Year::getMonths() {
    // Return vector of month
    return this->months;
}

void Year::generateMonths() {
    // Generate all month with days in year
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
    // Control if current year is leap
    return (this->year % 4 == 0 && this->year % 100 != 0)
           || (this->year % 400 == 0 && this->year % 4000 != 0);
}

bool Year::isLeapYear(const int currentYear) {
    // Control if input year is leap
    return (currentYear % 4 == 0 && currentYear % 100 != 0)
           || (currentYear % 400 == 0 && currentYear % 4000 != 0);
}

Month * Year::getMonth(const int month) {
    // Return poniter of input number month
    return &(this->months.at(month - 1));
}
