#pragma once

#include <stdexcept>

class InvalidDateException : public std::invalid_argument
{
public:
    InvalidDateException(const std::string &reason);
};

