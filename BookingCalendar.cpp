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

const std::vector<Year> & BookingCalendar::getYears() const {
    return this->years;
}

void BookingCalendar::generateNextYearIsPossible(const int year) {
    bool isOneYearInCalendar = this->years.size() == 1;
    bool isNextYearEqualNextYear = this->years.at(0).getYearNumber() + 1 == year;
    if (isOneYearInCalendar && isNextYearEqualNextYear) {
        this->generateNextYear(year);
    } else {
        //std::count << "Year is over"; // throw exception
        return;
    }
}

void BookingCalendar::reserveRoom(Room &room, const int year, const int month, const int day) {
    // validate year atd ... month > 0 && month < 13
    this->generateNextYearIsPossible(year);
    for(int i = 0; i < this->years.size(); i++) {
        if (this->years.at(i).getYearNumber() != year) continue;
        this->years.at(i).getMonths().at(month - 1).bookingRoomToDay(day, room);
    }
}


const std::vector<Room*> * BookingCalendar::getRoomReservationByDate(const int year, const int month, const int day) {
    for(int i = 0; i < this->years.size(); i++){
        if (this->years.at(i).getYearNumber() != year) continue;
        return this->years.at(i).getMonths().at(month - 1).getRoomsFromDays(day);
    }

    return NULL; // exception
}

/*
Year * BookingCalendar::getYear(const int year) {
    int startPositionCalendar = this->year;
}
 */

std::vector<Room> BookingCalendar::findFreeRoomInDay(Hotel & hotel, const int year, const int month, const int day) {
    // control if it date valid
    std::vector<Room> resultVec;
    std::vector<Room> *rooms = &(hotel.getRooms());
    Year * actualYear = &(this->years.at(0));
    Month * actualMonth = actualYear->getMonth(month);

    DayReservation * actualDay = actualMonth->getReservationDay(day);
    for (int i = 0; i < rooms->size(); i++) {
            if(actualDay->isRoomAlreadyRegistered(rooms->at(i)) == false) {
                resultVec.push_back(hotel.getRooms().at(i));
            }
    }
    rooms = NULL;
    actualMonth = NULL;
    actualDay = NULL;
    return resultVec;
}

std::vector<Room> BookingCalendar::findFreeRoomInDayByPrize(Hotel & hotel, const int prize, const int year, const int month, const int day) {
    std::vector<Room> resultVec;
    std::vector<Room> *rooms = &(hotel.getRooms());
    Year * actualYear = &(this->years.at(0));
    Month * actualMonth = actualYear->getMonth(month);

    DayReservation * actualDay = actualMonth->getReservationDay(day);
    for (int i = 0; i < rooms->size(); i++) {
        if (hotel.getRooms().at(i).getPrize() > prize) continue;
        if(actualDay->isRoomAlreadyRegistered(rooms->at(i)) == false) {
            resultVec.push_back(hotel.getRooms().at(i));
        }
    }
    rooms = NULL;
    actualMonth = NULL;
    actualDay = NULL;
    return resultVec;


}