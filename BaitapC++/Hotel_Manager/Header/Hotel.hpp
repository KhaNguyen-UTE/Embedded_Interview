#ifndef __HOTEL_H
#define __HOTEL_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

#define TABLE_DRAW(text_begin, text_mid, text_end, loop_value)                              \
cout << text_begin;                                                                         \
for (int i = 0; i < loop_value; i++){                                                       \
cout << text_mid;                                                                           \
}                                                                                           \
cout << text_end  <<endl;                                                                   \

#define INPUT_DATA_NO_SPACE(text, var)                                                      \
cout << text;                                                                               \
cin  >> var;                                                                                \

#define INPUT_DATA_HAVE_SPACE(text, name)                                                     \
cout << text;                                                                                               \
getline(cin, name);                                                                                         \
                                


class Room{
    private:
        int roomNumber;
        bool isBooked;
        bool isCleaned;
    public:
        Room(int number){
            roomNumber = number;
            isBooked = false;
            isCleaned = true;
        }

        int getRoomNumber(){
            return roomNumber;
        }

        bool isAvailable(){
            return !isBooked && isCleaned;
        }

        void bookRoom(){
            isBooked = true;
        }

        void checkIn(){
            isCleaned = false;
            isBooked = true;
        }

        void checkOut(){
            isBooked = false;
            isCleaned = true;
        }
};

class HotelManager{
    private:
        vector <Room> Database_Room;
        void createRoom();
        void bookRoom(uint8_t roomNumber);
        void checkIn(uint8_t roomNumber);
        void checkOut(uint8_t roomNumber);
    public:
        void displayAvailableRoom();
};

#endif