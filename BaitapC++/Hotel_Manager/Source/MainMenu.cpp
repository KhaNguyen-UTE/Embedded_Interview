#include "Hotel.hpp"

const int TOTAL_ROOMS = 10;

void HotelManager::createRoom(){
    for( int i = 1; i <= TOTAL_ROOMS; i++){
        Room temp(i);
        Database_Room.push_back(temp);
    }
}
void HotelManager::displayAllRoom(){
    cout <<"LIST OF AVAILABLE ROOMS"    <<endl;
    TABLE_DRAW ("+------------------","-------", "+",TOTAL_ROOMS);   
    cout     <<"| Total room: ";
    printf ("%-5d", TOTAL_ROOMS);
    TABLE_DRAW ("","       ","|", TOTAL_ROOMS);
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

void HotelManager::displayCustomerSelection(CustomerManager menu){
    int selection;
    cout <<"        WELCOME TO HOTEL"             <<endl
         <<"+-------------------------------+"    <<endl
         <<"| Enter your choice             |"    <<endl  
         <<"|      1. Book Room             |"    <<endl
         <<"|      2. Check-in              |"    <<endl
         <<"|      3. Check-out             |"    <<endl
         <<"+-------------------------------+"    <<endl; 
    INPUT_DATA_NO_SPACE(" Your choice: ", selection);
    char next_selection;
    do{
        switch (selection){
            case 1:{
                RUN_SELECTION("continue to Book another room", next_selection, menu.addCustomer());
            }break;
        }
    }
    while (next_selection == '1');
}



HotelManager::HotelManager(){
    static CustomerManager menu (this->Database_Customer);
    int selection;
    while(true){
    cout <<"            HOTEL MANAGER"              <<endl
         <<"+-----------------------------------+"  <<endl
         <<"|      --Welcome to the Hotel--     |"  <<endl 
         <<"|  What is your position?           |"  <<endl
         <<"|      1. Hotel's Employee          |"  <<endl
         <<"|      2. Customer                  |"  <<endl
         <<"|      3. End the program           |"  <<endl
         <<"+-----------------------------------+"  <<endl;
    INPUT_DATA_NO_SPACE (" Your selection:", selection);
    if (selection == 3)    break;
    if (selection <= 0 || selection > 3 || cin.fail() == true){        // If input type is wrong, then require enter data again
        cin.clear();
        cin.ignore(100, '\n');
        cout <<endl << "-- Please enter the right value --" << endl;
    }

    char next_selection;
    do{
        switch (selection){
            case 1:{

            }break;
            case 2:{
                RUN_SELECTION("continue as Customer", next_selection, displayCustomerSelection(menu));
                
            }break;
        }
    }
    while(next_selection == '1'); 
    }
}