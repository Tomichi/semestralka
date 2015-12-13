#ifndef SEMESTRALKA_YEAR_H
#define SEMESTRALKA_YEAR_H
#include <vector>
#include "Month.h"

static int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Year {
    private:
        int year;
        std::vector<Month> months;
        const bool isLeapYear() const;
    public:
        Year(const int);
        ~Year();
        const int getYearNumber() const;
        std::vector<Month> & getMonths();
        void generateMonths();

};


#endif //SEMESTRALKA_YEAR_H
