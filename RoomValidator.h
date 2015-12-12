#ifndef SEMESTRALKA_ROOMVALIDATOR_H
#define SEMESTRALKA_ROOMVALIDATOR_H

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

#endif //SEMESTRALKA_ROOMVALIDATOR_H
