#include "Hotel.hpp"

const int TOTAL_ROOMS = 10;

void HotelManager::createRoom(){
    for( int i = 1; i <= TOTAL_ROOMS; i++){
        Room temp(i);
        Database_Room.push_back(temp);
    }
}
void HotelManager::displayAvailableRoom(){
    HotelManager::createRoom();
    int count_available_room = 0;
    for( auto check_status : Database_Room){
        if( check_status.isAvailable() == true) count_available_room++ ;
    }
    cout <<"LIST OF AVAILABLE ROOMS"    <<endl;
    TABLE_DRAW ("+------------------","-------", "+", count_available_room);   
    cout     <<"| Total room: ";
    printf ("%-5d", TOTAL_ROOMS);
    TABLE_DRAW ("","       ","|", count_available_room);
    cout     <<"| Room Number: ";
    for(auto check_status : Database_Room){
        if( check_status.isAvailable() == true) printf("|  %-4d", check_status.getRoomNumber()); 
    }
    cout <<"    |" <<endl;
    TABLE_DRAW ("+------------------","-------", "+", count_available_room);  
}