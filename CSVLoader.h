#ifndef SEMESTRALKA_CSVLOADER_H
#define SEMESTRALKA_CSVLOADER_H

#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "Hotel.h"
#include "BookingCalendar.h"
#include "RoomValidatorException.h"
#include "Room.h"

class CSVLoader {
    private:
        std::string file;
    public:
        CSVLoader(const char *);
        ~CSVLoader();
        void parseRoomToHotel(Hotel &);
        void parseReservation(Hotel &, BookingCalendar &);
};


#endif //SEMESTRALKA_CSVLOADER_H
