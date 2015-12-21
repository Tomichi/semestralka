/**
 * @file    BookingCalendar.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class BookingCalendar
 *
 * This file contains implementation of BookingCalendar class
 */

#include "BookingCalendar.h"


BookingCalendar::BookingCalendar(const int year) {
    // Initialize variables
    this->addYear(year);
}

BookingCalendar::~BookingCalendar() {
    // Clear memory
    this->years.clear();
}

void BookingCalendar::addYear(const int year) {
    // Create new year
    Year newYear(year);

    // Push year to global years vector
    this->years.push_back(newYear);
}

void BookingCalendar::generateNextYearIsPossible(const int year) {
    // Count is year only one
    bool isOneYearInCalendar = this->years.size() == 1;
    // Validate if input year is curent year + 1
    bool isNextYearEqualNextYear = this->years.at(0).getYearNumber() + 1 == year;

    // If variables are true will be generate new year
    if (isOneYearInCalendar && isNextYearEqualNextYear) {
        this->addYear(year);
    }
}

void BookingCalendar::reserveRoom(Room &room, const int year, const int month, const int day) {
    // Validate input date
    DateValidator::validateDate(year, month, day);
    this->generateNextYearIsPossible(year);

    // Get room object
    DayReservation * dayReservation = this->getDayByDate(year, month, day);

    // Reserve room to input date
    dayReservation->reserveDay(room);
    dayReservation = NULL;
}

Year * BookingCalendar::getYear(const int year) {
    // Set first year in calendar
    const int startYearInPositionCalendar = this->years.at(0).getYearNumber();

    // Set number of years in calendar
    const int countYearsInCalendar = (int) this->years.size();

    // If year smaller than calendar begin year throw exception
    if (year < startYearInPositionCalendar) {
        throw "year is not in calendar";
    }

    // Contorl if year in calendar
    int yearDiff = startYearInPositionCalendar - year;
    if (yearDiff > countYearsInCalendar) {
        throw "year is not in calendar";
    }

    // Create temporary Year pointer and return them
    Year * result = NULL;
    for(int i = 0; i < countYearsInCalendar; i++) {
        if (year != this->years.at(i).getYearNumber()) continue;
        result =  &(this->years.at(i));
    }

    return result;

}

DayReservation * BookingCalendar::getDayByDate(const int year, const int month, const int day) {
    // Validate input date
    DateValidator::validateDate(year, month, day);

    // Create temporary pointer
    Year * actualYear = this->getYear(year);
    Month * actualMonth = actualYear->getMonth(month);

    // Get current day from function input parameters
    DayReservation * actualDay = actualMonth->getReservationDay(day);

    // Parking temporary pointers
    actualYear = NULL;
    actualMonth = NULL;

    return actualDay;
}

void BookingCalendar::findFreeRoomInDay(Hotel & hotel, const int year, const int month, const int day,
                                                       std::vector<Room> &result) {
    // Validate input date
    DateValidator::validateDate(year, month, day);

    // Create poniter vector rooms which included all register rooms
    std::vector<Room> *rooms = hotel.getRooms();

    // Get current day reservation from input date
    DayReservation * actualDay = this->getDayByDate(year, month, day);

    // Sequency iterate rooms in day if not search push it to result vector
    for (int i = 0; i < rooms->size(); i++) {
            if(!actualDay->isRoomAlreadyRegistered(rooms->at(i))) {
                result.push_back(rooms->at(i));
            }
    }

    // Parking temporary vector
    actualDay = NULL;
    rooms = NULL;
}

void BookingCalendar::findFreeRoomInDayByPrize(Hotel & hotel, const int prize, const int year, const int month, const int day, std::vector<Room> &result) {
    // Validate input date
    DateValidator::validateDate(year, month, day);

    // Create poniter vector rooms which included all register rooms
    std::vector<Room> *rooms = hotel.getRooms();

    // Get current day reservation from input date
    DayReservation * actualDay = this->getDayByDate(year, month, day);

    // Sequency iterate rooms in day if not search push it to result vector
    for (int i = 0; i < rooms->size(); i++) {
        if (rooms->at(i).getPrize() > prize) continue;
        if(!actualDay->isRoomAlreadyRegistered(rooms->at(i))) {
            result.push_back(rooms->at(i));
        }
    }

    // Parking temporary vector
    actualDay = NULL;
    rooms = NULL;
}


void BookingCalendar::findFreeRoomInDayByCapacity(Hotel & hotel, const int capacity, const int year, const int month, const int day, std::vector<Room> &result) {
    // Validate input date
    DateValidator::validateDate(year, month, day);

    // Create poniter vector rooms which included all register rooms
    std::vector<Room> *rooms = hotel.getRooms();

    // Get current day reservation from input date
    DayReservation * actualDay = this->getDayByDate(year, month, day);

    // Sequency iterate rooms in day if not search push it to result vector
    for (int i = 0; i < rooms->size(); i++) {
        if (rooms->at(i).getCapacity() > capacity) continue;
        if(!actualDay->isRoomAlreadyRegistered(rooms->at(i))) {
            result.push_back(rooms->at(i));
        }
    }

    // Parking temporary vector
    actualDay = NULL;
    rooms = NULL;
}

void BookingCalendar::findRoomByDateRange(Room & room, const int year1, const int month1, const int day1, const int year2, const int month2, const int day2, std::vector<std::string> &date) {
    // Validate input dates
    DateValidator::isDateValidate(year1, month1, day1);
    DateValidator::isDateValidate(year2, month2, day2);

    // Iterate from start date to end date
    for (int y = year1; y <= year2; y++) {

        for (int m = (y == year1) ? month1 : 1; m <= ((y == year2) ? month2: 12); m++) {

            for (int d = (y == year1 && m == month1) ? day1 : 1;
                    d <= ((y == year2 && m == month2) ? day2 : daysInMonths[m - 1]); d++) {

                DayReservation * reservation = this->getDayByDate(y, m, d);
                if (reservation->isReservationEmpty()) continue;
                if (reservation->isRoomAlreadyRegistered(room)) {
                    date.push_back(std::to_string(d) + "." + std::to_string(m) + "." + std::to_string(y));
                }
            }
        }
    }
}
