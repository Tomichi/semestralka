#include "Hotel.h"
#include <iterator>

SearchResult::SearchResult(const bool found, const int index) {
    this->found = found;
    this->index = index;
}

SearchResult::~SearchResult() { }

const bool SearchResult::getFound() const {
    return this->found;
}

const int SearchResult::getIndex() const {
    return this->index;
}

Hotel::Hotel() { }

Hotel::~Hotel() {
    this->database.clear();
}

void Hotel::pushRoomToDatabase(Room &room) {
    this->roomValidate(room.getId());
    this->database.push_back(room);
}

void Hotel::sortRoomsById() {
    std::sort(this->database.begin(), this->database.end(), this->compareRoomsById);
}

const bool Hotel::compareRoomsById(Room &room1, Room &room2) {
    return room1.getId() < room2.getId();
}

std::vector<Room> *Hotel::getRooms() {
    return &(this->database);
}

SearchResult Hotel::findRoomInHotels(const int index) {
    bool found = false;
    int indexFound = -1;

    for (std::vector<Room>::iterator it = this->database.begin(); it != this->database.end() && !found; ++it) {
        if (it->getId() == index) {
            found = true;
            indexFound = it - this->database.begin();
        }
    }

    return SearchResult(found, indexFound);
}

bool Hotel::isIdRoomDuplicate(const int index) {
    SearchResult result = this->findRoomInHotels(index);
    return result.getFound();
}

void Hotel::roomValidate(const int index) {
    if (this->isIdRoomDuplicate(index)) {
        throw DuplicateIdRoomException("Room with id#" + std::to_string(index) + " is duplicate.");
    }
}

Room & Hotel::getRoomByIndex(const int index) {
    return this->database.at(index);
}