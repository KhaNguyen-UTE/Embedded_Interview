#include <Hotel.hpp>

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

class Customer{
    private:
        uint8_t ID;    
        string NAME;
        string PHONE_NUMBER;
        string ADDRESS;
        string PASSWORD;
        vector <BookingHistory> History;
    public:
        Customer (string CusNAme, string CusAdddress, string Cusphone);

        string getName();
        void setName(string name);

        string getPHONE_NUMBER();
        void setPHONE_NUMBER(string phone_number);

        string getADDRESS();
        void setADDRESS(string address);
        
        void addBokking(BookingHistory var);
        void displayBooking();
};

class CustomerManager{
    private:
        vector <Customer> Database_Customer;
    public:
        void addCustomer();
        void editCustomer();
        void deleteCustomer();
        void displayCustomer();
};

Customer::Customer (string CusNAme, string CusAdddress, string Cusphone){
    static uint8_t id = 100;
    this->ID = id;
    this->NAME = CusNAme;
    this->ADDRESS = CusAdddress;
    this->PHONE_NUMBER = Cusphone;
    id++;
}

string Customer::getName(){
     return Customer::NAME;
}

void Customer::setName(string name){
    this->NAME = name;
}

string Customer::getPHONE_NUMBER(){
     return Customer::PHONE_NUMBER;
}

void Customer::setPHONE_NUMBER(string phone_number){
    this->PHONE_NUMBER = phone_number;
}

string Customer::getADDRESS(){
     return Customer::ADDRESS;
}

void Customer::setADDRESS(string address){
    this->ADDRESS = address;
}

void Customer::addBokking(BookingHistory var){
    History.push_back(var);
}

/*
void Customer::displayBooking(){
    for (auto history : History){
        cout <<"" ;
    }
}

*/

void CustomerManager::addCustomer(){
    //uint8_t id;    
    string name;
    string phone_number;
    string address;
    string password;
    vector <BookingHistory> History;

    //INPUT_DATA_HAVE_SPACE(" Enter Name: ", name);
}