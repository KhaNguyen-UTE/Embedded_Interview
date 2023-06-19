#ifndef __HOTEL_H
#define __HOTEL_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

const int TOTAL_ROOMS = 10;

#define TABLE_DRAW(text_begin, text_mid, text_end, loop_value)                              \
cout << text_begin;                                                                         \
for (int i = 0; i < loop_value; i++){                                                       \
cout << text_mid;                                                                           \
}                                                                                           \
cout << text_end  <<endl;                                                                   \

#define INPUT_DATA_NO_SPACE(text, var)                                                      \
cout << text;                                                                               \
cin  >> var;                                                                                \
cout <<endl;                                                                                \

#define INPUT_DATA_HAVE_SPACE(text, name)                                                   \
cout << text;                                                                               \
getline(cin, name);                                                                         \

#define RUN_SELECTION(text, var, run)                        \
run;                                                         \
cout << "Enter the next selection" <<endl;                   \
cout << "    - Press 1 to " <<text <<endl;                   \
cout << "    - Any key to bak to Main stream" <<endl;        \
cout << "Your selection: ";                                  \
cin  >> var;                                                 \

#define PRINT_ZERO(var, text)                                \
if( var < 10 ) cout <<"0" <<var;                             \
else cout<<var;                                              \
cout <<text;                                                 \

typedef struct {
    int day;
    int month;
    int year;
}typeDate;

typedef struct {
    int second;
    int minute;
    int hour;
}typeTime;

typedef enum{
    IN,
    OUT
}TypeStatus;

typedef struct {
    typeDate date;
    typeTime time;
    TypeStatus status;
}BookingHistory;

typedef enum{
    DAY_SHIFT,
    AFTERNOON_SHIFT,
    NIGHT_SHIFT,
    ALL_DAY
}TypeShift;

typedef enum{
    MANAGER,
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LAUGGAGE_STAFF,
    GRADENER
}TypeJobPosition;

typedef enum{
    NAME,
    ADDRESS,
    PHONE_NUMBER,
    POSITION,
    DAY,
    MONTH,
    YEAR,
    SECOND,
    MINUTE,
    HOUR
}TypeInput;

class Room{
    private:
        int roomNumber;
        bool isBooked;
        bool isCleaned;
    public:
        Room(int number){
            roomNumber = number;
            isBooked = false;
            isCleaned = false;
        }

        int getRoomNumber(){
            return roomNumber;
        }

        bool isAvailable(){
            return !isBooked && !isCleaned;
        }

        bool isClean(){
            return isCleaned;
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
        void book(){
            isBooked = false;
            isCleaned = false;
        }
};



class Check{
    public:
        void check_input(void * text, TypeInput type);
        bool check_limit( int text, int upper_limit, int lower_limit);
};

class Customer {
    private:
        int ID;    
        string NAME;
        string PHONE_NUMBER;
        string ADDRESS;
        string PASSWORD;
    public:
        Customer (int ID, string CusNAme, string CusAdddress, string Cusphone, string CusPassword);

        string getName();
        void setName(string name);

        string getPHONE_NUMBER();
        void setPHONE_NUMBER(string phone_number);

        string getADDRESS();
        void setADDRESS(string address);

        string getPASSWORD();
        void setPASSWORD(string password);
        
        void addBokking(BookingHistory var);

        vector <BookingHistory> History;

        int getID();
};

class CustomerManager : public Check{
    private:
        vector <Customer>  *Database_Customer;
    public:
        CustomerManager(vector <Customer> &Database_Customer);
        void addCustomer(int id);
        void editCustomer();
        void deleteCustomer(int ID);
        void listOneCustomer(int ID);
        void listCustomer();
        void CheckInorOut(int In_or_Out);
        void enterHistory(int in_out, int ID);
        bool check_password(int ID);
        bool check_ID(int ID);
};

class Employee{
    private:
        int ID; 
        string NAME;
        string PHONENUMBER;
        string PASSWORD;
        TypeJobPosition POSITION;
        
    public:
        Employee(string name, string phone, string password, TypeJobPosition position);
        vector <TypeShift> SHIFT;
        string getName();
        void setName(string name);

        string getPHONE_NUMBER();
        void setPHONE_NUMBER(string phone_number);

        TypeJobPosition getPOSITION();
        void setPOSITION(TypeJobPosition position);

        string getPASSWORD();
        void setPASSWORD(string password);
        
        void addSchedule(TypeShift shift);
        void displaySchedule();

        int getID();
};

class EmployeeManager : public Check{
    private:
        vector <Employee> *Database_Employee;
        bool check_num_Manager();
       
        void transfer_position(int value, TypeJobPosition *TypeJobPosition);
    public:
    
        EmployeeManager(vector <Employee> &Database_Employee);
        void createManager();
        bool check_num_Receptionist();
        void addEmployee();
        void editEmployee();
        void deleteEmployee(int ID);
        void displayEmployee();
        bool check_password(int ID);
        bool check_ID(int ID);
        void addShift(int ID, TypeShift shift);
         void addShift(int ID);
        bool check_Position(int ID, TypeJobPosition position);
};

class HotelManager{
    private:
        vector <Room> Database_Room;
        vector <Customer> Database_Customer;
        vector <Employee> Database_Employee;
        void createRoom();
        void bookRoom(int roomNumber);
        void checkIn(int roomNumber);
        void checkOut(int roomNumber);
        void displayCustomerSelection(CustomerManager menu);
        void displayEmployeeSelection(EmployeeManager emp_menu, CustomerManager cus_menu);
        void SelectionMenu(int selection, EmployeeManager emp_menu, CustomerManager cus_menu);
        void createManager(vector <Employee> Database_Employee);
    public:
        HotelManager();
        void displayAllRoom();
        void displayAvailableRoom();
};


#endif