#ifndef SEMESTRALKA_SEARCHENGINE_H
#define SEMESTRALKA_SEARCHENGINE_H

#include "Room.h"
#include <vector>

struct SearchResult{
    public:
        SearchResult(const bool, const int);
        ~SearchResult();
        bool const & getFound();
        int const & getIndex();
    private:
        int index;
        bool found;
};

class SearchEngine {
    public:
        SearchEngine();
        ~SearchEngine();
        static SearchResult findRoomInHotels(std::vector<Room*>, const int);
};


#endif //SEMESTRALKA_SEARCHENGINE_H
