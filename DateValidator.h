/**
 * @file    DateValidator.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class DateValidator
 *
 * This file contains prototype of DateValidator class
 */
#ifndef SEMESTRALKA_DATEVALIDATOR_H
#define SEMESTRALKA_DATEVALIDATOR_H

#include "Year.h"
#include "DateValidatorException.h"

/**
 * Date Validator
 */
class DateValidator {
private:
    /* Default contructor */
    DateValidator();

    /* Desctructor */
    ~DateValidator();

public:
    /**
     * This function validate date
     *
     * @param year
     * @param month
     * @param day
     *
     * @return bool
     */
    static bool isDateValidate(const int, const int, const int);

    /**
     * This function validate date if not throw exception
     *
     * @param year
     * @param month
     * @param day
     */
    static void validateDate(const int, const int, const int);

    /**
     * This function validate year if is in range
     *
     * @param year
     *
     * @return bool
     */
    static bool isYearValidate(const int);

    /**
     * This function validate month
     *
     * @param month
     *
     * @return bool
     */
    static bool isMonthValidate(const int);

    /**
     * This function validate day
     *
     * @param year
     * @param month
     * @param day
     *
     * @return bool
     */
    static bool isDayValidate(const int, const int, const int);
};


#endif //SEMESTRALKA_DATEVALIDATOR_H
