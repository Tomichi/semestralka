#include "../../DayReservation.h"
#include "../../DayReservation.cpp"
#include "gtest/gtest.h"


class TestDayReservation : public ::testing::Test {
protected:
    std::vector<Room *> rooms;
    const int roomCount = 5;

    void SetUp() {
        this->generateRooms();
    }

    void TearDown() {
        this->rooms.clear();
    }

    void generateRooms() {
        for (int i = 0; i < this->roomCount; i++) {
            this->rooms.push_back(new Room(i + 1, 2, 3, 4, 55));
        }
    }
};


TEST_F(TestDayReservation, testDestructor) {
    DayReservation *dayReservation = new DayReservation(1);
    for (int i = 0; i < this->roomCount; i++) {
        dayReservation->reserveDay(this->rooms[i]);
    }

    const std::vector<Room *> *result = dayReservation->getReserveRooms();
    EXPECT_EQ(this->roomCount, result->size());
    delete dayReservation;
    result = NULL;
}