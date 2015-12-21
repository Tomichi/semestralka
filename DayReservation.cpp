/**
 * @file    DateValidatorException.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class InvalidDateException
 *
 * This file contains implementation of DateValidator class
 */
#include "DayReservation.h"

DayReservation::DayReservation(const int day) {
    // Set property
    this->day = day;
}

DayReservation::~DayReservation() {
    // Free memmory from booking
    for (int i = 0; i < (int) this->booking.size(); i++) {
        this->booking.pop_back();
    }
}

void DayReservation::reserveDay(Room &room) {
    // Control if room has been already registered if yes it throws exception
    if (this->isRoomAlreadyRegistered(room)) {
        throw RoomIsAlreadyRegisteredOnThisDayException("Room with id#" + std::to_string(room.getId())+
        " is already registered in day#" + std::to_string(this->day));
    }
    // Reserve room adress
    this->booking.push_back(&room);
}

const int DayReservation::getNumberDay() const {
    // Return number of day
    return this->day;
}

const bool DayReservation::isReservationEmpty() const {
    // Test reservation if it is empty
    return this->booking.size() == 0;
}

bool DayReservation::isRoomAlreadyRegistered(Room & room) {
    // Control if reservation is not empty
    if (this->isReservationEmpty()) {
        return false;
    }

    // Find room in booking day
    return std::find(this->booking.begin(), this->booking.end(), &room) != this->booking.end();
}