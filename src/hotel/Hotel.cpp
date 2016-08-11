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


std::vector<Room> *Hotel::getRooms() {
    return &(this->database);
}

SearchResult Hotel::findRoomInHotels(const int id) {
    bool found = false;
    int indexFound = -1;

    for (std::vector<Room>::iterator it = this->database.begin(); it != this->database.end() && !found; ++it) {
        if (it->getId() == id) {
            found = true;
            indexFound = it - this->database.begin();
        }
    }

    return SearchResult(found, indexFound);
}

bool Hotel::isIdRoomDuplicate(const int id) {
    SearchResult result = this->findRoomInHotels(id);

    return result.getFound();
}

void Hotel::roomValidate(const int id) {
    if (this->isIdRoomDuplicate(id)) {
        throw DuplicateIdRoomException("Room with id#" + std::to_string(id) + " is duplicate.");
    }
}

Room & Hotel::getRoomByIndex(const int index) {
    return this->database.at(index);
}
