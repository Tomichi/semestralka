#ifndef SEMESTRALKA_HOTEL_H
#define SEMESTRALKA_HOTEL_H

#include <vector>
#include <algorithm>
#include "Room.h"
#include "HotelValidator.h"

class Hotel {
    private:
        std::vector<Room> database;
    public:
        Hotel();
        ~Hotel();
        void pushRoomToDatabase(Room &);
        void sortRoomsById();
        std::vector<Room> & getRooms();
        static const bool compareRoomsById(Room &, Room &);
};


#endif //SEMESTRALKA_HOTEL_H
