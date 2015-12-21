/**
 * @file    RoomValidatorException.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of classes InvalidRoomIdException, InvalidPrizeException, InvalidCapacityException
 *
 * This file contains implementation of InvalidRoomIdException class, InvalidCapacityException class. InvalidPrizeException class
 */
#include "RoomValidatorException.h"

// Default construct
InvalidRoomIdException::InvalidRoomIdException(const std::string &reason): std::invalid_argument(reason) { }

// Default construct
InvalidPrizeException::InvalidPrizeException(const std::string &reason): std::invalid_argument(reason) { }

// Default construct
InvalidCapacityException::InvalidCapacityException(const std::string &reason): std::invalid_argument(reason) { }
