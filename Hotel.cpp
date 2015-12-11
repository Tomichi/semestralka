#include "Hotel.h"
#include <vector>
#include <Room.h>

Hotels::Hotels() { }

Hotels::~Hotels() {
    this->database.clear();
}

void Hotels::pushRoomToDatabase(Room * &) {
    HotelValidator::validateRoom(database, (*room)->getId());
    this->database.push_back(room);
}
