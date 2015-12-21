/**
 * @file    DateValidator.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class DateValidator
 *
 * This file contains implementation of DateValidator class
 */

#include "DateValidator.h"

bool DateValidator::isDateValidate(const int year, const int month, const int day) {
    // Validate year, month and day
    return DateValidator::isYearValidate(year)
           && DateValidator::isMonthValidate(month)
           && DateValidator::isDayValidate(year, month, day);
}


void DateValidator::validateDate(const int year, const int month, const int day) {
    // If date is not valid i throw exception
    if (!DateValidator::isDateValidate(year, month, day)) {
        throw InvalidDateException("Invalid date" + std::to_string(year) +
                                           "-" +std::to_string(month) + "-" + std::to_string(day));
    }
}

bool DateValidator::isYearValidate(const int year) {
    // validate year if in current range
    return year >= 2015 && year <= 2017;
}

bool DateValidator::isMonthValidate(const int month) {
    // validate month
    return month <= 12 && month > 0;
}

bool DateValidator::isDayValidate(const int year, const int month, const int day) {
    // Control if year is leap
    bool isLeapYear = Year::isLeapYear(year);

    // Get days in month
    int daysInCurrentMonth = daysInMonths[month - 1];

    // Control if not february in leap year
    if (month == 2 && isLeapYear) ++daysInCurrentMonth;

    // validate number day
    return day <= daysInCurrentMonth && day > 0;

}