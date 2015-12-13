#ifndef SEMESTRALKA_MONTH_H
#define SEMESTRALKA_MONTH_H
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
        void bookingRoomToDay(const int, Room &);
        DayReservation * getReservationDay(const int);
};


#endif //SEMESTRALKA_MONTH_H
