#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "../hotel/Hotel.h"
#include "../calendar/BookingCalendar.h"
#include "../validators/RoomValidatorException.h"
#include "../hotel/Room.h"

class CSVLoader {
private:
    std::string file;
public:
    CSVLoader(const char *);

    ~CSVLoader();

    void parseRoomToHotel(Hotel &);

    void parseReservation(Hotel &, BookingCalendar &);
};
