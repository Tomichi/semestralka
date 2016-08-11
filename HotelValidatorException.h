#pragma once

#include <stdexcept>

class DuplicateIdRoomException : public std::invalid_argument {
    public:
        DuplicateIdRoomException(const std::string &reason);
};
