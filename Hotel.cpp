#include "Hotel.h"


Hotel::Hotel() {
}

Hotel::~Hotel() {
    if (!this->database.empty()) {
        for (int i = 0; i < this->database.size(); i++) {
            delete this->database[i];
        }
    }
    this->database.clear();
}

void Hotel::pushRoomToDatabase(Room *room) {
    HotelValidator::roomValidate(database, (*room).getId());
    this->database.push_back(room);
}

void Hotel::sortRoomsById() {
    std::sort(this->database.begin(), this->database.end(), this->compareRoomsById);
}

const bool Hotel::compareRoomsById(Room * room1, Room * room2) {
    return room1->getId() < room2->getId();
}

const std::vector<Room *> & Hotel::getRooms() const {
    return this->database;
}