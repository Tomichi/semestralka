#include "../../SearchEngine.h"
#include "../../SearchEngine.cpp"

#include "gtest/gtest.h"

class TestSearchEngine : public ::testing::Test {
protected:
    void SetUp() {
        for (int i = 1; i < 5; i++) {
            this->database.push_back(new Room(i, 2, 4, 4, 5));
        }
    }
    void TearDown() {
        for(unsigned long int i = 0; i < this->database.size(); i++) {
            delete this->database[i];
        }
        this->database.clear();
    }
    std::vector<Room*> database;
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



