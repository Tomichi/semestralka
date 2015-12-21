/**
 * @file    BookingCalendar.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class BookingCalendar
 *
 * This file contains prototype of BookingCalendar class
 */
#ifndef SEMESTRALKA_BOOKINGCALENDAR_H
#define SEMESTRALKA_BOOKINGCALENDAR_H

#include "Year.h"
#include "Hotel.h"
#include "Room.h"
#include "DayReservation.h"
#include "DateValidator.h"
#include <vector>

/**
 * Booking Calendar
 */
class BookingCalendar {
private:
    std::vector<Year> years;

    DayReservation *getDayByDate(const int, const int, const int);

    /**
     * This function generate next year and push it years vector
     *
     * @param year
     */
    void addYear(const int);

    /**
     * This function check if it possible generate
     * next input year
     *
     * @param year
     */
    void generateNextYearIsPossible(const int);

public:
    /**
     * Default constructor
     *
     * @param year
     */
    BookingCalendar(const int);

    /** Destructor */
    ~BookingCalendar();

    /**
     * This function reerve room to current day
     *
     * @param Room
     * @param year
     * @param month
     * @param day
     */
    void reserveRoom(Room &, const int, const int, const int);

    /**
     * Getter for returning number of year
     *
     * @param year
     * @return number of year
     */
    Year *getYear(const int);

    /**
     * This function find free room in current date
     * and push it to input room vector
     *
     * @param Hotel
     * @param year
     * @param month
     * @param day
     * @param vector Room
     */
    void findFreeRoomInDay(Hotel &, const int, const int, const int, std::vector<Room> &);

    /**
     * This function find free room in current date limited by max prize
     * and push it to input room vector
     *
     * @param Hotel
     * @param prize
     * @param year
     * @param month
     * @param day
     * @param vector Room
     */
    void findFreeRoomInDayByPrize(Hotel &, const int, const int, const int, const int, std::vector<Room> &);

    /**
     * This function find free room in current date limited by max capacity
     * and push it to input room vector
     *
     * @param Hotel
     * @param capacity
     * @param year
     * @param month
     * @param day
     * @param vector Room
     */
    void findFreeRoomInDayByCapacity(Hotel &, const int, const int, const int, const int, std::vector<Room> &);

    /**
     * This function find bookin room in date interval and push
     * format date to string vector
     *
     * @param Hotel
     * @param prize
     * @param year start
     * @param month start
     * @param day start
     * @param year end
     * @param month end
     * @param day end
     * @param vector string date
     */
    void findRoomByDateRange(Room &, const int, const int, const int, const int, const int, const int,
                             std::vector<std::string> &);
};


#endif //SEMESTRALKA_BOOKINGCALENDAR_H
