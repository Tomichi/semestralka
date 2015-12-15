cmake_minimum_required(VERSION 3.3)
project(semestralka)

include_directories(semestralka)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        Room.cpp Room.h
        BookingCalendar.cpp BookingCalendar.h
        CSVLoader.cpp CSVLoader.h
        DateValidator.cpp DateValidator.h
        DateValidatorException.cpp DateValidatorException.h
        DayReservation.cpp DayReservation.h
        DayReservationException.cpp DayReservationException.h
        Hotel.cpp Hotel.h
        HotelValidatorException.cpp HotelValidatorException.h
        Month.cpp Month.h
        RoomValidator.cpp RoomValidator.h
        RoomValidatorException.cpp RoomValidatorException.h
        Year.cpp Year.h
        )
add_executable(semestralka ${SOURCE_FILES})
add_subdirectory(tests)