#include "../../src/hotel/Room.h"
#include "../../src/validators/RoomValidatorException.cpp"
#include "../../src/validators/RoomValidator.cpp"
#include "gtest/gtest.h"

class TestRoom : public::testing::Test {
public:
    void setDeleteRoom(bool value) {
        this->deleteRoom = value;
    }

protected:
    bool deleteRoom;
    void SetUp() {
        this->deleteRoom = true;
    }

    void TearDown() {
        if (this->deleteRoom) {
            delete this->room;
        }
    }

    Room *room;
};

TEST_F(TestRoom, testBaseValidInput) {
    room = new Room(5, 40, 200, 3, 305);
    RoomLocation location = room->getRoomLocation();

    EXPECT_EQ(5, room->getId());
    EXPECT_EQ(40, room->getCapacity());
    EXPECT_EQ(200, room->getPrize());
    EXPECT_EQ(3, location.getFloor());
    EXPECT_EQ(305, location.getDoor());
}


TEST_F(TestRoom, testZeroId) {
        this->setDeleteRoom(false);
    try {
        this->room = new Room(0, 40, 200, 3, 305);
    } catch (const InvalidRoomIdException & err) {
        ASSERT_STREQ("id#0 is not valid.", err.what());
    }
}

TEST_F(TestRoom, testNegativeId) {
    this->setDeleteRoom(false);
    try {
        room = new Room(-5, 40, 200, 3, 305);
    } catch (const InvalidRoomIdException & err) {
        ASSERT_STREQ("id#-5 is not valid.", err.what());
    }
}

TEST_F(TestRoom, testZeroCapacity) {
    this->setDeleteRoom(false);
    try {
        room = new Room(2, 0, 250, 4, 400);
    } catch (const InvalidCapacityException & err) {
        ASSERT_STREQ("Capacity 0 of id#2 is not valid.", err.what());
    }
}

TEST_F(TestRoom, testNegativeCapacity) {
    this->setDeleteRoom(false);
    try {
        room = new Room(6, -40, 250, 4, 400);
    } catch (const InvalidCapacityException & err) {
        ASSERT_STREQ("Capacity -40 of id#6 is not valid.", err.what());
    }
}

TEST_F(TestRoom, testZeroPrice) {
    this->setDeleteRoom(false);
    try {
        room = new Room(3, 3, 0, 2, 2);
    } catch (const InvalidPrizeException & err) {
        ASSERT_STREQ("Prize 0 of id#3 is not valid.", err.what());
    }
}
TEST_F(TestRoom, testNegativePrice) {
    this->setDeleteRoom(false);
    try {
        room = new Room(8, 43, -700, 2, 2);
    } catch (const InvalidPrizeException & err) {
        ASSERT_STREQ("Prize -700 of id#8 is not valid.", err.what());
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
