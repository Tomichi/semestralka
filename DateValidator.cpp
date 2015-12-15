#include "DateValidator.h"

bool DateValidator::isDateValidate(const int year, const int month, const int day) {
    return DateValidator::isYearValidate(year)
           && DateValidator::isMonthValidate(month)
           && DateValidator::isDayValidate(year, month, day);
}
void DateValidator::validateDate(const int year, const int month, const int day) {
    if (!DateValidator::isDateValidate(year, month, day)) {
        throw InvalidDateException("Invalid date" + std::to_string(year) +
                                           "-" +std::to_string(month) + "-" + std::to_string(day));
    }
}

bool DateValidator::isYearValidate(const int year) {
    return year >= 2015 && year <= 2017;
}

bool DateValidator::isMonthValidate(const int month) {
    return month <= 12 && month > 0;
}

bool DateValidator::isDayValidate(const int year, const int month, const int day) {
    bool isLeapYear = Year::isLeapYear(year);
    int daysInCurrentMonth = daysInMonths[month - 1];
    if (month == 2 && isLeapYear) ++daysInCurrentMonth;

    return day <= daysInCurrentMonth && day > 0;

}