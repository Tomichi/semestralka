#include "gtest/gtest.h"
#include "../../RoomValidator.h"

TEST(TestValidator, valdiateId) {
    EXPECT_TRUE(RoomValidator::isIdValid(1));
    EXPECT_TRUE(RoomValidator::isIdValid(34));
    EXPECT_FALSE(RoomValidator::isIdValid(-24));
    EXPECT_FALSE(RoomValidator::isIdValid(0));
}

TEST(TestValidator, valdiatePrize) {
    EXPECT_TRUE(RoomValidator::isPrizeValid(1));
    EXPECT_TRUE(RoomValidator::isPrizeValid(304));
    EXPECT_FALSE(RoomValidator::isPrizeValid(-240));
    EXPECT_FALSE(RoomValidator::isPrizeValid(0));
}

TEST(TestValidator, valdiateCapacit) {
    EXPECT_TRUE(RoomValidator::isCapacityValid(1));
    EXPECT_TRUE(RoomValidator::isCapacityValid(30004));
    EXPECT_FALSE(RoomValidator::isCapacityValid(-24000));
    EXPECT_FALSE(RoomValidator::isCapacityValid(0));
}