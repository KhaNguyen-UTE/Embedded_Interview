/*
* File Name: MainMenu.cpp
* Author: Nguyen Tran Minh Kha
* Date: 15/06/2023
* Description: The program is used to setup for Class HotelManager to create the menu for program
*/

#include "Hotel.hpp"

/*
* Function: createRoom()
* Description: creat the initial Room status with all Room is Available
* Input:
*   none
* Output:
*   none
*/
void HotelManager::createRoom(){
    for( int i = 101; i <= TOTAL_ROOMS + 100; i++){
        Room temp(i);
        Database_Room.push_back(temp);
    }
}

/*
* Function: displayAllRoom()
* Description: show all room with all status like Cleaning(CL), Booking(NO) and Availabling(OK)
* Input:
*   none
* Output:
*   none
*/
void HotelManager::displayAllRoom(){
    cout <<"LIST OF ROOMS"    <<endl;
    TABLE_DRAW ("+------------------","-------", "+",TOTAL_ROOMS-1);   
    cout     <<"| Total room: ";
    printf ("%-5d", TOTAL_ROOMS);
    TABLE_DRAW ("","       ","|", TOTAL_ROOMS - 1);
    cout     <<"|     Room Number: ";
    for (int i = 101; i <= 100 + TOTAL_ROOMS; i++){
        printf("| %-4d", i);
    }
    cout <<"   |"  <<endl <<"|     Room Status: ";
        for( auto check_status : Database_Room){
            if(check_status.isAvailable() == true)        cout <<"| OK  ";
            else if(check_status.isAvailable() == false && check_status.isClean() == false)  cout <<"| NO  ";
            else if(check_status.isAvailable() == false && check_status.isClean() == true)       cout <<"| CL  ";
        }
    cout <<"   |" <<endl;
    TABLE_DRAW ("+------------------","-------", "+", TOTAL_ROOMS-1);  
}

/*
* Function: displayAvailableRoom()
* Description: show only available room for booking
* Input:
*   none
* Output:
*   none
*/
void HotelManager::displayAvailableRoom(){
    //Create the Table for showwing available Room
    int count_available_room = 0;
    for( auto check_status : Database_Room){
        if( check_status.isAvailable() == true) count_available_room++ ;
    }
    cout <<"LIST OF AVAILABLE ROOMS"    <<endl;
    TABLE_DRAW ("+------------------","-------", "+", count_available_room);   
    cout <<"| Total room: ";
    printf ("%-5d", TOTAL_ROOMS);
    TABLE_DRAW ("","       ","|", count_available_room);
    cout <<"| Room Number: ";
    for(auto check_status : Database_Room){
        if( check_status.isAvailable() == true) printf("|  %-4d", check_status.getRoomNumber()); 
    }
    cout <<"    |" <<endl;
    TABLE_DRAW ("+------------------","-------", "+", count_available_room);  
}

/*
* Function: displayCustomerSelection()
* Description: show the Menu function of Customer
* Input:
*   menu: CustomerManager
* Output:
*   none
*/
void HotelManager::displayCustomerSelection(CustomerManager menu){
    int selection;
    do{
        cout <<"          WELCOME TO HOTEL"             <<endl
            <<"+----------------------------------+"    <<endl
            <<"| Enter your choice                |"    <<endl  
            <<"|      1. Book Room                |"    <<endl
            <<"|      2. Check-in                 |"    <<endl
            <<"|      3. Check-out                |"    <<endl
            <<"|      4. Pay                      |"    <<endl
            <<"|      5. Back to previous menu    |"    <<endl
            <<"+----------------------------------+"    <<endl; 
        INPUT_DATA_NO_SPACE("Your choice: ", selection);

        if (selection <= 0 || selection > 5 || cin.fail() == true){        // If input type is wrong, then require enter data again
            cin.clear();
            cin.ignore(100, '\n');
            cout <<endl << "-- Please enter the option in Menu --" << endl;
            continue;
        }
        
        switch (selection){
            case 1:{
                displayAvailableRoom();
                int id;
                bool status = true;
                INPUT_DATA_NO_SPACE("Chosse your room/ID: ", id);
                if(id >100 and id <= TOTAL_ROOMS + 100){
                    int vector_index = 0;
                    for (auto check_id : Database_Room){
                        if (check_id.isAvailable() == true && check_id.getRoomNumber() == id){
                            menu.addCustomer(id);
                            Database_Room[vector_index].bookRoom();
                            status = false;
                        }
                        vector_index++;
                    }
                    if (status == true) cout<<"--Please choose another Room--" <<endl;
                }
            }break;

            case 2:
            case 3:
                menu.CheckInorOut(selection);
                break;

            case 4:{
                int selection;
                int id;
                bool check_id = false;
                INPUT_DATA_NO_SPACE("Enter your ID: ", id);
                for (auto temp : Database_Customer){
                    if (id == temp.getID()){
                        cout <<"Which option do you want to pay?" <<endl
                             <<"       1. Cash"                   <<endl
                             <<"       2. Momo"                   <<endl;
                        INPUT_DATA_NO_SPACE("Your choice: ", selection);
                        menu.deleteCustomer(id);
                        int vector_index = 0;
                        for (auto clean : Database_Room){
                            if (clean.getRoomNumber() == id){
                                Database_Room[vector_index].checkOut();
                                break;
                            }
                            vector_index++;
                        }
                        check_id = true;
                    }
                }
                if (check_id == false) cout<<"--Don't have your Room ID in Database--" <<endl;
            }break;
                
        }
    }
    while (selection != 5);
}

