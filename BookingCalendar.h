#ifndef SEMESTRALKA_BOOKINGCALENDAR_H
#define SEMESTRALKA_BOOKINGCALENDAR_H
#include "Year.h"
#include "Hotel.h"
#include "Room.h"
#include "DayReservation.h"
#include "DateValidator.h"
#include <vector>

class BookingCalendar {
    private:
        std::vector<Year> years;
        void addYear(const int);
        void generateNextYearIsPossible(const int );
        DayReservation * getDayByDate(const int, const int, const int);
public:
        BookingCalendar(const int);
        ~BookingCalendar();
        void generateNextYear(const int); // must be private !!!
        void reserveRoom(Room &, const int, const int, const int);
        const std::vector<Room*> * getRoomReservationByDate(const int, const int, const int);
        Year * getYear(const int);
        void findFreeRoomInDay(Hotel &, const int, const int, const int, std::vector<Room> &);
        void findFreeRoomInDayByPrize(Hotel &, const int, const int, const int, const int, std::vector<Room> &);
};


#endif //SEMESTRALKA_BOOKINGCALENDAR_H
