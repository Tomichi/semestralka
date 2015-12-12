#ifndef SEMESTRALKA_HOTELVALIDATOREXCEPTION_H
#define SEMESTRALKA_HOTELVALIDATOREXCEPTION_H

#include <stdexcept>

class DuplicateIdRoomException : public std::invalid_argument {
    public:
        DuplicateIdRoomException(const std::string &reason);
};

#endif //SEMESTRALKA_HOTELVALIDATOREXCEPTION_H