/*
* Function: SelectionMenu()
* Description: create the Human menu for Manager and Recepionist function
* Input:
*   position: int
*   emp_menu: EmployeeManager 
*   cus_menu: CustomerManager 
* Output:
*   none
*/
void HotelManager::SelectionMenu(int position,EmployeeManager emp_menu, CustomerManager cus_menu){
    int selection;
    string text;
    
    if (position == 1) text = "Employee";
    else       text = "Customer";
    while(true){
        cout<<"            HUMAN MENU"                       <<endl
            <<"+--------------------------------+"           <<endl
            <<"|    1. Add "    <<text    <<"             |" <<endl
            <<"|    2. Deleted " <<text   <<"         |"     <<endl
            <<"|    3. Edit "    <<text   <<"            |"  <<endl
            <<"|    4. Display " <<text   <<"         |"     <<endl;

        //2 different functions of Manager and Receptionist
        if(position == 1){
        cout<<"|    5. Add Employee shift       |"           <<endl;
        }
        else{
        cout<<"|    5. Set room status          |"           <<endl;
        }

        cout<<"|    6. Back to previous menu    |"           <<endl
            <<"+--------------------------------+"           <<endl;
        
        INPUT_DATA_NO_SPACE("Your choice: ", selection);
        if (selection == 6)   break;
        if (selection <= 0 || selection > 6 || cin.fail() == true){        // If input type is wrong, then require enter data again
            cin.clear();
            cin.ignore(100, '\n');
            cout <<endl << "-- Please enter the option in Human Menu --" << endl;
            continue;
        }
        
        if(position == 2){
            int emp_ID, cus_ID;
            INPUT_DATA_NO_SPACE("Enter your Receptionist ID: ", emp_ID);
            if (emp_menu.check_ID(emp_ID) == false)  cout <<"--Don't have your ID in Database--" <<endl;
            else{
                if(emp_menu.check_Position(emp_ID, RECEPTIONIST) == false)  cout <<"-- Your position do not permit --" <<endl;
                else{
                    int error_count = 0;
                    bool check_status = true;
                    while(check_status  == true){
                    if (emp_menu.check_password(emp_ID) == true){
                        cout <<endl;
                        check_status = false;
                        char next_selection;
                        do{
                        switch (selection){
                        case 1:{
                            displayAvailableRoom();
                            int id;
                            bool status = true;
                            INPUT_DATA_NO_SPACE("Chosse your room/ID: ", id);
                            if(id >100 and id <= TOTAL_ROOMS + 100){
                                int vector_index = 0;
                                for (auto check_id : Database_Room){
                                     if (check_id.isAvailable() == true && check_id.getRoomNumber() == id){
                                        cus_menu.addCustomer(id);
                                        check_id.bookRoom();
                                        Database_Room[vector_index].bookRoom();
                                        status = false;
                                     }
                                     vector_index++;
                                }
                                if (status == true) cout<<"--Please choose another Room--" <<endl;
                            }
                        }
                            break;
                        case 2:
                            INPUT_DATA_NO_SPACE("Enter Customer ID: ", cus_ID);
                            if(cus_menu.check_ID(cus_ID) ==true){
                            int vector_index = 0;
                            RUN_SELECTION("continue DELETE Customer", next_selection, cus_menu.deleteCustomer(cus_ID));
                            for(auto temp : Database_Room){
                                if (temp.getRoomNumber() == cus_ID){
                                    Database_Room[vector_index].checkOut();
                                    break;
                                }
                                vector_index++;
                            }
                            }
                            else cout <<"--Don't have Customer ID in Database--" <<endl;
                            break;
                        case 3:
                            RUN_SELECTION("continue EDIT Customer", next_selection, cus_menu.editCustomer());
                            break;
                        case 4:
                            cus_menu.listCustomer();
                            break;
                        case 5:
                            displayAllRoom();
                            int vector_index = 0;
                            bool status = false;
                            INPUT_DATA_NO_SPACE("Enter Room ID: ", cus_ID);
                            if(cus_ID > 100 and cus_ID <= TOTAL_ROOMS + 100){
                            for (auto temp : Database_Room){
                                    if( temp.getRoomNumber() == cus_ID && temp.isClean() == true){
                                        Database_Room[vector_index].book();
                                        status = true;
                                    }
                                    vector_index++;  
                            }
                            if (status == true) displayAllRoom();
                            else cout<<"-- Room cannot be Cleaned because it is Booked or Cleaned --" <<endl;
                            }
                            else cout <<"-- Please enter the right value --" <<endl;
                            break;
                        }
                        if (cin.fail()== true){
                            cin.clear();
                            cin.ignore(100, '\n');
                            next_selection = 0;
                        }
                        }
                        while (next_selection == '1');
                        }
                    else{
                        error_count++;
                        cout <<"-- Wrong password (" <<error_count <<"/3) --" <<endl;
                        if (error_count <=3){
                            cout <<"Re-enter password: " <<endl;
                        }
                        else{
                            cout<<"-- YOU HAVE ENTERED THE WRONG PASSWORD TOO MANY TIMES --" <<endl;
                            check_status = false;
                        }
                    }
                    }
                }
            }   
        }
        else{
            int emp_ID;
            int error_count = 0;
            bool check_status = true;
            while(check_status  == true){
                if (emp_menu.check_password(100) == true){
                    cout <<endl;
                    check_status = false;
                    char next_selection;
                    do{
                        switch (selection){
                            case 1:
                                RUN_SELECTION("continue ADD Employee", next_selection, emp_menu.addEmployee());
                                break;
                            case 2:
                                INPUT_DATA_NO_SPACE("Enter Employee ID: ", emp_ID);
                                if(emp_menu.check_ID(emp_ID) ==true){
                                    RUN_SELECTION("continue DELETE Employee", next_selection, emp_menu.deleteEmployee(emp_ID));
                                }
                                else cout <<"-- Don't have Employee ID in Database --" <<endl;
                                break;
                            case 3:
                                RUN_SELECTION("continue EDIT Employee", next_selection, emp_menu.editEmployee());
                                break;
                            case 4:
                                emp_menu.displayEmployee();
                                break;
                            case 5:
                                INPUT_DATA_NO_SPACE("Enter Employee ID: ", emp_ID);
                                if(emp_menu.check_ID(emp_ID) ==true){
                                    emp_menu.addShift(emp_ID);
                                }
                                else{
                                    cout <<"-- Don't have Employee ID in Database --" <<endl;
                                }
                                break;
                            }
                        if (cin.fail()== true){
                            cin.clear();
                            cin.ignore(100, '\n');
                            next_selection = 0;
                        }
                    }
                    while (next_selection == '1');
                }
                else{
                    error_count++;
                    cout <<"-- Wrong password (" <<error_count <<"/3) --" <<endl;
                    if (error_count <=3){
                        cout <<"Re-enter password: " <<endl;
                    }
                    else{
                        cout<<"-- YOU HAVE ENTERED THE WRONG PASSWORD TOO MANY TIMES --" <<endl;
                        check_status = false;
                    }
                }
            }
        }
    }
}
    
