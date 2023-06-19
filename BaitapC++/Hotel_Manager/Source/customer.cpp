/*
* File Name: Customer.cpp
* Author: Nguyen Tran Minh Kha
* Date: 15/06/2023
* Description: The program is used to setup the function for Class Customer
*/

#include "Hotel.hpp"

/*
* Function: Customer()
* Description: get Customer data
* Input:
*   id - int
*   CusName - string
*   CusAddress - string
*   Cusphone - string
*   CusPassword - string
* Output:
*   None
*/
Customer::Customer (int id, string CusNAme, string CusAdddress, string Cusphone, string CusPassword){
    
    this->ID = id;
    this->NAME = CusNAme;
    this->ADDRESS = CusAdddress;
    this->PHONE_NUMBER = Cusphone;
    this->PASSWORD = CusPassword;
    
}

/*
* Function: getName()
* Description: get name for customer
* Input:
*   none
* Output:
*   return name in type of string
*/
string Customer::getName(){
     return Customer::NAME;
}

/*
* Function: setName()
* Description: set name for customer
* Input:
*   NAME - string
* Output:
*   none
*/
void Customer::setName(string name){
    this->NAME = name;
}

/*
* Function: getPHONE_NUMBER()
* Description: get phonenumber of customer
* Input:
*   none
* Output:
*   return phone number in type of string
*/
string Customer::getPHONE_NUMBER(){
     return Customer::PHONE_NUMBER;
}

/*
* Function: setPHONE_NUMBER()
* Description: set phone number for customer
* Input:
*   phone_number - string
* Output:
*   none
*/
void Customer::setPHONE_NUMBER(string phone_number){
    this->PHONE_NUMBER = phone_number;
}

/*
* Function: getADDRESS()
* Description: get address of customer
* Input:
*   none
* Output:
*   return address in type of string
*/
string Customer::getADDRESS(){
     return Customer::ADDRESS;
}

/*
* Function: setADDRESS()
* Description: set address for customer
* Input:
*   address - string
* Output:
*   none
*/
void Customer::setADDRESS(string address){
    this->ADDRESS = address;
}

/*
* Function: getPASSWORD()
* Description: get password of customer
* Input:
*   none
* Output:
*   return password in type of string
*/
string Customer::getPASSWORD(){
    return Customer::PASSWORD;
}

/*
* Function: setPASSWORD()
* Description: set password for customer
* Input:
*   password - string
* Output:
*   none
*/
void Customer::setPASSWORD(string password){
    this->PASSWORD = password;
}

/*
* Function: getID()
* Description: get ID of customer
* Input:
*   none
* Output:
*   return ID in type of int
*/
int Customer::getID(){
    return Customer::ID;
}

/*
* Function: addBokking()
* Description: add room into Database
* Input:
*   var: vector BookingHistory
* Output:
*   add room was booked into vector database
*/
void Customer::addBokking(BookingHistory var){
    History.push_back(var);
}

/*
* Function: check_password()
* Description: use for checking input password
* Input:
*   ID : int
* Output:
*   return true if right password or return false
*/
bool CustomerManager::check_password(int ID){
    string password;
    INPUT_DATA_NO_SPACE("Enter your Customer password: ", password);
    for (auto &temp : *Database_Customer){
        if (ID == temp.getID()){
            if (password == temp.getPASSWORD()) return true;
        }
    }
    return false;
}

/*
* Function: check_ID()
* Description: use for checking room ID
* Input:
*   ID : int
* Output:
*   return true if have ID in Database or return false
*/
bool CustomerManager::check_ID(int ID){
    for( auto &temp : *Database_Customer){
        if (ID == temp.getID()) return true;
    }
    return false;
}

/*
* Function: Constructor CustomerManager
* Description: get data
* Input:
*   &Database_Customer - vector <Customer>
* Output:
*   none
*/
CustomerManager::CustomerManager(vector <Customer> &Database_Customer){
    this->Database_Customer = &Database_Customer;
}

