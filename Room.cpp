#include "Room.h"
#include "RoomValidator.h"
#include "RoomException.h"
#include "RoomException.cpp"
#include "RoomValidator.cpp"

RoomLocation::RoomLocation(const int floor, const int door) {
    this->floor = floor;
    this->door = door;
}

int RoomLocation::getDoor() {
    return door;
}

int RoomLocation::getFloor() {
    return floor;
}

RoomLocation::~RoomLocation() { }

Room::Room(const int id, const int capacity, const int prize, const int floor, const int door) {
    RoomValidator::validateInput(id, prize, capacity);
    this->id = id;
    this->capacity = capacity;
    this->prize = prize;
    this->location = new RoomLocation(floor, door);
}

Room::Room(const int id, const int capacity, const int prize, RoomLocation location) {
    RoomValidator::validateInput(id, prize, capacity);
    this->id = id;
    this->capacity = capacity;
    this->prize = prize;
    this->location = new RoomLocation(location.getFloor(), location.getDoor());
}

Room::~Room() {
    delete this->location;
    this->location = nullptr;
}

// getters
int Room::getId() {
    return this->id;
}

int Room::getCapacity() {
    return this->capacity;
}

int Room::getPrize() {
    return this->prize;
}

RoomLocation Room::getRoomLocation() {
    return *location;
}
