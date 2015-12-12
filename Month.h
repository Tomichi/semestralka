#ifndef SEMESTRALKA_MONTH_H
#define SEMESTRALKA_MONTH_H
#include <vector>
#include "DayReservation.h"


class Month {
    private:
        int month;
        std::vector<DayReservation> days;
        void generateDays(const int);
    public:

        Month(const int, const int);

        ~Month();

        const int getMonthNumber() const;

        const std::vector<DayReservation> &getDays() const;

        void bookingRoomToDay(const int, Room &);
};


#endif //SEMESTRALKA_MONTH_H
