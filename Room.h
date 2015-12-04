#ifndef SEMESTRALKA_ROOM_H
#define SEMESTRALKA_ROOM_H

#include "RoomValidator.h"

struct RoomLocation {
    private:
        int floor;
        int door;
    public:
        RoomLocation(const int , const int);
        ~RoomLocation();
        int getFloor();
        int getDoor();
};

class Room {
    private:
        RoomLocation *location = nullptr;
        int id;
        int capacity;
        int prize;
        void validateInput(const int &, const int &, const int &);
    public:
        Room(const int, const int, const int, const int, const int);
        Room(const int, const int, const int, RoomLocation);
        ~Room();

        // getters
        int getId();
        int getCapacity();
        int getPrize();
        RoomLocation getRoomLocation();
};

#endif //SEMESTRALKA_ROOM_H
