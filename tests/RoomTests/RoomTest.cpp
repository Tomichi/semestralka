#include "gtest/gtest.h"
#include "../../Room.h"
#include "../../Room.cpp"
#include "../../RoomException.h"
#include "../../RoomException.cpp"
#include "../../RoomValidator.h"
#include "../../RoomValidator.cpp"


TEST(TestRoom, testConstructor) {
    const int id = 5, capacity = 40, prize = 200, floor = 3, door = 305;
    Room newRoom(id, capacity, prize, floor, door);
    RoomLocation location = newRoom.getRoomLocation();

    EXPECT_EQ(id, newRoom.getId());
    EXPECT_EQ(capacity, newRoom.getCapacity());
    EXPECT_EQ(prize, newRoom.getPrize());
    EXPECT_EQ(floor, location.getFloor());
    EXPECT_EQ(door, location.getDoor());
}

TEST(TestRoom, testInvalidId) {
    const int capacity = 40, prize = 200, floor = 3, door = 305;
    int id = 0; // zero id

    try {
        Room testRoom(id, capacity, prize, floor, door);
    } catch (const InvalidRoomIdException & err) {
        ASSERT_STREQ("id#0 is not valid.", err.what());
    }

    id = -3; //negative id
    try {
        Room testRoom2(id, capacity, prize, floor, door);
    } catch (const InvalidRoomIdException & err) {
        ASSERT_STREQ("id#-3 is not valid.", err.what());
    }
}

TEST(TestRoom, testInvalidCapacity) {
    const int prize = 200, floor = 3, door = 305;
    int id = 2, capacity = 0; // zero capacity

    try {
        Room testRomm(id, capacity, prize, floor, door);
    } catch (const InvalidCapacityException & err) {
        ASSERT_STREQ("Capacity 0 of id#2 is not valid.", err.what());
    }

    id = 4;
    capacity = -50;
    try {
        Room testRoom2(id, capacity, prize, floor, door);
    } catch (const InvalidCapacityException & err) {
        ASSERT_STREQ("Capacity -50 of id#4 is not valid.", err.what());
    }
}


TEST(TestRoom, testInvalidPrice) {
    const int capacity = 330, floor = 3, door = 305;
    int id = 7, prize = 0;
    try {
        Room testRoom(id, capacity, prize, floor, door);
    } catch (const InvalidPrizeException & err) {
        ASSERT_STREQ("Prize 0 of id#7 is not valid.", err.what());
    }

    id = 9;
    prize = -500;
    try {
        Room testRoom(id, capacity, prize, floor, door);
    } catch (const InvalidPrizeException & err) {
        ASSERT_STREQ("Prize -500 of id#9 is not valid.", err.what());
    }
}
