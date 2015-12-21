/**
 * @file    DateValidatorEception.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class RoomIsAlreadyRegisteredOnThisDayException
 *
 * This file contains prototype of RoomIsAlreadyRegisteredOnThisDayException class
 */

#ifndef SEMESTRALKA_DAYRESERVATIONEXCEPTION_H
#define SEMESTRALKA_DAYRESERVATIONEXCEPTION_H

#include <stdexcept>

/**
 * Room Is Already Registered On This Day Exception
 */
class RoomIsAlreadyRegisteredOnThisDayException : public std::runtime_error
{
public:
    /**
     * Default constructor
     *
     * @param string message
     */
    RoomIsAlreadyRegisteredOnThisDayException(const std::string &reason);
};

#endif //SEMESTRALKA_DAYRESERVATIONEXCEPTION_H
