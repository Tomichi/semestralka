/**
 * @file    DateValidatorException.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class InvalidDateException
 *
 * This file contains prototype of InvalidDateException class
 */

#ifndef SEMESTRALKA_DATEVALIDATOREXCEPTION_H
#define SEMESTRALKA_DATEVALIDATOREXCEPTION_H

#include <stdexcept>

/**
 * Invalid Date Exception
 */
class InvalidDateException : public std::invalid_argument
{
public:
    /**
     * Default contructor
     *
     * @param string of message
     */
    InvalidDateException(const std::string &reason);
};


#endif //SEMESTRALKA_DATEVALIDATOREXCEPTION_H
