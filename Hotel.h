#ifndef SEMESTRALKA_HOTEL_H
#define SEMESTRALKA_HOTEL_H

#include <vector>
#include "Room.h"
#include "HotelValidator.h"

class Hotels{
    private:
        std::vector<Room*> database;
    public:
        Hotels();
        ~Hotels();
        void pushRoomToDatabase(Room * &);
};


#endif //SEMESTRALKA_HOTEL_H
