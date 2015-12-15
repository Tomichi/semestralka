#ifndef SEMESTRALKA_DATEVALIDATOR_H
#define SEMESTRALKA_DATEVALIDATOR_H

#include "Year.h"
#include "DateValidatorException.h"

class DateValidator {
    private:
        DateValidator();
        ~DateValidator();

    public:
        static bool isDateValidate(const int, const int, const int);
        static void validateDate(const int, const int, const int);
        static bool isYearValidate(const int);
        static bool isMonthValidate(const int);
        static bool isDayValidate(const int, const int, const int);
};


#endif //SEMESTRALKA_DATEVALIDATOR_H
