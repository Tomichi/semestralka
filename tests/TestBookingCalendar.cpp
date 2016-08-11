#include "../src/calendar/BookingCalendar.h"
#include "../src/calendar/BookingCalendar.cpp"
#include "../src/calendar/DayReservationException.h"
#include "../src/validators/DateValidator.h"
#include "../src/validators/DateValidator.cpp"
#include "../src/validators/DateValidatorException.h"
#include "../src/validators/DateValidatorException.cpp"
#include "../src/calendar/Year.h"
#include "../src/hotel/Hotel.h"
#include "../src/hotel/Room.h"
#include <vector>
#include <string>
#include "gtest/gtest.h"


void compareRoom(Room & room1, Room & room2) {
    EXPECT_EQ(room1.getId(), room2.getId());
    EXPECT_EQ(room1.getCapacity(), room2.getCapacity());
    EXPECT_EQ(room1.getPrize(), room2.getPrize());
    EXPECT_EQ(room1.getRoomLocation().getDoor(), room2.getRoomLocation().getDoor());
    EXPECT_EQ(room1.getRoomLocation().getFloor(), room2.getRoomLocation().getFloor());
}


TEST(TestBookingCalendar, testDuplicateReservation) {
    BookingCalendar calendar(2015);
    Room R1(1, 20, 300, 400, 405), R2(2, 15, 200, 300, 302);
    calendar.reserveRoom(R1, 2015, 12, 13);
    calendar.reserveRoom(R2, 2015, 12, 13);
    try {
        calendar.reserveRoom(R2, 2015, 12, 13);
    } catch (const RoomIsAlreadyRegisteredOnThisDayException & err) {
        ASSERT_STREQ("Room with id#2 is already registered in day#13", err.what());
    }

}


TEST(TestBookingCalendar, testAvailableRoomInDay) {
    Hotel hotels;
    int count = 4;
    for (int i = 0; i < count; i++){
        Room R1(i + 1, i + 20, i+300, i+400, i+405);
        hotels.pushRoomToDatabase(R1);
    }

    std::vector<Room> * rooms = hotels.getRooms();
    EXPECT_EQ(count, rooms->size());

    BookingCalendar calendar(2015);
    calendar.reserveRoom(rooms->at(2), 2015, 12, 14);
    calendar.reserveRoom(rooms->at(3), 2015, 12, 14);

    std::vector<Room> result;
    calendar.findFreeRoomInDay(hotels, 2015, 12, 14, result);
    EXPECT_EQ(2, result.size());

    for (int i = 0; i < 2; i++) {
        compareRoom(rooms->at(i), result.at(i));
    }
    result.clear();
    EXPECT_EQ(count, rooms->size());
    rooms = NULL;
}


TEST(TestBookingCalendar, testAvaliableRoomInDayBoundByPrize) {
    Hotel hotels;
    int count = 4;
    for (int i = 0; i < count; i++){
        Room R1(i + 1, i + 20, (i+1) * 30, i+400, i+405);
        hotels.pushRoomToDatabase(R1);
    }

    std::vector<Room> * rooms = hotels.getRooms();
    EXPECT_EQ(count, rooms->size());

    BookingCalendar calendar(2015);
    calendar.reserveRoom(rooms->at(2), 2015, 12, 14);
    calendar.reserveRoom(rooms->at(3), 2015, 12, 14);

    std::vector<Room> result;
    calendar.findFreeRoomInDayByPrize(hotels, 70, 2015, 12, 14, result);
    EXPECT_EQ(2, result.size());

    for (int i = 0; i < 2; i++) {
        compareRoom(rooms->at(i), result.at(i));
    }
    result.clear();
    EXPECT_EQ(count, rooms->size());
    rooms = NULL;
}

TEST(TestBookingCalendar, testFindRoomInTwoDate) {
    std::vector<std::string> date;
    BookingCalendar calendar(2015);
    Hotel hotel;
    for (int i = 0; i < 4; i++) {
        Room room(1+i, 5*(i+1), 200, 4, 405);
        hotel.pushRoomToDatabase(room);
    }

    calendar.reserveRoom(hotel.getRoomByIndex(0), 2015, 12, 12);
    calendar.reserveRoom(hotel.getRoomByIndex(1), 2015, 12, 12);
    calendar.reserveRoom(hotel.getRoomByIndex(2), 2015, 12, 12);
    calendar.reserveRoom(hotel.getRoomByIndex(1), 2015, 12, 14);
    calendar.reserveRoom(hotel.getRoomByIndex(1), 2015, 12, 16);
    calendar.reserveRoom(hotel.getRoomByIndex(0), 2015, 12, 15);

    calendar.findRoomByDateRange(hotel.getRoomByIndex(1), 2015, 12, 10, 2015, 12, 20, date);
    EXPECT_EQ(3, date.size());
}