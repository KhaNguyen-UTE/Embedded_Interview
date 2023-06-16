#include "Hotel.hpp"


Customer::Customer (string CusNAme, string CusAdddress, string Cusphone, string CusPassword){
    static int id = 100;
    this->ID = id;
    this->NAME = CusNAme;
    this->ADDRESS = CusAdddress;
    this->PHONE_NUMBER = Cusphone;
    this->PASSWORD = CusPassword;
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

string Customer::getPASSWORD(){
    return Customer::PASSWORD;
}

void Customer::setPASSWORD(string password){
    this->PASSWORD = password;
}

int Customer::getID(){
    return Customer::ID;
}

void Customer::addBokking(BookingHistory var){
    History.push_back(var);
}

bool CustomerManager::check_password(int ID){
    string password;
    INPUT_DATA_NO_SPACE("Enter password: ", password);
    for (auto &temp : *Database_Customer){
        if (ID == temp.getID()){
            if (password == temp.getPASSWORD()) return true;
        }
    }
    return false;
}

bool CustomerManager::check_ID(int ID){
    for( auto &temp : *Database_Customer){
        if (ID == temp.getID()) return true;
    }
    return false;
}

void Customer::displayBooking(){
    for (auto history : History){
        cout <<history.date.day ;
    }
}

CustomerManager::CustomerManager(vector <Customer> &Database_Customer){
    this->Database_Customer = &Database_Customer;
}

void CustomerManager::addCustomer(){
    string name;
    string phone_number;
    string address;
    string password;
    cin.ignore(100, '\n');
    check_input(&name, NAME);
    check_input(&address, ADDRESS);
    check_input(&phone_number, PHONE_NUMBER);
    INPUT_DATA_NO_SPACE("Enter password: ", password);
    cin.ignore(100, '\n');
    Customer add(name, address,phone_number, password);
    Database_Customer->push_back(add);

}

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

void CustomerManager::editCustomer(){
    bool edit_status = false;
    int id;
    int vector_index = 0;
    INPUT_DATA_NO_SPACE("Enter ID: ", id);
    for (auto &temp : *Database_Customer){
        if (id == temp.getID()){
            int error_count = 0;
            while (edit_status == false){
            if (check_password(id) == true ) {

                string name;
                string phone_numeber;
                string address;
                string password;
            selection_menu:
                cout <<"What do you want to edit ?" <<endl
                    <<"    1. Name"                <<endl
                    <<"    2. Address"             <<endl
                    <<"    3. Password"            <<endl
                    <<"    4. Phone Number"        <<endl
                    <<"    5. Back to Menu"        <<endl;
                int edit_selection;
                INPUT_DATA_NO_SPACE("Your selection: ", edit_selection);
                if ( edit_selection < 1 || edit_selection > 5) goto selection_menu;
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
                    INPUT_DATA_NO_SPACE("Enter password: ", password);
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
            else{
                error_count++;
                cout <<"-- Wrong password (" <<error_count <<"/3) --" <<endl;
                if (error_count <=3){
                    cout <<"Re-enter password: " <<endl;
                }
                else{
                    cout<<"--YOU HAVE ENTERED THE WRONG PASSWORD TOO MANY TIMES--" <<endl;
                    edit_status = true;
                }
            }
            }
        }
        vector_index++;
    }
    if(edit_status == false) cout <<"--Don't have info in Database--" <<endl;
}

void CustomerManager::listCustomer(){
    cout <<"                              DATA CUSTOMER                              "     <<endl  
         <<"+------------------------------------------------------------------------+"    <<endl
         <<"|  ID  |        Name      |     Phone number     |        Address        |"    <<endl
         <<"|------------------------------------------------------------------------|"    <<endl;
    for (auto &temp : *Database_Customer){
        
        printf("|  %-4d|  %-16s|  %-20s|  %-21s|\n", temp.getID(),temp.getName().c_str(), temp.getPHONE_NUMBER().c_str(), temp.getADDRESS().c_str());
    }
    cout <<"+------------------------------------------------------------------------+"    <<endl;
}

    
