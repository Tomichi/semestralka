/**
 * @file    RoomValidatorException.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of classes InvalidRoomIdException, InvalidPrizeException, InvalidCapacityException
 *
 * This file contains prototype of InvalidRoomIdException class, InvalidPrizeException class, InvalidCapacityException class
 */
#ifndef SEMESTRALKA_ROOMEXCEPTION_H
#define SEMESTRALKA_ROOMEXCEPTION_H

#include <stdexcept>

/**
 * Invalid Room Id Exception
 */
class InvalidRoomIdException : public std::invalid_argument {
public:
    /*
     * Default constructor
     *
     * @param string of message
     */
    InvalidRoomIdException(const std::string &reason);
};

/**
 * Invalid Prize Exception
 */
class InvalidPrizeException : public std::invalid_argument {
public:
    /*
     * Default constructor
     *
     * @param string of message
     */
    InvalidPrizeException(const std::string &reason);
};

/**
 * Invalid Capacity Exception
 */
class InvalidCapacityException : public std::invalid_argument {
public:
    /*
     * Default constructor
     *
     * @param string of message
     */
    InvalidCapacityException(const std::string &reason);
};

#endif //SEMESTRALKA_ROOMEXCEPTION_H
