/**
 * @file    DayReservation.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class DayReservation
 *
* This file contains prototype of DayReservation class
 */

#ifndef SEMESTRALKA_DAYRESERVATION_H
#define SEMESTRALKA_DAYRESERVATION_H

#include "Room.h"
#include "DayReservationException.h"
#include <string>
#include <vector>
#include <algorithm>

/**
 * Day Reservation
 */
class DayReservation {

private:
    int day;
    std::vector<Room *> booking;
public:
    /**
     * Default constructor
     *
     * @param day
     */
    DayReservation(const int);

    /**
     * Destructor
     */
    ~DayReservation();

    /**
     * This getter function return number of day
     *
     * @return number of day
     */
    const int getNumberDay() const;

    /**
     * This function reserve room for actual day
     * if room is already reserved it throws exception
     *
     * @param room
     */
    void reserveDay(Room &);

    /**
     * This function is for find information if
     * the day is empty for reservation
     *
     * @return bool
     */
    const bool isReservationEmpty() const;

    /**
     * This function find information if room
     * has been already registered on this day
     *
     * @param room
     *
     * @return bool
     */
    bool isRoomAlreadyRegistered(Room &);
};


#endif //SEMESTRALKA_DAYRESERVATION_H
