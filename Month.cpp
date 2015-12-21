/**
 * @file    Month.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class Month
 *
 * This file contains implementation of Month class
 */
#include "Month.h"

Month::Month(const int month, const int days) {
    // Setup parameters
    this->month = month;
    this->generateDays(days);
    this->daysInMonth = days;
}

Month::~Month() {
    // Clear vector which contains all days in month
    this->days.clear();
}


const int Month::getDays() const {
    // Return vector of all days in month
    return this->daysInMonth;
}

void Month::generateDays(const int days) {
    // Generate all days in month and push it do
    // class store vector
    for (int i = 1; i <= days; i++) {
        DayReservation day(i);
        this->days.push_back(day);
    }
}

const int Month::getMonthNumber() const {
    // Return number of month
    return this->month;
}

DayReservation * Month::getReservationDay(const int day) {
    // Return pointer of reservation day
    return &(this->days.at(day - 1));
}