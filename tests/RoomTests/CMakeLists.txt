include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${SOURCE_FILES})


add_executable(runRoomTest
        TestRoomValidator.cpp
        TestRoom.cpp
        TestSearchEngine.cpp
        TestHotelValidator.cpp)

target_link_libraries(runRoomTest gtest gtest_main)