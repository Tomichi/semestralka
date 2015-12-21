/**
 * @file    Room.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class Room
 *
 * This file contains prototype of Room class
*/
#ifndef SEMESTRALKA_ROOM_H
#define SEMESTRALKA_ROOM_H

/**
 * Room RoomLocation
 */
struct RoomLocation {
private:
    int floor;
    int door;
public:
    /* Default constructor */
    RoomLocation();

    /**
     * Constructor
     *
     * @parameter number floor
     * @parameter number door
     */
    RoomLocation(const int, const int);

    /**
     * Destructor
     */
    ~RoomLocation();

    /**
     * This function get number of floor
     *
     * @return number of floor
     */
    const int getFloor() const;

    /**
     * This function get number of door
     *
     * @return number of door
     */
    const int getDoor() const;
};

/**
 * Room
 */
class Room {
private:
    RoomLocation location;
    int id;
    int capacity;
    int prize;
public:
    /**
     * Constructor
     *
     * @parameter number id
     * @parameter number capacity
     * @parameter number prize
     * @parameter number floor
     * @parameter number door
     */
    Room(const int, const int, const int, const int, const int);

    /**
     * Constructor
     *
     * @parameter number id
     * @parameter number capacity
     * @parameter number prize
     * @parameter number floor
     * @parameter number door
     */
    Room(const int, const int, const int, RoomLocation);

    /* Destructor */
    ~Room();

    /**
     * This function return number room id
     *
     * @return number room id
     */
    const int getId() const;

    /**
     * This function return number room capacity
     *
     * @return number capacity id
     */
    const int getCapacity() const;

    /**
     * This function return room prize
     *
     * @return number room prize
     */
    const int getPrize() const;

    /**
     * This function return RoomLocation
     *
     * @return RoomLocation struct
     */
    const RoomLocation &getRoomLocation() const;
};

#endif //SEMESTRALKA_ROOM_H