/*
* Function: addCustomer()
* Description: add customer into Database of customer
* Input:
*   id : int
* Output:
*   print the result and function
*/
void CustomerManager::addCustomer(int id){

    string name;
    string phone_number;
    string address;
    string password;
    cin.ignore(100, '\n');
    
    check_input(&name, NAME);
    check_input(&address, ADDRESS);
    check_input(&phone_number, PHONE_NUMBER);
    INPUT_DATA_NO_SPACE("Enter new password: ", password);
    cin.ignore(100, '\n');
    Customer add(id, name, address,phone_number, password);
    Database_Customer->push_back(add);
    cout <<"-- Successfulled Booking Room --" <<endl;
    CustomerManager::listOneCustomer(add.getID());
}

/*
* Function: deleteCustomer()
* Description: delete customer in Database of customer
* Input:
*   ID : int
* Output:
*   print the result
*/
void CustomerManager::deleteCustomer(int ID){
    bool status_delete = false;
    vector<Customer>::iterator vector_index = (*Database_Customer).begin();
    for (auto &temp : *Database_Customer){
        if (temp.getID() == ID){
            (*Database_Customer).erase(vector_index);
            cout <<"--Already delete--" <<endl;
            status_delete = true;
        }
        vector_index++;
    }
    if (status_delete == false) cout <<"--Don't have ID customer in Database--" <<endl;
}

/*
* Function: editCustomer()
* Description: update customer into Database of customer
* Input:
*   none
* Output:
*   print the result
*/
void CustomerManager::editCustomer(){
    bool edit_status = false;
    int id;
    int vector_index = 0;
    INPUT_DATA_NO_SPACE("Enter ID: ", id);
    for (auto &temp : *Database_Customer){
        if (id == temp.getID()){
            while (edit_status == false){

                string name;
                string phone_numeber;
                string address;
                string password;
                cout <<"What do you want to edit ?" <<endl
                    <<"    1. Name"                <<endl
                    <<"    2. Address"             <<endl
                    <<"    3. Password"            <<endl
                    <<"    4. Phone Number"        <<endl
                    <<"    5. Back to Menu"        <<endl;
                int edit_selection;
                INPUT_DATA_NO_SPACE("Your selection: ", edit_selection);
                if (edit_selection == 5)    break;
                if (edit_selection <= 0 || edit_selection > 5 || cin.fail() == true){        // If input type is wrong, then require enter data again
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout <<endl << "-- Please enter the right value --" << endl;
                    continue;
                }

                switch (edit_selection){
                case 1:
                    cin.ignore(100, '\n');
                    check_input(&name, NAME);
                    temp.setName(name);
                    break;
                case 2:
                    cin.ignore(100, '\n');
                    check_input(&address, ADDRESS);
                    temp.setADDRESS(address);
                    break;
                case 3:
                    cin.ignore(100, '\n');
                    INPUT_DATA_NO_SPACE("Enter new Customer password: ", password);
                    temp.setPASSWORD(password);
                    break;
                case 4:
                    cin.ignore(100, '\n');
                    check_input(&phone_numeber, PHONE_NUMBER);
                    temp.setPHONE_NUMBER(phone_numeber);
                    break;
                case 5:
                    break;
                }
                (*Database_Customer)[vector_index] = temp;
                cout <<"--Already edited--" <<endl;
                edit_status = true;
            }
        }
        vector_index++;
    }
    if(edit_status == false) cout <<"--Don't have info in Database--" <<endl;
}

/*
* Function: enterHistory()
* Description: enter the history of check In or check Out of Customer
* Input:
*   in_out : int
*   ID : int
* Output:
*   print the result ad function
*/
void CustomerManager::enterHistory(int in_out, int ID){
    int day;
    int month;
    int year;
    int second;
    int minute;
    int hour;

    Check::check_input(&day, DAY);
    Check::check_input(&month, MONTH);
    Check::check_input(&year, YEAR);
    Check::check_input(&second, SECOND);
    Check::check_input(&minute, MINUTE);
    Check::check_input(&hour, HOUR);

    BookingHistory InOut;

    InOut.date.day = day;
    InOut.date.month = month;
    InOut.date.year = year;
    InOut.time.hour = hour;
    InOut.time.minute = minute;
    InOut.time.second = second;

    if (in_out == 2) InOut.status = IN;
    else if( in_out == 3) InOut.status = OUT;

    for( auto &temp : *Database_Customer){
        if( ID == temp.getID()){
            temp.History.push_back(InOut);
            break;
        }
    }
}   

