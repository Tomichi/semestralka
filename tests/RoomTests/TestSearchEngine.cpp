#include "../../Room.h"
#include "../../Room.cpp"
#include "../../Hotel.h"
#include "gtest/gtest.h"

class TestSearchEngine : public ::testing::Test {
protected:
    void SetUp() {
        for (int i = 1; i < 5; i++) {
            Room room(i, 2, 3, 4, 5);
            this->hotel.pushRoomToDatabase(room);
        }
    }

    void TearDown() {
    }

    Hotel hotel;
};


TEST_F(TestSearchEngine, tetsFindExistId) {
    SearchResult result = this->hotel.findRoomInHotels(1);
    EXPECT_TRUE(result.getFound());
    EXPECT_EQ(0, result.getIndex());

    result = hotel.findRoomInHotels(4);
    EXPECT_TRUE(result.getFound());
    EXPECT_EQ(3, result.getIndex());
}

TEST_F(TestSearchEngine, tetsNotFindId) {
    SearchResult result = hotel.findRoomInHotels(5);
    EXPECT_FALSE(result.getFound());
    EXPECT_EQ(-1, result.getIndex());
}



