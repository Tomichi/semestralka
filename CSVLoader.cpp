#include "CSVLoader.h"

CSVLoader::CSVLoader(const char *sourceFileName) {
    std::string filename(sourceFileName);
    this->file = filename;
}

CSVLoader::~CSVLoader() {
}

void CSVLoader::parseRoomToHotel(Hotel &hotel) {
    std::ifstream ifs(this->file);
    std::string line;
    int id, capacity, prize, floor, door;
    char del1, del2, del3, del4;
    if (ifs.is_open()) {
        int lineCounter = 1;
       while( getline(ifs, line, '\n') ) {
           std::stringstream cline;
           cline << line;
           cline >> id >> del1 >> capacity >> del2 >> prize >> del3 >> floor >> del4 >> door;
           if (cline.fail() || !(del1 == del2 && del3 == del4 && del1 == del3)) {
               throw "Parse csv error in file " + this->file + " on line " + std::to_string(lineCounter);
           }

           try {
               Room room(id, capacity, prize, floor, door);
               hotel.pushRoomToDatabase(room);
           } catch (const InvalidRoomIdException & err ) {
               ifs.close();
               std::string message(err.what());
                throw message + " in file " + this->file +" on line " + std::to_string(lineCounter);
           } catch (const InvalidCapacityException & err) {
               ifs.close();
               std::string message(err.what());
               throw message + " in file " + this->file +" on line " + std::to_string(lineCounter);
           } catch (const InvalidPrizeException & err) {
               ifs.close();
               std::string message(err.what());
               throw message + " in file " + this->file +" on line " + std::to_string(lineCounter);
           } catch (const DuplicateIdRoomException & err) {
               ifs.close();
               std::string message(err.what());
               throw message + " in file " + this->file +" on line " + std::to_string(lineCounter);
           }
           ++lineCounter;
       }
    } else {
        throw "Error file is not open";
    }
}

void CSVLoader::parseReservation(Hotel & hotel, BookingCalendar &calendar) {
    std::ifstream ifs(this->file);
    std::string line;
    int id, year, month, day;
    char del1, del2, del3;
    if (ifs.is_open()) {
        int lineCounter = 1;
        while( getline(ifs, line, '\n') ) {
            std::stringstream cline;
            cline << line;
            cline >> id >> del1 >> year >> del2 >> month >> del3 >> day;
            if (cline.fail() || !(del1 == ';' && del2 == del3 && del2 == del3)) {
                ifs.close();
                throw "Parse csv error in file " + file +" on line " + std::to_string(lineCounter);
            }
            try {
                 SearchResult result = hotel.findRoomInHotels(id);
                 if (result.getFound() == false) {
                     ifs.close();
                     throw  "Id#" + std::to_string(id) + " doesnt exist error in file " + this->file + " on line "
                                  + std::to_string(lineCounter);
                 }

                calendar.reserveRoom(hotel.getRoomByIndex(result.getIndex()), year, month, day);
            } catch (const InvalidDateException & err) {
                ifs.close();
                throw "id#"+  std::to_string(id) +" doent exist in hotel in file " + this->file +
                      " on line " + std::to_string(lineCounter);
            }
            ++lineCounter;
        }
    } else {
        ifs.close();
        throw "Error file is not open";
    }


}