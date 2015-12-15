#include "DateValidatorException.h"

InvalidDateException::InvalidDateException(const std::string &reason) : std::invalid_argument(reason) { }