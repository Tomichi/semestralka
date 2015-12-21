/**
 * @file    HotelValidatorException.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class DuplicateIdRoomException
 *
 * This file contains implementation of DuplicateIdRoomException class
 */
#include "HotelValidatorException.h"

// Default construct
DuplicateIdRoomException::DuplicateIdRoomException(const std::string &reason): std::invalid_argument(reason) { }