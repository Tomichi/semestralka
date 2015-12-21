/**
 * @file    Hotel.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class Hotel
 *
 * This file contains prototype of Hotel class
*/

#ifndef SEMESTRALKA_HOTEL_H
#define SEMESTRALKA_HOTEL_H

#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "Room.h"
#include "HotelValidatorException.h"

/**
 * Search Result
 */
struct SearchResult {
public:
    /**
     * Default constructor
     *
     * @param found
     * @param index in vector
     */
    SearchResult(const bool, const int);

    /* Destructor */
    ~SearchResult();

    /**
     * Getter function of found
     *
     * @return bool
     */
    const bool getFound() const;

    /**
     * Getter function of index from vector
     *
     * @return index
     */
    const int getIndex() const;

private:
    int index;
    bool found;
};

/**
 * Hotel
 */
class Hotel {

private:
    std::vector<Room> database;
public:
    /* Default constructor */
    Hotel();

    /* Destructor */
    ~Hotel();

    /**
     * This function register and push room to database of rooms
     *
     * @param room
     */
    void pushRoomToDatabase(Room &);

    /**
     * This getter function return pointer to vector all rooms
     *
     * @return pointer of room vector
     */
    std::vector<Room> *getRooms();

    /**
     * This function find room if not duplicate
     *
     * @return bool
     */
    bool isIdRoomDuplicate(const int index);

    /**
     * This function validate room according
     * id if not duplicate.
     *
     * @param id of room
     */
    void roomValidate(const int);

    /**
     * This function return information about
     * find index and result which is room located
     * in database
     *
     * @param id room
     *
     * @return SearchResult struct
     */
    SearchResult findRoomInHotels(const int);

    /**
     * This function return room from
     * index from database
     *
     * @param index from database
     *
     * @return address to Room object
     */
    Room &getRoomByIndex(const int);
};


#endif //SEMESTRALKA_HOTEL_H
