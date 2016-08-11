#include "../src/hotel/Hotel.h"
#include "../src/calendar/BookingCalendar.h"
#include "../src/hotel/Room.h"
#include "../src/format/CSVLoader.h"
#include "../src/format/CSVLoader.cpp"
#include "gtest/gtest.h"

/*void TestRoom(Room &room, int id, int capacity, int prize, int floor, int door) {

    EXPECT_EQ(id, room.getId());
    EXPECT_EQ(capacity, room.getCapacity());
    EXPECT_EQ(prize, room.getPrize());
    EXPECT_EQ(floor, room.getRoomLocation().getFloor());
    EXPECT_EQ(door, room.getRoomLocation().getDoor());
}

TEST(TestCSVLoader, testparseCsvHotel) {
    Hotel hotel;
    BookingCalendar calendar(2015);
    CSVLoader roomLoader("/Users/tomichi/ClionProjects/semestralka/tests/RoomTests/hotel1.csv");
    roomLoader.parseRoomToHotel(hotel);
    EXPECT_EQ(5, hotel.getRooms()->size());
    TestRoom(hotel.getRoomByIndex(0), 1, 20, 400, 1, 100);
    TestRoom(hotel.getRoomByIndex(1), 2, 10, 300, 1, 101);
    TestRoom(hotel.getRoomByIndex(2), 3, 15, 350, 1, 102);
    TestRoom(hotel.getRoomByIndex(3), 4, 5, 150, 2, 202);
    TestRoom(hotel.getRoomByIndex(4), 5, 5, 250, 2, 205);

    CSVLoader reservationLoader("/Users/tomichi/ClionProjects/semestralka/tests/RoomTests/reservation1.csv");
    reservationLoader.parseReservation(hotel, calendar);
    std::vector<Room> freeRoom;
    calendar.findFreeRoomInDay(hotel, 2015, 12, 20, freeRoom);
    EXPECT_EQ(2, freeRoom.size());
    TestRoom(freeRoom.at(0), 4, 5, 150, 2, 202);
    TestRoom(freeRoom.at(1), 5, 5, 250, 2, 205);
    freeRoom.clear();

    calendar.findFreeRoomInDay(hotel, 2015, 12, 21, freeRoom);
    EXPECT_EQ(4, freeRoom.size());
    TestRoom(freeRoom.at(0), 1, 20, 400, 1, 100);
    TestRoom(freeRoom.at(1), 2, 10, 300, 1, 101);
    TestRoom(freeRoom.at(2), 3, 15, 350, 1, 102);
    TestRoom(freeRoom.at(3), 5, 5, 250, 2, 205);
    freeRoom.clear();


    calendar.findFreeRoomInDay(hotel, 2015, 12, 22, freeRoom);
    EXPECT_EQ(3, freeRoom.size());
    TestRoom(freeRoom.at(0), 1, 20, 400, 1, 100);
    TestRoom(freeRoom.at(1), 2, 10, 300, 1, 101);
    TestRoom(freeRoom.at(2), 5, 5, 250, 2, 205);
    freeRoom.clear();


}*/
