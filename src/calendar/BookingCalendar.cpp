
#include "BookingCalendar.h"


BookingCalendar::BookingCalendar(const int year) {
    this->addYear(year);
}

BookingCalendar::~BookingCalendar() {
    this->years.clear();
}

void BookingCalendar::addYear(const int year) {
    Year newYear(year);

    this->years.push_back(newYear);
}

void BookingCalendar::generateNextYearIsPossible(const int year) {
    bool isOneYearInCalendar = this->years.size() == 1;
    bool isNextYearEqualNextYear = this->years.at(0).getYearNumber() + 1 == year;

    if (isOneYearInCalendar && isNextYearEqualNextYear) {
        this->addYear(year);
    }
}

void BookingCalendar::reserveRoom(Room &room, const int year, const int month, const int day) {
    DateValidator::validateDate(year, month, day);
    this->generateNextYearIsPossible(year);

    DayReservation * dayReservation = this->getDayByDate(year, month, day);

    dayReservation->reserveDay(room);
    dayReservation = NULL;
}

Year * BookingCalendar::getYear(const int year) {
    const int startYearInPositionCalendar = this->years.at(0).getYearNumber();

    const int countYearsInCalendar = (int) this->years.size();

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
            if(!actualDay->isRoomAlreadyRegistered(rooms->at(i))) {
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
        if(!actualDay->isRoomAlreadyRegistered(rooms->at(i))) {
            result.push_back(rooms->at(i));
        }
    }

    actualDay = NULL;
    rooms = NULL;
}


void BookingCalendar::findFreeRoomInDayByCapacity(Hotel & hotel, const int capacity, const int year, const int month, const int day, std::vector<Room> &result) {
    DateValidator::validateDate(year, month, day);

    std::vector<Room> *rooms = hotel.getRooms();

    DayReservation * actualDay = this->getDayByDate(year, month, day);

    for (int i = 0; i < rooms->size(); i++) {
        if (rooms->at(i).getCapacity() > capacity) continue;
        if(!actualDay->isRoomAlreadyRegistered(rooms->at(i))) {
            result.push_back(rooms->at(i));
        }
    }

    actualDay = NULL;
    rooms = NULL;
}

void BookingCalendar::findRoomByDateRange(Room & room, const int year1, const int month1, const int day1, const int year2, const int month2, const int day2, std::vector<std::string> &date) {
    DateValidator::isDateValidate(year1, month1, day1);
    DateValidator::isDateValidate(year2, month2, day2);

    for (int y = year1; y <= year2; y++) {

        for (int m = (y == year1) ? month1 : 1; m <= ((y == year2) ? month2: 12); m++) {

            for (int d = (y == year1 && m == month1) ? day1 : 1;
                    d <= ((y == year2 && m == month2) ? day2 : ((Year::isLeapYear(y) && m == 1) ? daysInMonths[m - 1] + 1 : daysInMonths[m - 1])); d++) {

                DayReservation * reservation = this->getDayByDate(y, m, d);
                if (reservation->isReservationEmpty()) continue;
                if (reservation->isRoomAlreadyRegistered(room)) {
                    date.push_back(std::to_string(d) + "." + std::to_string(m) + "." + std::to_string(y));
                }
            }
        }
    }
}
