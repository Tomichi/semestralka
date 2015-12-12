#include "DayReservation.h"

DayReservation::DayReservation(const int day) {
    this->day = day;
}

DayReservation::~DayReservation() {
    for (int i = 0; i < (int) this->booking.size(); i++) {
        booking.pop_back();
    }
}

void DayReservation::reserveDay(Room *&room) {
    this->booking.push_back(room);
}

const std::vector<Room *> *DayReservation::getReserveRooms() const {
    return &(this->booking);
}
