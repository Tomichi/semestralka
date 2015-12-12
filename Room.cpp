#include "Room.h"
#include "RoomValidator.h"

RoomLocation::RoomLocation(const int floor, const int door) {
    this->floor = floor;
    this->door = door;
}

RoomLocation::RoomLocation() {
    this->floor = 0;
    this->door = 0;
}

const int RoomLocation::getDoor() const {
    return door;
}

const int RoomLocation::getFloor() const {
    return floor;
}

RoomLocation::~RoomLocation() { }

Room::Room(const int id, const int capacity, const int prize, const int floor, const int door) {
    RoomValidator::validateInput(id, prize, capacity);
    this->id = id;
    this->capacity = capacity;
    this->prize = prize;
    RoomLocation tmpLocation(floor, door);
    this->location = tmpLocation;
}

Room::Room(const int id, const int capacity, const int prize, RoomLocation location) {
    RoomValidator::validateInput(id, prize, capacity);
    this->id = id;
    this->capacity = capacity;
    this->prize = prize;
    this->location = location;
}

Room::~Room() { }

const int Room::getId() const {
    return this->id;
}

const int Room::getCapacity() const {
    return this->capacity;
}

const int Room::getPrize() const {
    return this->prize;
}

const RoomLocation &Room::getRoomLocation() const {
    return location;
}
