#pragma once

#include <vector>
#include "Room.h"
#include "DayReservation.h"

class Month {
private:
    int month;
    int daysInMonth;
    std::vector<DayReservation> days;

    void generateDays(const int);

public:

    Month(const int, const int);

    ~Month();

    const int getMonthNumber() const;

    const int getDays() const;

    DayReservation *getReservationDay(const int);
};
