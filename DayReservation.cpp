#include "DayReservation.h"

DayReservation::DayReservation(const int day) {
    this->day = day;
}

DayReservation::~DayReservation() {
    for (int i = 0; i < (int) this->booking.size(); i++) {
        this->booking.pop_back();
    }
}

void DayReservation::reserveDay(Room &room) {
    if (this->isRoomAlreadyRegistered(room)) {
        throw RoomIsAlreadyRegisteredOnThisDayException("Room with id#" + std::to_string(room.getId())+
        " is already registered in day#" + std::to_string(this->day));
    }
    this->booking.push_back(&room);
}

const int DayReservation::getNumberDay() const {
    return this->day;
}

const bool DayReservation::isReservationEmpty() const {
    return this->booking.size() == 0;
}

bool DayReservation::isRoomAlreadyRegistered(Room & room) {
    if (this->isReservationEmpty()) {
        return false;
    }

    return std::find(this->booking.begin(), this->booking.end(), &room) != this->booking.end();
}