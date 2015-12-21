/**
 * @file    DayReservationException.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class RoomIsAlreadyRegisteredOnThisDayException
 *
 * This file contains implementation of RoomIsAlreadyRegisteredOnThisDayException class
 */
#include "DayReservationException.h"

// Default constructor
RoomIsAlreadyRegisteredOnThisDayException::RoomIsAlreadyRegisteredOnThisDayException(const std::string &reason)
        : std::runtime_error(reason) { }