/*
* Function: CheckInorOut()
* Description: set the data of Check In or Check Out of Customer
* Input:
*   InorOut : int
* Output:
*   print the result and function
*/
void CustomerManager::CheckInorOut(int InorOut){
    int id;
    INPUT_DATA_NO_SPACE("Enter your room ID: ", id);
    if ( check_ID(id) == true){
        int error_count = 0;
        bool check_status = true;
        while(check_status  == true){
        if (check_password(id) == true){
            enterHistory(InorOut, id);
            check_status= false;
        }
        else{
            error_count++;
            cout <<"-- Wrong password (" <<error_count <<"/3) --" <<endl;
            if (error_count <=3){
                cout <<"Re-enter password: " <<endl;
            }
            else{
                cout<<"--YOU HAVE ENTERED THE WRONG PASSWORD TOO MANY TIMES--" <<endl;
                check_status = false;
            }
            }
        }
    }
    else{
        cout <<"--Don't have your room ID in Database--" <<endl;
    }
}

/*
* Function: listOneCustomer()
* Description: show the information of 1 Cusstomer except for PASSWORD base on input ID
* Input:
*   ID : int
* Output:
*   print the result
*/
void CustomerManager::listOneCustomer(int ID){
    cout <<"                              DATA CUSTOMER                              "     <<endl  
         <<"+------------------------------------------------------------------------+"    <<endl
         <<"|  ID  |        Name      |     Phone number     |        Address        |"    <<endl
         <<"|------------------------------------------------------------------------|"    <<endl;

    for (auto &temp : *Database_Customer){
        if( ID == temp.getID()){
        printf("|  %-4d|  %-16s|  %-20s|  %-21s|\n", temp.getID(),temp.getName().c_str(), temp.getPHONE_NUMBER().c_str(), temp.getADDRESS().c_str());
        }
    }
    cout <<"+------------------------------------------------------------------------+"    <<endl;
}

/*
* Function: listCustomer()
* Description: show the information of All Cusstomer except for PASSWORD
* Input:
*   None
* Output:
*   print the result
*/
void CustomerManager::listCustomer(){
    cout <<"                                               DATA CUSTOMER                              "                        <<endl  
         <<"+------------------------------------------------------------------------------------------------------------+"    <<endl
         <<"|      |                  |                      |                       |               History             |"    <<endl
         <<"|  ID  |        Name      |     Phone number     |        Address        |-----------------------------------|"    <<endl
         <<"|      |                  |                      |                       | Status |           Time           |"    <<endl
         <<"|============================================================================================================|"    <<endl;

    int length = (*Database_Customer).size();

    for (auto &temp : *Database_Customer){
        printf("|  %-4d|  %-16s|  %-20s|  %-21s|", temp.getID(),temp.getName().c_str(), temp.getPHONE_NUMBER().c_str(), temp.getADDRESS().c_str());
        bool begin = true;

        if ( temp.History.size() == 0) cout <<"                                   |" <<endl;

        for(auto inout : temp.History){
            string status;

            if (inout.status == IN) status ="IN";
            else status ="OUT";

            if (begin == true) begin = false;
            else    printf("|      |                  |                      |                       |");

            printf("   %-5s|  ", status.c_str());
            PRINT_ZERO(inout.time.hour,":");
            PRINT_ZERO(inout.time.minute,":");
            PRINT_ZERO(inout.time.second,"    ");
            PRINT_ZERO(inout.date.day,"/");
            PRINT_ZERO(inout.date.month,"/");
            PRINT_ZERO(inout.date.year,"  |");
            cout <<endl;
        }
        length--;

        if(length != 0)
        cout <<"|------------------------------------------------------------------------------------------------------------|"    <<endl;
    }
    cout <<"+------------------------------------------------------------------------------------------------------------+"    <<endl;
}

   
