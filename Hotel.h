#pragma once

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

    std::vector<Room> *getRooms();

    bool isIdRoomDuplicate(const int index);

    void roomValidate(const int);

    SearchResult findRoomInHotels(const int);

    Room &getRoomByIndex(const int);
};
