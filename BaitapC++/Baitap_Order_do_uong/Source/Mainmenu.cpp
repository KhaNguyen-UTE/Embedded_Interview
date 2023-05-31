#include "Do_uong.h"

TypePosition MainMenu::getPosition(){
    return MainMenu::POSITION;
}

MainMenu::MainMenu(){
    uint8_t i_position;
    INPUT_DATA ("Chon vi tri cua ban", i_position);
    if (i_position == 1) MainMenu::POSITION = MANAGER;
    else if (i_position == 2) MainMenu::POSITION = STAFF;
    else{
        cin.clear();
        cin.ignore();
        cout <<"--Vui long nhap lua chon cos trong menu" <<endl;
    }
}