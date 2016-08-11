#pragma once

#include <stdexcept>

class InvalidRoomIdException : public std::invalid_argument {
public:
    InvalidRoomIdException(const std::string &reason);
};

class InvalidPrizeException : public std::invalid_argument {
public:

    InvalidPrizeException(const std::string &reason);
};

class InvalidCapacityException : public std::invalid_argument {
public:
    InvalidCapacityException(const std::string &reason);
};
