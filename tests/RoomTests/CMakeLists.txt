include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${SOURCE_FILES}})


add_executable(runRoomTest RoomTest.cc)

target_link_libraries(runRoomTest gtest gtest_main)