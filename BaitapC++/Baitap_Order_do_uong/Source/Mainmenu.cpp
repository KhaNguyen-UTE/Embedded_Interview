/*
* File Name: MainMenu.cpp
* Author: Nguyen Tran Minh Kha
* Date: 04/06/2023
* Description: The program is used to setup for Class MainMenu
*/

#include "Beverage.hpp"

/*
* Function: getPosition()
* Description: get position of employee
* Input:
*   none
* Output:
*   return the position of employee in type of TypePosition
*/
TypePosition MainMenu::getPosition(){
    return MainMenu::POSITION;
}

/*
* Function: Constructor MainMenu
* Description: get data
* Input:
*   none
* Output:
*   print the result
*/
MainMenu::MainMenu(){
    static Manage menu(this -> Database_Beverage, this -> numTable);
    static Staff order(this -> Database_Beverage, this -> numTable, this->Database_Oder);

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
            cin.ignore(100,'\n');                                      
            cout <<"-- Please enter the options available in the table --" <<endl;
            continue;
        }

        switch (MainMenu::POSITION){
            case MANAGER:
                    menu.displayMenu(); 
                    break;
            case STAFF:
                    if(numTable == 0){
                        cout <<"--PLEASE ENTER THE NUMBER OF TABLE--" <<endl;
                        menu.numberOfTable();
                    }
                    order.displayStaffMenu();
                    break;
        }
    }
}