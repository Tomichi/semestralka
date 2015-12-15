#ifndef SEMESTRALKA_HOTEL_H
#define SEMESTRALKA_HOTEL_H

#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "Room.h"
#include "HotelValidatorException.h"

struct SearchResult {
public:
    SearchResult(const bool, const int);
    ~SearchResult();
    const bool getFound() const;
    const int getIndex() const;

private:
    int index;
    bool found;
};

class Hotel {
    private:
        std::vector<Room> database;
    public:
        Hotel();
        ~Hotel();
        void pushRoomToDatabase(Room &);
        void sortRoomsById();
        std::vector<Room> * getRooms();
        static const bool compareRoomsById(Room &, Room &);
        bool isIdRoomDuplicate(const int index);
        void roomValidate(const int);
        SearchResult findRoomInHotels(const int);
};


#endif //SEMESTRALKA_HOTEL_H
