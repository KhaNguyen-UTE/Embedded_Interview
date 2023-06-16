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

typedef struct {
    uint8_t day;
    uint8_t month;
    uint8_t year;
}typeDate;

typedef struct {
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
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
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LAUGGAGE_STAFF,
    GRADENER
}JobPosition;

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
        vector <BookingHistory> History;
    public:
        Customer (string CusNAme, string CusAdddress, string Cusphone, string CusPassword);

        string getName();
        void setName(string name);

        string getPHONE_NUMBER();
        void setPHONE_NUMBER(string phone_number);

        string getADDRESS();
        void setADDRESS(string address);

        string getPASSWORD();
        void setPASSWORD(string password);
        
        void addBokking(BookingHistory var);
        void displayBooking();

        int getID();
};

class CustomerManager : public Check{
    private:
        
        bool check_password(int ID);
        bool check_ID(int ID);
        vector <Customer>  *Database_Customer;
    public:
        
        CustomerManager(vector <Customer> &Database_Customer);
        void addCustomer();
        void editCustomer();
        void deleteCustomer(int ID);
        void listCustomer();
};

class Employee{
    private:
        int ID; 
        string NAME;
        string PHONENUMBER;
        string PASSWORD;
        JobPosition POSITION;
        vector <BookingHistory> SCHEDULE;
    public:
        Employee(string name, string phone, string password, JobPosition position);

        string getName();
        void setName(string name);

        string getPHONE_NUMBER();
        void setPHONE_NUMBER(string phone_number);

        JobPosition getPOSITION();
        void setPOSITION(JobPosition position);

        string getPASSWORD();
        void setPASSWORD(string password);
        
        void addSchedule(BookingHistory var);
        void displaySchedule();

        int getID();
};

class EmployeeManager : public Check{
    private:
        vector <Employee> Database_Employee;
        bool check_password(int ID);
        bool check_ID(int ID);
        
    public:
        void transfer_position(int value, JobPosition *jobPosition);
        void addEmployee();
        void editEmployee();
        void deleteEmployee(int ID);
        void displayEmployee();
};

class HotelManager{
    private:
        vector <Room> Database_Room;
        vector <Customer> Database_Customer;
        void createRoom();
        void bookRoom(uint8_t roomNumber);
        void checkIn(uint8_t roomNumber);
        void checkOut(uint8_t roomNumber);
        void displayCustomerSelection(CustomerManager menu);
    public:
        HotelManager();
        void displayAllRoom();
        void displayAvailableRoom();
};


#endif