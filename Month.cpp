#include "Month.h"

Month::Month(const int month, const int days) {
    this->month = month;
    this->generateDays(days);
    this->daysInMonth = days;
}

Month::~Month() {
    this->days.clear();
}


const int Month::getDays() const {
    return this->daysInMonth;
}

void Month::generateDays(const int days) {
    for (int i = 1; i <= days; i++) {
        DayReservation day(i);
        this->days.push_back(day);
    }
}

const std::vector<Room*> * Month::getRoomsFromDays(const int day) const {
    return this->days.at(day - 1).getReserveRooms();
}

const int Month::getMonthNumber() const {
    return this->month;
}

void Month::bookingRoomToDay(const int day, Room & room) {
    if (day > this->days.size() || day < 1) {

    } else {
        this->days.at(day - 1).reserveDay(room);
    }
}


DayReservation * Month::getReservationDay(const int day) {
    return &(this->days.at(day - 1));
}