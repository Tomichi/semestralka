#include "CSVLoader.h"

CSVLoader::CSVLoader(const char *source) {
    this->source = source;
}

CSVLoader::~CSVLoader() { }

void CSVLoader::parseRoomToHotel(Hotel &hotel) {
    this->ifs.open(this->source);
    string line;
    int id, capacity, prize, floor, door;
    char del1, del2, del3, del4;
    if (this->ifs.is_open()) {
        int lineCounter = 1;
       while( getline(ifs, line, '\n') ) {
           std::stringstream cline;
           cline << line;
           cline >> id >> del1 >> capacity >> del2 >> prize >> del3 >> floor >> del4 >> door;
           if (!cline.end && cline.fail() || !(d1 == d2 && d3 == d4 && d1 == d3)) {
               throw "Parse csv error in file " +std::to_string(this->source)+" on line " + std::to_string(lineCounter);
           }

           try {
               Room room(id, capacity, prize, floor, door);
               hotel.pushRoomToDatabase(room);
           } catch (const InvalidRoomIdException & err ) {
               this->ifs.close();
                throw err.what() + " in file " +std::to_string(this->source)+" on line " + std::to_string(lineCounter);
           } catch (const InvalidCapacityException & err) {
               this->ifs.close();
               throw err.what() + " in file " +std::to_string(this->source)+" on line " + std::to_string(lineCounter);
           } catch (const InvalidPrizeException & err) {
               this->ifs.close();
               throw err.what() + " in file " +std::to_string(this->source)+" on line " + std::to_string(lineCounter);
           } catch (const DuplicateIdRoomException & err) {
               this->ifs.close();
               throw err.what() + " in file " +std::to_string(this->source)+" on line " + std::to_string(lineCounter);
           }
           ++lineCounter;
       }
    } else {
        throw "Error file is not open";
    }
}

void CSVLoader::parseReservation(Hotel & hotel, BookingCalendar &calendar) {
    this->ifs.open(this->source);
    string line;
    int id, year, month, day;
    char del1, del2, del3;
    if (this->ifs.is_open()) {
        int lineCounter = 1;
        while( getline(ifs, line, '\n') ) {
            std::stringstream cline;
            cline << line;
            cline >> id >> del1 >> year >> del2 >> month >> del3 >> day;
            try {
                
            }

        }
    } else {
        throw "Error file is not open";
    }


}