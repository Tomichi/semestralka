#ifndef SEMESTRALKA_DAYRESERVATIONEXCEPTION_H
#define SEMESTRALKA_DAYRESERVATIONEXCEPTION_H


#include <stdexcept>

class RoomIsAlreadyRegisteredOnThisDayException : public std::runtime_error
{
public:
    RoomIsAlreadyRegisteredOnThisDayException(const std::string &reason);
};


#endif //SEMESTRALKA_DAYRESERVATIONEXCEPTION_H
