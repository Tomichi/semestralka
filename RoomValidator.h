/**
 * @file    RoomValidator.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class RoomValidator
 *
 * This file contains prototype of RoomValidator class
*/
#ifndef SEMESTRALKA_ROOMVALIDATOR_H
#define SEMESTRALKA_ROOMVALIDATOR_H

#include <string>
#include "RoomValidatorException.h"

class RoomValidator {
private:
    /* Default constructor */
    RoomValidator();

    /* Destructor */
    ~RoomValidator();

public:
    /**
     * This function return information if id is vali
     *
     * @paramater id
     *
     * @return bool
     */
    static bool isIdValid(const int &);

    /**
     * This function return information if id is vali
     *
     * @parameter prize
     *
     * @return bool
     */
    static bool isPrizeValid(const int &);

    /**
     * This function return information if id is vali
     *
     * @parameter capacity
     *
     * @return bool
     */
    static bool isCapacityValid(const int &);

    /**
     * This function validate input parameters of room
     * if parameters did not correct it throws exception
     *
     * @parameter number id
     * @parameter number capacity
     * @parameter number prize
     */
    static void validateInput(const int &, const int &, const int &);
};

#endif //SEMESTRALKA_ROOMVALIDATOR_H
