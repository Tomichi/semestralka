#include "../src/hotel/Hotel.h"
#include "../src/format/CSVLoader.h"
#include "gtest/gtest.h"


/*TEST(TestCsvLoadError, testDuplicityId) {
    Hotel hotel;
    CSVLoader loader("/Users/tomichi/ClionProjects/semestralka/tests/RoomTests/hotel2wrong.csv");
    try {
        loader.parseRoomToHotel(hotel);
    } catch (const std::string & ex) {
        ASSERT_STREQ("Room with id#2 is duplicate. in file /Users/tomichi/ClionProjects/semestralka/tests/RoomTests/hotel2wrong.csv on line 5", ex.c_str());
    }
}

TEST(TestCsvLoadError, testZeroId) {
    Hotel hotel;
    CSVLoader loader("/Users/tomichi/ClionProjects/semestralka/tests/RoomTests/hotel3wrong.csv");
    try {
        loader.parseRoomToHotel(hotel);
    } catch (const std::string & ex) {
        ASSERT_STREQ("id#-2 is not valid. in file /Users/tomichi/ClionProjects/semestralka/tests/RoomTests/hotel3wrong.csv on line 2", ex.c_str());

    }
}


TEST(TestCsvLoadError, testTextInNumber) {
    Hotel hotel;
    CSVLoader loader("/Users/tomichi/ClionProjects/semestralka/tests/RoomTests/hotel4wrong.csv");
    try {
        loader.parseRoomToHotel(hotel);
    } catch (const std::string & ex) {
        ASSERT_STREQ("Parse csv error in file /Users/tomichi/ClionProjects/semestralka/tests/RoomTests/hotel4wrong.csv on line 2", ex.c_str());

    }
}*/
