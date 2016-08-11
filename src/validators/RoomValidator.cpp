#include "RoomValidator.h"

RoomValidator::RoomValidator() {}

RoomValidator::~RoomValidator() {}


void RoomValidator::validateInput(const int &id, const int &prize, const int &capacity) {
    if (!RoomValidator::isIdValid(id)) {
        throw InvalidRoomIdException("id#" + std::to_string(id) + " is not valid.");
    }

    if (!RoomValidator::isCapacityValid(capacity)) {
        throw InvalidCapacityException("Capacity "+ std::to_string(capacity) +" of id#" + std::to_string(id) + " is not valid.");
    }

    if (!RoomValidator::isPrizeValid(prize)) {
        throw InvalidPrizeException("Prize "+ std::to_string(prize) +" of id#" + std::to_string(id) + " is not valid.");
    }
}

bool RoomValidator::isIdValid(const int & id) {
    return id > 0;
}

bool RoomValidator::isPrizeValid(const int & prize) {
    return prize > 0;
}

bool RoomValidator::isCapacityValid(const int & capacity) {
    return capacity > 0;
}

