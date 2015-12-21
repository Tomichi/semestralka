/**
 * @file    RoomValidator.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class RoomValidator
 *
 * This file contains implementation of RoomValidator class
 */
#include "RoomValidator.h"

RoomValidator::RoomValidator() {}

RoomValidator::~RoomValidator() {}


void RoomValidator::validateInput(const int &id, const int &prize, const int &capacity) {
    // Control if id is valid if no it throws exception
    if (!RoomValidator::isIdValid(id)) {
        throw InvalidRoomIdException("id#" + std::to_string(id) + " is not valid.");
    }

    // Control if capacity is valid if no it throws exception
    if (!RoomValidator::isCapacityValid(capacity)) {
        throw InvalidCapacityException("Capacity "+ std::to_string(capacity) +" of id#" + std::to_string(id) + " is not valid.");
    }

    // Control if prize is valid if no it throws exception
    if (!RoomValidator::isPrizeValid(prize)) {
        throw InvalidPrizeException("Prize "+ std::to_string(prize) +" of id#" + std::to_string(id) + " is not valid.");
    }
}

bool RoomValidator::isIdValid(const int & id) {
    // Control if id is valid
    return id > 0;
}

bool RoomValidator::isPrizeValid(const int & prize) {
    // Control if prize is valid
    return prize > 0;
}

bool RoomValidator::isCapacityValid(const int & capacity) {
    // Control if capacity is valid
    return capacity > 0;
}

