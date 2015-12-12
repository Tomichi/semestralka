#ifndef SEMESTRALKA_DAYRESERVATION_H
#define SEMESTRALKA_DAYRESERVATION_H

#include "Room.h"
#include <vector>

class DayReservation {
    private:
        int day;
        std::vector<Room *> booking;
    public:
        DayReservation(const int);
        ~DayReservation();
        const int getNumberDay() const;
        const std::vector<Room *> * getReserveRooms() const;
        void reserveDay(Room &);
        const bool isReservationEmpty() const;
};


#endif //SEMESTRALKA_DAYRESERVATION_H
