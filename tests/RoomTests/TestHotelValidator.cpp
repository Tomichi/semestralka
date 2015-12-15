#include "../../HotelValidatorException.cpp"
#include "../../Hotel.h"
#include "gtest/gtest.h"

class TestHotelValidator: public::testing::Test {
    protected:
        Hotel hotel;
        void SetUp() {
            for (int i = 1; i < 4; i++) {
                Room room(i, 2, 4, 9, 10);
                hotel.pushRoomToDatabase(room);
            }
        }
};

TEST_F(TestHotelValidator, testBasicUsage) {
    EXPECT_TRUE(hotel.isIdRoomDuplicate(1));
    EXPECT_TRUE(hotel.isIdRoomDuplicate(3));
    EXPECT_FALSE(hotel.isIdRoomDuplicate(45));
}


TEST_F(TestHotelValidator, testHotelValidatorException) {
    try {
        hotel.isIdRoomDuplicate(1);
    } catch (const DuplicateIdRoomException & err) {
        ASSERT_STREQ("Room with id#1 is duplicate.", err.what());
    }
}


