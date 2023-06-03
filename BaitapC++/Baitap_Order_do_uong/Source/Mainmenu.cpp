#include "Beverage.hpp"

TypePosition MainMenu::getPosition(){
    return MainMenu::POSITION;
}

MainMenu::MainMenu(){
    static Manage menu(this -> Database_Beverage, this -> numTable);
    static Staff order(this -> Database_Beverage, this -> numTable);
    while (true){
    int i_position;
    cout << "+-----------------------+" <<endl
         << "|       Main Menu       |" <<endl
         << "|   1. Manager          |" <<endl
         << "|   2. Staff            |" <<endl
         << "+-----------------------+" <<endl;
    INPUT_DATA ("Select postion / Enter 0 for exit: ", i_position);
    if (i_position == 1) MainMenu::POSITION = MANAGER;
    else if (i_position == 2) MainMenu::POSITION = STAFF;
    else if (i_position == 0) break;
    else {
        cin.clear();
        cin.ignore(100, '\n');
        cout <<"-- Please enter the options available in the table --" <<endl;
        continue;
    }
    switch (MainMenu::POSITION){
        case MANAGER:
                    menu.displayMenu(); 
                    break;
        case STAFF: 
                    order.displayStaffMenu();
                    break;
    }
    }
}