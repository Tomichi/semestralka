#pragma once
#include "../calendar/Year.h"
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
