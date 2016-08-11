#include "DayReservationException.h"

RoomIsAlreadyRegisteredOnThisDayException::RoomIsAlreadyRegisteredOnThisDayException(const std::string &reason)
        : std::runtime_error(reason) { }