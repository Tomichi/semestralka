#pragma once

struct RoomLocation {
private:
    int floor;
    int door;
public:
    RoomLocation();

    RoomLocation(const int, const int);

    ~RoomLocation();

    const int getFloor() const;

    const int getDoor() const;
};

class Room {
private:
    RoomLocation location;
    int id;
    int capacity;
    int prize;
public:

    Room(const int, const int, const int, const int, const int);

    Room(const int, const int, const int, RoomLocation);

    ~Room();

    const int getId() const;

    const int getCapacity() const;

    const int getPrize() const;

    const RoomLocation &getRoomLocation() const;
};
