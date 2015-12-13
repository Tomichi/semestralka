#include "Hotel.h"

Hotel::Hotel() { }

Hotel::~Hotel() {
    this->database.clear();
}

void Hotel::pushRoomToDatabase(Room &room) {
    HotelValidator::roomValidate(database, room.getId());
    this->database.push_back(room);
}

void Hotel::sortRoomsById() {
    std::sort(this->database.begin(), this->database.end(), this->compareRoomsById);
}

const bool Hotel::compareRoomsById(Room & room1, Room & room2) {
    return room1.getId() < room2.getId();
}

std::vector<Room> * Hotel::getRooms() {
    return &(this->database);
}