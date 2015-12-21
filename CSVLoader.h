/**
 * @file    CSVLoader.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class CSVLoader
 *
 * This file contains prototype of CSVLoader class
 */
#ifndef SEMESTRALKA_CSVLOADER_H
#define SEMESTRALKA_CSVLOADER_H

#include <fstream>
#include <string>
#include <sstream>
#include "Hotel.h"
#include "BookingCalendar.h"
#include "RoomValidatorException.h"
#include "Room.h"

/**
 * CSV Loader
 */
class CSVLoader {
private:
    std::string file;
public:
    /**
     * Default contructor
     *
     * @param sorce filename
     */
    CSVLoader(const char *);

    /* Destructor */
    ~CSVLoader();

    /**
     * Fuction which parse input room csv file
     *
     * @param hotel
     */
    void parseRoomToHotel(Hotel &);

    /**
     * Fuction which parse reservation
     *
     * @param hotel
     * @param bookingCalendar
     */
    void parseReservation(Hotel &, BookingCalendar &);
};


#endif //SEMESTRALKA_CSVLOADER_H