/*
* Function: displayEmployeeSelection()
* Description: create a Menu function for employee (Manager and Receptionist)
* Input:
*   emp_menu: class EmployeeManager
*   cus_menu: class CustomerManager
* Output:
*   none
*/
void HotelManager::displayEmployeeSelection(EmployeeManager emp_menu, CustomerManager cus_menu){
    int selection;
    while(true){
    cout <<"             EMPLOYEE MENU"              <<endl
         <<"+----------------------------------+"    <<endl
         <<"| Enter your position              |"    <<endl  
         <<"|      1. Manager                  |"    <<endl
         <<"|      2. Receptionist             |"    <<endl
         <<"|      3. Back to previous menu    |"    <<endl
         <<"+----------------------------------+"    <<endl; 
    cin.ignore(100, '\n');     
    INPUT_DATA_NO_SPACE("Your choice: ", selection);
    if (selection == 3)    break;
    if (selection <= 0 || selection > 2 || cin.fail() == true){        // If input type is wrong, then require enter data again
        cin.clear();
        cin.ignore(100, '\n');
        cout <<endl << "-- Please enter the right value --" << endl;
    }
    else if(selection == 2){
            if(emp_menu.check_num_Receptionist() == true) SelectionMenu(selection, emp_menu, cus_menu);
            else cout <<"-- Please add RECEPTIONIST --" <<endl;
         }       
    else SelectionMenu(selection, emp_menu, cus_menu);
    }
}

/*
* Function: HotelManager()
* Description: Create the welcome menu for Hotel
* Input:
*   None
* Output:
*   None
*/
HotelManager::HotelManager(){
    HotelManager::createRoom();
    static CustomerManager cus_menu (this->Database_Customer);
    static EmployeeManager emp_menu (this->Database_Employee);
    emp_menu.createManager();
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
    INPUT_DATA_NO_SPACE (" Your selection: ", selection);
    if (selection == 3)    break;
    if (selection <= 0 || selection > 3 || cin.fail() == true){        // If input type is wrong, then require enter data again
        cin.clear();
        cin.ignore(100, '\n');
        cout <<endl << "-- Please enter the right value --" << endl;
    }
    switch (selection){
            case 1:{
                displayEmployeeSelection(emp_menu,cus_menu);
            }break;
            case 2:{
                displayCustomerSelection(cus_menu);
            }break;
        }
    }
}