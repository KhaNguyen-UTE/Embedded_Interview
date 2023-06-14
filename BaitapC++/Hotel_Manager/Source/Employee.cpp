#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef enum{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LAUGGAGE_STAFF,
    GRADENER
}JobPosition;

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
    typeDate Date;
    typeTime Time;
    TypeStatus Status;
}BookingHistory;

class Employee{
    private:
        string NAME;
        string PHONENUMBER;
        JobPosition POSITION;
        BookingHistory SCHEDULE;
    public:
        Employee(string name, string phone, JobPosition position, BookingHistory schedule);
};

class EmployeeManager{
    private:
        vector <Employee> Database_Employee;
    public:
        void addEmployee();
        void editEmployee();
        void deleteEmployee();
        void displayEmployee();
};