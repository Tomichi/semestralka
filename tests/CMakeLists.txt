add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${SOURCE_FILES})


add_executable(runTest
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

target_link_libraries(runTest gtest gtest_main)