#ifndef SEMESTRALKA_CSVLOADER_H
#define SEMESTRALKA_CSVLOADER_H

#include <fstream>
#include <string>
#include <sstream>
#include "Hotel.h"
#include "BookingCalendar.h"
#include "Room.h"

class CSVLoader {
    private:
        std::ifstream ifs;
        char * source;
    public:
        CSVLoader(const char *);
        ~CSVLoader();
        void parseRoomToHotel(Hotel &);
        void parseReservation(Hotel &, BookingCalendar &);
};


#endif //SEMESTRALKA_CSVLOADER_H
