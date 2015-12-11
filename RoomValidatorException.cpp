#include "RoomValidatorException.h"

InvalidRoomIdException::InvalidRoomIdException(const std::string &reason): std::invalid_argument(reason) { }

InvalidPrizeException::InvalidPrizeException(const std::string &reason): std::invalid_argument(reason) { }

InvalidCapacityException::InvalidCapacityException(const std::string &reason): std::invalid_argument(reason) { }
