#include "BookingCalendar.h"


BookingCalendar::BookingCalendar(const int year) {
    this->addYear(year);
}

BookingCalendar::~BookingCalendar() {
    this->years.clear();
}

void BookingCalendar::generateNextYear(const int year) {
    this->addYear(year);
}

void BookingCalendar::addYear(const int year) {
    Year newYear(year);
    this->years.push_back(newYear);
}

void BookingCalendar::generateNextYearIsPossible(const int year) {
    bool isOneYearInCalendar = this->years.size() == 1;
    bool isNextYearEqualNextYear = this->years.at(0).getYearNumber() + 1 == year;
    if (isOneYearInCalendar && isNextYearEqualNextYear) {
        this->generateNextYear(year);
    }
}

void BookingCalendar::reserveRoom(Room &room, const int year, const int month, const int day) {
    DateValidator::validateDate(year, month, day);
    this->generateNextYearIsPossible(year);
    DayReservation * dayReservation = this->getDayByDate(year, month, day);
    dayReservation->reserveDay(room);
    dayReservation = NULL;
}


const std::vector<Room*> * BookingCalendar::getRoomReservationByDate(const int year, const int month, const int day) {
    DateValidator::validateDate(year, month, day);
    DayReservation * dayReservation = this->getDayByDate(year, month, day);

    return dayReservation->getReserveRooms();

}


Year * BookingCalendar::getYear(const int year) {
    const int startYearInPositionCalendar = this->years.at(0).getYearNumber();
    const int countYearsInCalendar = this->years.size();
    if (year < startYearInPositionCalendar) {
        throw "year is not in calendar";
    }

    int yearDiff = startYearInPositionCalendar - year;
    if (yearDiff > countYearsInCalendar) {
        throw "year is not in calendar";
    }

    Year * result = NULL;
    for(int i = 0; i < countYearsInCalendar; i++) {
        if (year != this->years.at(i).getYearNumber()) continue;
        result =  &(this->years.at(i));
    }

    return result;

}

DayReservation * BookingCalendar::getDayByDate(const int year, const int month, const int day) {
    DateValidator::validateDate(year, month, day);
    Year * actualYear = this->getYear(year);
    Month * actualMonth = actualYear->getMonth(month);
    DayReservation * actualDay = actualMonth->getReservationDay(day);

    actualYear = NULL;
    actualMonth = NULL;

    return actualDay;
}

void BookingCalendar::findFreeRoomInDay(Hotel & hotel, const int year, const int month, const int day,
                                                       std::vector<Room> &result) {
    DateValidator::validateDate(year, month, day);
    std::vector<Room> *rooms = hotel.getRooms();
    DayReservation * actualDay = this->getDayByDate(year, month, day);
    for (int i = 0; i < rooms->size(); i++) {
            if(actualDay->isRoomAlreadyRegistered(rooms->at(i)) == false) {
                result.push_back(rooms->at(i));
            }
    }

    actualDay = NULL;
    rooms = NULL;
}

void BookingCalendar::findFreeRoomInDayByPrize(Hotel & hotel, const int prize, const int year, const int month, const int day, std::vector<Room> &result) {
    DateValidator::validateDate(year, month, day);
    std::vector<Room> *rooms = hotel.getRooms();
    DayReservation * actualDay = this->getDayByDate(year, month, day);
    for (int i = 0; i < rooms->size(); i++) {
        if (rooms->at(i).getPrize() > prize) continue;
        if(actualDay->isRoomAlreadyRegistered(rooms->at(i)) == false) {
            result.push_back(rooms->at(i));
        }
    }
    actualDay = NULL;
    rooms = NULL;
}
