#include "../../SearchEngine.h"
#include "../../SearchEngine.cpp"

#include "gtest/gtest.h"

class TestSearchEngine : public ::testing::Test {
protected:
    void SetUp() {
        for (int i = 1; i < 5; i++) {
            Room room(i, 2, 3, 4, 5);
            this->database.push_back(room);
        }
    }

    void TearDown() {
        this->database.clear();
    }

    std::vector<Room> database;
};


TEST_F(TestSearchEngine, tetsFindExistId) {
    SearchResult result = SearchEngine::findRoomInHotels(this->database, 1);
    EXPECT_TRUE(result.getFound());
    EXPECT_EQ(0, result.getIndex());

    result = SearchEngine::findRoomInHotels(this->database, 4);
    EXPECT_TRUE(result.getFound());
    EXPECT_EQ(3, result.getIndex());
}

TEST_F(TestSearchEngine, tetsNotFindId) {
    SearchResult result = SearchEngine::findRoomInHotels(this->database, 5);
    EXPECT_FALSE(result.getFound());
    EXPECT_EQ(-1, result.getIndex());
}



