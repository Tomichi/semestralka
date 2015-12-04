include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${SOURCE_FILES})


add_executable(runRoomTest
        RoomValidatorTest.cpp
        RoomTest.cpp)

target_link_libraries(runRoomTest gtest gtest_main)