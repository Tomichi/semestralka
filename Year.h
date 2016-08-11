#pragma once

#include <vector>
#include "Month.h"

static int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Year {
    private:
        int year;
        std::vector<Month> months;

        const bool isLeapYear() const;

        void generateMonths();
public:

        Year(const int);

        ~Year();

        const int getYearNumber() const;

        std::vector<Month> & getMonths();

        Month * getMonth(const int);

        static bool isLeapYear(const int);
};

