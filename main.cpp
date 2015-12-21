/**
 * @file    main.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of main function
 *
 * This file contains implementation of main function
 */
#include <iostream>
#include <vector>
#include "Hotel.h"
#include "BookingCalendar.h"
#include "CSVLoader.h"
#include "Room.h"
#include "DateValidator.h"
#include "HtmlExport.h"

// This function print menu
void printMenu();

// This function print room information
void printRoom(std::vector<Room> &);

int main(int argc, char *argv[]) {
    // control input parameter
    if (argc != 3) {
        std::cout << "Invalid input parameters must be 2 input files,\n"
                " first file contains data from rooms and last one contains room reservation\n";
        return 1;
    }

    // Setup hotel
    Hotel hotel;

    // Setup Calendar to actual year
    BookingCalendar calendar(2015);
    try {
        // Try to load csv files
        CSVLoader roomCSV(argv[1]);
        roomCSV.parseRoomToHotel(hotel);

        CSVLoader registrationCSV(argv[2]);
        registrationCSV.parseReservation(hotel, calendar);
    } catch (std::string &er) {
        std::cout << er;
        return 1;
    }

    bool stop = false;
    while (1) {
        if (stop)
            break;
        int menu;
        printMenu();
        // Load which operation do user want
        std::cout << "Choose your choice\n";
        std::cin >> menu;
        if (std::cin.fail() || menu < 1 || menu > 6) {
            std::cout << "Wrong input was type. Try again.\n";
            break;
        }

        switch (menu) {
            case 1: {
                int id, y, m, d;

                // Load id
                std::cout << "Write id:";
                std::cin >> id;
                bool isCinOk = std::cin.fail();

                // Control if load was successful
                std::cout << "Write date by YYYY MM DD format:";
                std::cin >> y >> m >> d;
                    if (isCinOk || std::cin.fail() || !DateValidator::isDateValidate(y, m, d)) {
                    std::cout << "Wrong input was type. Try again.\n";
                    break;
                }

                // Control if room exist
                SearchResult result = hotel.findRoomInHotels(id);
                if (!result.getFound()) {
                    std::cout << "This id doesnt exist\n";
                    break;
                }
                try {
                    // Try to reserve room
                    calendar.reserveRoom(hotel.getRoomByIndex(result.getIndex()), y, m, d);
                } catch (std::string &er) {
                    std::cout << er;
                    break;
                }

                std::cout << "Booking room was successfully complete.\n";

                break;
            };
            case 2: {
                int y, m, d;

                // Load date
                std::cout << "Write date by YYYY MM DD format:";
                std::cin >> y >> m >> d;
                if (std::cin.fail() || !DateValidator::isDateValidate(y, m, d)) {
                    std::cout << "Wrong input was type. Try again.\n";
                    break;
                }

                // Find free rooms in this day
                std::vector<Room> rooms;
                try {
                    calendar.findFreeRoomInDay(hotel, y, m, d, rooms);
                } catch (std::string &er) {
                    std::cout << er;
                    rooms.clear();
                    break;
                }

                printRoom(rooms);
                rooms.clear();

                break;
            };
            case 3: {
                int y, m, d;

                // Load date
                std::cout << "Write date by YYYY MM DD format:";
                std::cin >> y >> m >> d;
                if (std::cin.fail() || !DateValidator::isDateValidate(y, m, d)) {
                    std::cout << "Wrong input was type. Try again.\n";
                    break;
                }

                // Load prize
                int prize;
                std::cout << "Type a max prize:\n";
                std::cin >> prize;
                if (std::cin.fail() || prize <= 0) {
                    std::cout << "Wrong input was type. Try again.\n";
                    break;
                }

                // Find free rooms in this day limited by prize
                std::vector<Room> rooms;
                try {
                    calendar.findFreeRoomInDayByPrize(hotel, prize, y, m, d, rooms);
                } catch (std::string &er) {
                    std::cout << er;
                    rooms.clear();
                    break;
                }

                printRoom(rooms);
                rooms.clear();

                break;
            };
            case 4: {
                int y, m, d;

                // Load date
                std::cout << "Write date by YYYY MM DD format:";
                std::cin >> y >> m >> d;
                if (std::cin.fail() || !DateValidator::isDateValidate(y, m, d)) {
                    std::cout << "Wrong input was type. Try again.\n";
                    break;
                }

                // Load capacity
                int capacity;
                std::cout << "Type a max capacity:\n";
                std::cin >> capacity;
                if (std::cin.fail() || capacity <= 0) {
                    std::cout << "Wrong input was type. Try again.\n";
                    break;
                }

                // Find free rooms in this day limited by capacity
                std::vector<Room> rooms;
                try {
                    calendar.findFreeRoomInDayByCapacity(hotel, capacity, y, m, d, rooms);
                } catch (std::string &er) {
                    std::cout << er;
                    rooms.clear();
                    break;
                }

                printRoom(rooms);
                rooms.clear();
                break;
            };
            case 5: {

                int y1, m1, d1, y2, m2, d2;

                std::cout << "Write date by start YYYY MM DD format:";
                std::cin >> y1 >> m1 >> d1;
                if (std::cin.fail() || !DateValidator::isDateValidate(y1, m1, d1)) {
                    std::cout << "Wrong input was type. Try again.\n";
                    break;
                }

                std::cout << "Write date by end YYYY MM DD format:";
                std::cin >> y2 >> m2 >> d2;
                if (std::cin.fail() || !DateValidator::isDateValidate(y2, m2, d2)) {

                    std::cout << "Wrong input was type. Try again.\n";
                    break;
                }

                // Load id room
                int id;
                std::cout << "Write id room:\n";
                std::cin >> id;
                SearchResult result = hotel.findRoomInHotels(id);
                if (std::cin.fail() || id <= 0 || !result.getFound()) {
                    std::cout << "Wrong input was type. Try again.\n";
                    break;
                }

                // export reservation of room
                std::vector<std::string> dates;
                calendar.findRoomByDateRange(hotel.getRoomByIndex(result.getIndex()), y1, m1, d1, y2, m2, d2, dates);
                HtmlExport html("output.html");
                html.flush(dates, hotel.getRoomByIndex(result.getIndex()).getId());
                break;
            };
            case 6: {
                // end program
                stop = true;
                break;

            };
        }
    }
    return 0;
}

void printMenu() {
    // Print menu
    std::cout << "1 - Reserve room\n"
            "2 - Search free rooms in day\n"
            "3 - Search free rooms in day by max prize\n"
            "4 - Search free rooms in day by max people capacity\n"
            "5 - Export room by id\n"
            "6 - Exit\n";
}

void printRoom(std::vector<Room> &rooms) {
    // Print information about room
    int size = (int) rooms.size();
    for (int i = 0; i < size; i++) {
        Room room = rooms.at(i);
        std::cout << "Room id#" << room.getId() << " capacity: " << room.getCapacity() << " prize: "
        << room.getPrize() << " floor: " << room.getRoomLocation().getFloor() <<
        " door: " << room.getRoomLocation().getDoor() << "\n";
    }
}
