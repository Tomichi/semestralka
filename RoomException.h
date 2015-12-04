#ifndef SEMESTRALKA_ROOMEXCEPTION_H
#define SEMESTRALKA_ROOMEXCEPTION_H

#include <string>
#include <stdexcept>

using namespace std;

class InvalidRoomIdException : public invalid_argument
{
    public:
        InvalidRoomIdException(const string &reason);
};

class InvalidPrizeException : public invalid_argument
{
    public:
        InvalidPrizeException(const string &reason);
};

class InvalidCapacityException : public invalid_argument
{
    public:
        InvalidCapacityException(const string &reason);
};

#endif //SEMESTRALKA_ROOMEXCEPTION_H
