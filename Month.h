#ifndef SEMESTRALKA_MONTH_H
#define SEMESTRALKA_MONTH_H
#include <vector>
#include "Room.h"
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
        std::vector<DayReservation> &getDays();

        void bookingRoomToDay(const int, Room &);
        const std::vector<Room*> * getRoomsFromDays(const int day) const;
};


#endif //SEMESTRALKA_MONTH_H
