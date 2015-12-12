#include "../../HotelValidator.h"
#include "../../HotelValidator.cpp"
#include "../../HotelValidatorException.cpp"
#include "gtest/gtest.h"

class TestHotelValidator: public::testing::Test {
    protected:
        std::vector<Room> database;
        void SetUp() {
            for (int i = 1; i < 4; i++) {
                Room room(i, 2, 4, 9, 10);
                database.push_back(room);
            }
        }

        void TearDown() {
            database.clear();
        }
};

TEST_F(TestHotelValidator, testBasicUsage) {
    EXPECT_TRUE(HotelValidator::isIdRoomDuplicate(this->database, 1));
    EXPECT_TRUE(HotelValidator::isIdRoomDuplicate(this->database, 3));
    EXPECT_FALSE(HotelValidator::isIdRoomDuplicate(this->database, 45));
}


TEST_F(TestHotelValidator, testHotelValidatorException) {
    try {
        HotelValidator::roomValidate(this->database, 1);
    } catch (const DuplicateIdRoomException & err) {
        ASSERT_STREQ("Room with id#1 is duplicate.", err.what());
    }
}


