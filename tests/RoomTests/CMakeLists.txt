include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${SOURCE_FILES})


add_executable(runRoomTest
        TestRoomValidator.cpp
        TestRoom.cpp
        TestSearchEngine.cpp
        TestHotelValidator.cpp
        TestHotel.cpp
        TestDayReservation.cpp
        TestMonth.cpp
        TestYear.cpp
        TestBookingCalendar.cpp
        TestCsvLoader.cpp
        TestCsvLoadError.cpp
        )

target_link_libraries(runRoomTest gtest gtest_main)