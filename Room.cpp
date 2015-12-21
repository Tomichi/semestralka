/**
 * @file    Room.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class Room
 *
 * This file contains implementation of Room class
 */
#include "Room.h"
#include "RoomValidator.h"

RoomLocation::RoomLocation(const int floor, const int door) {
    // Setup parameter
    this->floor = floor;
    this->door = door;
}

RoomLocation::RoomLocation() {
    // Setup default parameter
    this->floor = 0;
    this->door = 0;
}

const int RoomLocation::getDoor() const {
    // Return number of door
    return door;
}

const int RoomLocation::getFloor() const {
    // Return number od floor
    return floor;
}

RoomLocation::~RoomLocation() { }

Room::Room(const int id, const int capacity, const int prize, const int floor, const int door) {
    // Validate input parameter if will be problem, I throws exception
    RoomValidator::validateInput(id, prize, capacity);

    // Setup parameters
    this->id = id;
    this->capacity = capacity;
    this->prize = prize;
    RoomLocation tmpLocation(floor, door);
    this->location = tmpLocation;
}

Room::Room(const int id, const int capacity, const int prize, RoomLocation location) {
    // Validate input parameter if will be problem, I throws exception
    RoomValidator::validateInput(id, prize, capacity);

    // Setup parameters
    this->id = id;
    this->capacity = capacity;
    this->prize = prize;
    this->location = location;
}

Room::~Room() { }

const int Room::getId() const {
    // Return id of room
    return this->id;
}

const int Room::getCapacity() const {
    // Return capacity of room
    return this->capacity;
}

const int Room::getPrize() const {
    // Return prize of room
    return this->prize;
}

const RoomLocation &Room::getRoomLocation() const {
    // Return struct location of room
    return location;
}
