#ifndef SEMESTRALKA_BOOKINGCALENDAR_H
#define SEMESTRALKA_BOOKINGCALENDAR_H
#include "Year.h"
#include "Hotel.h"
#include "Room.h"
#include "DayReservation.h"
#include <vector>

class BookingCalendar {
    private:
        std::vector<Year> years;
        void addYear(const int);
        void generateNextYearIsPossible(const int );
    public:
        BookingCalendar(const int);
        ~BookingCalendar();
        void generateNextYear(const int);
        const std::vector<Year> & getYears() const;
        void reserveRoom(Room &, const int, const int, const int);
        const std::vector<Room*> * getRoomReservationByDate(const int, const int, const int);
        std::vector<Room> findFreeRoomInDay(Hotel &, const int, const int, const int);
};


#endif //SEMESTRALKA_BOOKINGCALENDAR_H
