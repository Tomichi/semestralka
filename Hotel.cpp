/**
 * @file    Hotel.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class Hotel
 *
 * This file contains implementation of Hotel class
 */

#include "Hotel.h"
#include <iterator>

SearchResult::SearchResult(const bool found, const int index) {
    // Set property
    this->found = found;
    this->index = index;
}

SearchResult::~SearchResult() { }

const bool SearchResult::getFound() const {
    // return property found
    return this->found;
}

const int SearchResult::getIndex() const {
    // return property index
    return this->index;
}

Hotel::Hotel() { }

Hotel::~Hotel() {
    // Clear database
    this->database.clear();
}

void Hotel::pushRoomToDatabase(Room &room) {
    // Validate room if not duplicate
    this->roomValidate(room.getId());
    this->database.push_back(room);
}


std::vector<Room> *Hotel::getRooms() {
    // Return pointer to vector room to database
    return &(this->database);
}

SearchResult Hotel::findRoomInHotels(const int id) {
    // Set default value if room doesnt exist
    bool found = false;
    int indexFound = -1;

    // Iterate for each room store in database and compare id
    for (std::vector<Room>::iterator it = this->database.begin(); it != this->database.end() && !found; ++it) {
        if (it->getId() == id) {
            found = true;
            indexFound = it - this->database.begin();
        }
    }

    // Return result
    return SearchResult(found, indexFound);
}

bool Hotel::isIdRoomDuplicate(const int id) {
    // Control if room is duplicate
    SearchResult result = this->findRoomInHotels(id);

    // Return result
    return result.getFound();
}

void Hotel::roomValidate(const int id) {
    // Control room if is duplicate it throws exception
    if (this->isIdRoomDuplicate(id)) {
        throw DuplicateIdRoomException("Room with id#" + std::to_string(id) + " is duplicate.");
    }
}

Room & Hotel::getRoomByIndex(const int index) {
    // Return room stored in database on according
    return this->database.at(index);
}