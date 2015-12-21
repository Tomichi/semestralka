/**
 * @file    Year.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class Year
 *
 * This file contains prototype of Year class
*/
#ifndef SEMESTRALKA_YEAR_H
#define SEMESTRALKA_YEAR_H
#include <vector>
#include "Month.h"

// static array which contains numbers of days in month
static int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * Year
 */
class Year {
    private:
        int year;
        std::vector<Month> months;
        /**
         * Function which control if current year is leap
         *
         * @return bool
         */
        const bool isLeapYear() const;

        /**
         * This function generate months in current year
         */
        void generateMonths();
public:
        /**
         * Default constructor
         *
         * @parameter number of year
         */
        Year(const int);

        /* Destructor */
        ~Year();

        /**
         * This function return number of year
         *
         * @return number of year
         */
        const int getYearNumber() const;

        /**
         * This function return reference to vector
         * of all months in year
         *
         * @return reference to vector of all months store in year
         */
        std::vector<Month> & getMonths();

        /**
         * This function return pointer to month
         * according to number of month
         *
         * @parameter number of month
         *
         * @return pointer to month
         */
        Month * getMonth(const int);

        /**
         * This function control if input year is leap
         *
         * @parameter number of year
         *
         * @return bool
         */
        static bool isLeapYear(const int);
};


#endif //SEMESTRALKA_YEAR_H
