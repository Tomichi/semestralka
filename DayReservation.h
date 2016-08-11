#pragma once

#include "Room.h"
#include "DayReservationException.h"
#include <string>
#include <vector>
#include <algorithm>

class DayReservation {

private:
    int day;
    std::vector<Room *> booking;
public:

    DayReservation(const int);

    ~DayReservation();

    const int getNumberDay() const;

    void reserveDay(Room &);

    const bool isReservationEmpty() const;

    bool isRoomAlreadyRegistered(Room &);
};
