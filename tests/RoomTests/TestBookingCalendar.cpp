#include "../../BookingCalendar.h"
#include "../../BookingCalendar.cpp"
#include "../../DayReservationException.h"
#include "../../Year.h"
#include "../../Hotel.h"
#include "../../Room.h"
#include <vector>
#include "gtest/gtest.h"

TEST(TestBookingCalendar, testBasicUsage) {
    BookingCalendar calendar(2015);
    calendar.generateNextYear(2016);
    Year * actualYear = calendar.getYear(2015);
    for (int i = 0; i < 12; i++) {
        EXPECT_EQ(daysInMonths[i], actualYear->getMonth(i + 1)->getDays());
    }

    actualYear = calendar.getYear(2016);
    for (int i = 0; i < 12; i++) {
        if (i == 1) {
            EXPECT_EQ(daysInMonths[i] + 1, actualYear->getMonth(i + 1)->getDays());
        } else {
            EXPECT_EQ(daysInMonths[i], actualYear->getMonth(i + 1)->getDays());
        }
    }
    actualYear = NULL;
}


TEST(TestBookingCalendar, testReserveRoom) {
    BookingCalendar calendar(2015);
    Room R1(1, 20, 300, 400, 405), R2(2, 15, 200, 300, 302);
    calendar.reserveRoom(R1, 2015, 12, 12);
    calendar.reserveRoom(R2, 2016, 1, 2);
    const std::vector<Room *> *rooms1 = calendar.getRoomReservationByDate(2015, 12, 12);
    const std::vector<Room *> *rooms2 = calendar.getRoomReservationByDate(2016, 1, 2);
    const std::vector<Room *> *rooms3 = calendar.getRoomReservationByDate(2016, 2, 2);
    EXPECT_EQ(1, rooms1->size());
    EXPECT_EQ(1, rooms2->size());
    EXPECT_EQ(0, rooms3->size());

    EXPECT_EQ(R1.getId(), rooms1->at(0)->getId());
    EXPECT_EQ(R1.getCapacity(), rooms1->at(0)->getCapacity());
    EXPECT_EQ(R1.getPrize(), rooms1->at(0)->getPrize());
    EXPECT_EQ(R1.getRoomLocation().getDoor(), rooms1->at(0)->getRoomLocation().getDoor());
    EXPECT_EQ(R1.getRoomLocation().getFloor(), rooms1->at(0)->getRoomLocation().getFloor());

    EXPECT_EQ(R2.getId(), rooms2->at(0)->getId());
    EXPECT_EQ(R2.getCapacity(), rooms2->at(0)->getCapacity());
    EXPECT_EQ(R2.getPrize(), rooms2->at(0)->getPrize());
    EXPECT_EQ(R2.getRoomLocation().getDoor(), rooms2->at(0)->getRoomLocation().getDoor());
    EXPECT_EQ(R2.getRoomLocation().getFloor(), rooms2->at(0)->getRoomLocation().getFloor());
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

    const std::vector<Room *> *rooms1 = calendar.getRoomReservationByDate(2015, 12, 13);


    EXPECT_EQ(2, rooms1->size());
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

    std::vector<Room> result = calendar.findFreeRoomInDay(hotels, 2015, 12, 14);
    EXPECT_EQ(2, result.size());

    for (int i = 0; i < 2; i++) {

        EXPECT_EQ(rooms->at(i).getId(), result.at(i).getId());
        EXPECT_EQ(rooms->at(i).getCapacity(), result.at(i).getCapacity());
        EXPECT_EQ(rooms->at(i).getPrize(), result.at(i).getPrize());
        EXPECT_EQ(rooms->at(i).getRoomLocation().getFloor(), result.at(i).getRoomLocation().getFloor());
        EXPECT_EQ(rooms->at(i).getRoomLocation().getDoor(), result.at(i).getRoomLocation().getDoor());
    }

    EXPECT_EQ(count, rooms->size());
    rooms = NULL;
}