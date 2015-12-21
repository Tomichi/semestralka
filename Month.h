/**
 * @file    Month.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class Month
 *
 * This file contains prototype of Month class
*/
#ifndef SEMESTRALKA_MONTH_H
#define SEMESTRALKA_MONTH_H

#include <vector>
#include "Room.h"
#include "DayReservation.h"

/**
 * Month
 */
class Month {
private:
    int month;
    int daysInMonth;
    std::vector<DayReservation> days;

    /**
     * This funtion generate days in month
     *
     * @parameter days
     */
    void generateDays(const int);

public:
    /**
     * Default constructor
     *
     * @parameter number of mounth
     * @parameter number of days in month
     */
    Month(const int, const int);

    /* Destructor */
    ~Month();

    /**
     * This function get month number
     *
     * @return number of month
     */
    const int getMonthNumber() const;

    /**
     * This function get days in month
     *
     * @return number of days in month
     */
    const int getDays() const;

    /**
     * This function return pointer of reservation day
     *
     * @parameter number of day
     *
     * @return pointer of day reservation
     */
    DayReservation *getReservationDay(const int);
};


#endif //SEMESTRALKA_MONTH_H
