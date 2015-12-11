#include "HotelValidator.h"

HotelValidator::HotelValidator() { }

HotelValidator::~HotelValidator() { }

bool HotelValidator::isIdRoomDuplicate(const std::vector<Room*> database, const int index) {
    SearchResult result = SearchEngine::findRoomInHotels(database, index);
    return result.getFound();
}

void HotelValidator::roomValidate(const std::vector<Room*> database, const int index) {
    if (HotelValidator::isIdRoomDuplicate(database, index)) {
        throw DuplicateIdRoomException("Room with id#" + std::to_string(index) + " is duplicate.");
    }
}