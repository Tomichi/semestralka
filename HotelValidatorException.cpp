#include "HotelValidatorException.h"

DuplicateIdRoomException::DuplicateIdRoomException(const std::string &reason): std::invalid_argument(reason) { }