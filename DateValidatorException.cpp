/**
 * @file    DateValidatorException.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class InvalidDateException
 *
 * This file contains implementation of InvalidDateException class
 */
#include "DateValidatorException.h"

// Default constructor
InvalidDateException::InvalidDateException(const std::string &reason) : std::invalid_argument(reason) { }