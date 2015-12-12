#include "../../Month.h"
#include "../../Month.cpp"
#include "gtest/gtest.h"

TEST(TestMonth, testEmptyDays) {
    Month month(1, 0);
    const std::vector<DayReservation> days = month.getDays();
    EXPECT_EQ(0, days.size());
    EXPECT_EQ(1, month.getMonthNumber());
}

TEST(TestMonth, testGenerateDays) {
    Month month(2, 3);
    EXPECT_EQ(2, month.getMonthNumber());
    const std::vector<DayReservation> days = month.getDays();
    EXPECT_EQ(3, days.size());
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(i+1, days[i].getNumberDay());
    }
}

TEST(TestMonth, testAssignedDay) {
    Room room(1, 2, 3, 4, 5);
    Month month(3, 3);
    // osetrit 0
    month.bookingRoomToDay(3, room);
    std::vector<DayReservation> days = month.getDays();

    for (int i = 0; i < 2; i++) {
        EXPECT_TRUE(days.at(i).isReservationEmpty());
    }

    EXPECT_EQ(3, days.size());
    EXPECT_EQ(3, days[2].getNumberDay());
    const std::vector<Room*> * rooms = days.at(2).getReserveRooms();
    EXPECT_EQ(1, rooms->size());

    Room *room1 = rooms->at(0);
    EXPECT_EQ(room.getId(), room1->getId());
    EXPECT_EQ(room.getCapacity(), room1->getCapacity());
    EXPECT_EQ(room.getPrize(), room1->getPrize());
    EXPECT_EQ(room.getRoomLocation().getFloor(), room1->getRoomLocation().getFloor());
    EXPECT_EQ(room.getRoomLocation().getDoor(), room1->getRoomLocation().getDoor());
    room1 = NULL;
}


