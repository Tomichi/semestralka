/**
 * @file    HotelValidatorException.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class DuplicateIdRoomException
 *
 * This file contains prototype of DuplicateIdRoomException class
 */
#ifndef SEMESTRALKA_HOTELVALIDATOREXCEPTION_H
#define SEMESTRALKA_HOTELVALIDATOREXCEPTION_H

#include <stdexcept>
/**
 * Duplicate Id RoomException
 */
class DuplicateIdRoomException : public std::invalid_argument {
    public:
        /*
         * Default constructor
         *
         * @param string of message
         */
        DuplicateIdRoomException(const std::string &reason);
};

#endif //SEMESTRALKA_HOTELVALIDATOREXCEPTION_H
