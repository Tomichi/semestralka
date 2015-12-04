
#include "RoomException.h"

using namespace std;

InvalidRoomIdException::InvalidRoomIdException(const std::string &reason): invalid_argument(reason) { }

InvalidPrizeException::InvalidPrizeException(const std::string &reason): invalid_argument(reason) { }

InvalidCapacityException::InvalidCapacityException(const std::string &reason): invalid_argument(reason) { }
