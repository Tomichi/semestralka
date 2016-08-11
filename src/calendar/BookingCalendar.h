#pragma once
#include "Year.h"
#include "../hotel/Hotel.h"
#include "../hotel/Room.h"
#include "DayReservation.h"
#include "../validators/DateValidator.h"
#include <vector>

class BookingCalendar {
private:
    std::vector<Year> years;

    DayReservation *getDayByDate(const int, const int, const int);

    void addYear(const int);

    void generateNextYearIsPossible(const int);

public:
    BookingCalendar(const int);

    ~BookingCalendar();

    void reserveRoom(Room &, const int, const int, const int);

    Year *getYear(const int);

    void findFreeRoomInDay(Hotel &, const int, const int, const int, std::vector<Room> &);

    void findFreeRoomInDayByPrize(Hotel &, const int, const int, const int, const int, std::vector<Room> &);

    void findFreeRoomInDayByCapacity(Hotel &, const int, const int, const int, const int, std::vector<Room> &);

    void findRoomByDateRange(Room &, const int, const int, const int, const int, const int, const int,
                             std::vector<std::string> &);
};
