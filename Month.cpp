#include "Month.h"

Month::Month(const int month, const int days) {
    this->month = month;
    // test if days is valid
    this->generateDays(days);
}

Month::~Month() {
    this->days.clear();
}

void Month::generateDays(const int days) {
    for (int i = 1; i <= days; i++) {
        DayReservation day(i);
        this->days.push_back(day);
    }
}
const std::vector<DayReservation> & Month::getDays() const {
    return this->days;
}

const int Month::getMonthNumber() const {
    return this->month;
}

void Month::bookingRoomToDay(const int day, Room & room) {
    if (day > this->days.size() || day < 1) {

    } else {
        this->days[day - 1].reserveDay(room);
    }
}
