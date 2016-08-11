#pragma once

#include <string>
#include "RoomValidatorException.h"

class RoomValidator {
private:
    RoomValidator();

    ~RoomValidator();

public:
    static bool isIdValid(const int &);

    static bool isPrizeValid(const int &);

    static bool isCapacityValid(const int &);

    static void validateInput(const int &, const int &, const int &);
};
