#include "../../Hotel.h"
#include "../../Hotel.cpp"
#include "../../Room.h"
#include "gtest/gtest.h"

class TestHotel : public ::testing::Test {
    protected:
        Hotel *hotel;
        const int roomCount = 5;

        void SetUp() {
            this->hotel = new Hotel();
            this->generateValidInputRooms();

        }

        void TearDown() {
            hotel->~Hotel();
        }

        void generateValidInputRooms() {
            for (int i = 0; i < this->roomCount; i++) {
                this->hotel->pushRoomToDatabase(new Room(this->roomCount - i, 2, 3, 5, 5));
            }
        }
};


TEST_F(TestHotel, testBasicGetRooms) {
    const std::vector<Room *> tmpRoomDatabase = this->hotel->getRooms();
    EXPECT_EQ(this->roomCount, tmpRoomDatabase.size());
}

TEST_F(TestHotel, testBasicSort) {
    this->hotel->sortRoomsById();
    std::vector<Room *> tmpRoomDatabase = this->hotel->getRooms();

    int i = 1;
    for(std::vector<Room*>::iterator it = tmpRoomDatabase.begin(); it != tmpRoomDatabase.end(); it++, i++) {
        EXPECT_EQ(i, (*it)->getId());
    }
}




