#ifndef SEMESTRALKA_HOTELVALIDATOR_H
#define SEMESTRALKA_HOTELVALIDATOR_H

#include "Hotel.h"
#include "SearchEngine.h"
#include "HotelValidatorException.h"

class HotelValidator {
private:
    HotelValidator();

    ~HotelValidator();

public:
    static bool isIdRoomDuplicate(const std::vector<Room *>, const int);

    static void roomValidate(const std::vector<Room *>, const int);
};

#endif //SEMESTRALKA_HOTELVALIDATOR_H
