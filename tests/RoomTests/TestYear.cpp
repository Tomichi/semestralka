#include "../../src/calendar/Year.h"
#include "../../src/calendar/Year.cpp"
#include "gtest/gtest.h"

TEST(TestYear, testLeapYear) {
    Year leapYear(2012);
    Month * actualMonth;
    for (int i = 0; i < 12; i++) {
        actualMonth = leapYear.getMonth(i + 1);
        if (i == 1) {
            EXPECT_EQ(daysInMonths[i] + 1, actualMonth->getDays());
        } else {
            EXPECT_EQ(daysInMonths[i], actualMonth->getDays());
        }
    }

    actualMonth = NULL;
}

TEST(TestYear, testNoLeapYear) {
    Year leapYear(2015);
    std::vector<Month> months = leapYear.getMonths();
    Month * actualMonth;
    EXPECT_EQ(12, months.size());
    for (int i = 0; i < 12; i++) {
        actualMonth = leapYear.getMonth(i + 1);
        EXPECT_EQ(daysInMonths[i], actualMonth->getDays());
    }
}

