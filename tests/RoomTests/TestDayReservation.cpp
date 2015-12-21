#include "../../DayReservation.h"
#include "../../DayReservation.cpp"
#include "../../DayReservation.h"
#include "../../DayReservationException.cpp"
#include "gtest/gtest.h"

class TestDayReservation : public ::testing::Test {
protected:
    std::vector<Room> rooms;
    const int roomCount = 5;

    void SetUp() {
        this->generateRooms();
    }

    void TearDown() {
        this->rooms.clear();
    }

    void generateRooms() {
        for (int i = 0; i < this->roomCount; i++) {
            Room room(i + 1, 2, 3, 4, 55);
            this->rooms.push_back(room);
        }
    }
};
