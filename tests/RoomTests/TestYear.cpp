#include "../../Year.h"
#include "../../Year.cpp"
#include "gtest/gtest.h"

TEST(TestYear, testLeapYear) {
    Year leapYear(2012);
    std::vector<Month> months = leapYear.getMonths();
    EXPECT_EQ(12, months.size());
    for (int i = 0; i < 12; i++) {
        if (i == 1) {
            EXPECT_EQ(daysInMonths[i] + 1, months[i].getDays().size());
        } else {
            EXPECT_EQ(daysInMonths[i], months[i].getDays().size());
        }
    }
}

TEST(TestYear, testNoLeapYear) {
    Year leapYear(2015);
    std::vector<Month> months = leapYear.getMonths();
    EXPECT_EQ(12, months.size());
    for (int i = 0; i < 12; i++) {
        EXPECT_EQ(daysInMonths[i], months[i].getDays().size());
    }
}

