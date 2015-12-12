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

        const std::vector<Room *> * getReserveRooms() const;

        void reserveDay(Room * &);


};


#endif //SEMESTRALKA_DAYRESERVATION_H
