#pragma once
#include <stdexcept>

class RoomIsAlreadyRegisteredOnThisDayException : public std::runtime_error
{
public:
    RoomIsAlreadyRegisteredOnThisDayException(const std::string &reason);
};
