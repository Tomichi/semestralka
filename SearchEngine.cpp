#include "SearchEngine.h"

SearchResult::SearchResult(const bool found, const int index) {
    this->found = found;
    this->index = index;
}

SearchResult::~SearchResult() { }

const bool SearchResult::getFound() const{
    return this->found;
}

const int SearchResult::getIndex() const{
    return this->index;
}

SearchEngine::SearchEngine() { }

SearchEngine::~SearchEngine() { }

SearchResult SearchEngine::findRoomInHotels(std::vector<Room> & hotel, const int index) {
    bool found = false;
    int indexFound = -1;

    for (std::vector<Room>::iterator it = hotel.begin(); it != hotel.end() && !found; ++it) {
        if (it->getId() == index) {
            found = true;
            indexFound = std::distance(hotel.begin(), it);
        }
    }

    return SearchResult(found, indexFound);
}