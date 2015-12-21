#include "../../Month.h"
#include "../../Month.cpp"
#include "gtest/gtest.h"

TEST(TestMonth, testEmptyDays) {
    Month month(1, 0);
    EXPECT_EQ(0, month.getDays());
    EXPECT_EQ(1, month.getMonthNumber());
}

TEST(TestMonth, testGenerateDays) {
    Month month(2, 3);
    EXPECT_EQ(2, month.getMonthNumber());
    EXPECT_EQ(3, month.getDays());
    for (int i = 1; i < 4; i++) {
        EXPECT_EQ(i, month.getReservationDay(i)->getNumberDay());
    }
}



