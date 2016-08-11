cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(semestralka)

include_directories(semestralka)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -Wall -pedantic")

set(SOURCE_FILES main.cpp
        src/hotel/Room.cpp src/hotel/Room.h
        src/calendar/BookingCalendar.cpp src/calendar/BookingCalendar.h
        src/format/CSVLoader.cpp src/format/CSVLoader.h
        src/validators/DateValidator.cpp src/validators/DateValidator.h
        src/validators/DateValidatorException.cpp src/validators/DateValidatorException.h
        src/calendar/DayReservation.cpp src/calendar/DayReservation.h
        src/calendar/DayReservationException.cpp src/calendar/DayReservationException.h
        src/hotel/Hotel.cpp src/hotel/Hotel.h
        src/validators/HotelValidatorException.cpp src/validators/HotelValidatorException.h
        src/calendar/Month.cpp src/calendar/Month.h
        src/validators/RoomValidator.cpp src/validators/RoomValidator.h
        src/validators/RoomValidatorException.cpp src/validators/RoomValidatorException.h
        src/calendar/Year.cpp src/calendar/Year.h
        src/format/HtmlExport.cpp src/format/HtmlExport.h
        )
add_executable(semestralka ${SOURCE_FILES})
add_subdirectory(tests)
