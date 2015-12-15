#ifndef SEMESTRALKA_DATEVALIDATOREXCEPTION_H
#define SEMESTRALKA_DATEVALIDATOREXCEPTION_H

#include <stdexcept>

class InvalidDateException : public std::invalid_argument
{
public:
    InvalidDateException(const std::string &reason);
};


#endif //SEMESTRALKA_DATEVALIDATOREXCEPTION_H
