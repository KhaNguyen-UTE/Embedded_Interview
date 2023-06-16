#include <Hotel.hpp>

Employee::Employee(string name, string phone, string password, JobPosition position){
    static int id = 1000;
    this->ID = id;
    this->NAME = name;
    this->PHONENUMBER = phone;
    this->POSITION = position;
    this->PASSWORD = password;
    id++;
}

string Employee::getName(){
     return Employee::NAME;
}

void Employee::setName(string name){
    this->NAME = name;
}

string Employee::getPHONE_NUMBER(){
     return Employee::PHONENUMBER;
}

void Employee::setPHONE_NUMBER(string phone_number){
    this->PHONENUMBER = phone_number;
}

string Employee::getPASSWORD(){
    return Employee::PASSWORD;
}

void Employee::setPASSWORD(string password){
    this->PASSWORD = password;
}

JobPosition Employee::getPOSITION(){
    return this->POSITION;
}

void Employee::setPOSITION(JobPosition position){
    this->POSITION = position;
}

void Employee::addSchedule(BookingHistory var){
    SCHEDULE.push_back(var);
}

void displaySchedule(){

}

int Employee::getID(){
    return Employee::ID;
}

bool EmployeeManager::check_password(int ID){
    string password;
    INPUT_DATA_NO_SPACE("Enter password: ", password);
    for (auto temp : Database_Employee){
        if (ID == temp.getID()){
            if (password == temp.getPASSWORD()) return true;
        }
    }
    return false;
}

bool EmployeeManager::check_ID(int ID){
    for( auto temp : Database_Employee){
        if (ID == temp.getID()) return true;
    }
    return false;
}


void EmployeeManager::transfer_position(int value, JobPosition *jobPosition){
    switch (value){
        case 1:
            *jobPosition = JANITOR;
            break;
        case 2:
            *jobPosition = RECEPTIONIST;
            break;
        case 3:
            *jobPosition = LAUNDRY_STAFF;
            break;
        case 4:
            *jobPosition = LAUGGAGE_STAFF;
            break;
        case 5:
            *jobPosition = GRADENER;
            break;
    }
}


void EmployeeManager::addEmployee(){
    string name;
    string phone_number;
    int s_jobPosition;
    string password;
    JobPosition jobPosition;

    check_input(&name, NAME);
    check_input(&phone_number, PHONE_NUMBER);
    check_input(&s_jobPosition, POSITION);
    transfer_position(s_jobPosition, &jobPosition);
    INPUT_DATA_NO_SPACE("Enter password: ", password);
    cin.ignore(100, '\n');

    Employee add(name,phone_number, password, jobPosition);
    Database_Employee.push_back(add);

}

void EmployeeManager::deleteEmployee(int ID){
    bool status_delete = false;
    vector<Employee>::iterator vector_index = Database_Employee.begin();
    for (auto temp : Database_Employee){
        if (temp.getID() == ID){
            Database_Employee.erase(vector_index);
            cout <<"--Already delete--" <<endl;
            status_delete = true;
        }
        vector_index++;
    }
    if (status_delete == false) cout <<"--Don't have ID Employee in Database--" <<endl;
}


void EmployeeManager::editEmployee(){
    bool edit_status = false;
    int id;
    int vector_index = 0;
    INPUT_DATA_NO_SPACE("Enter ID: ", id);
    for (auto temp : Database_Employee){
        if (id == temp.getID()){
            int error_count = 0;
            while (edit_status == false){
            if (check_password(id) == true ) {
                int s_position;
                string name;
                string phone_number;
                string password;
                JobPosition jobPosition;
            selection_menu:
                cout <<"What do you want to edit ?" <<endl
                    <<"    1. Name"                <<endl
                    <<"    2. Job Position"        <<endl
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
                    check_input(&s_position, POSITION);
                    transfer_position(s_position, &jobPosition);
                    temp.setPOSITION(jobPosition);
                    break;
                case 3:
                    cin.ignore(100, '\n');
                    INPUT_DATA_NO_SPACE("Enter password: ", password);
                    temp.setPASSWORD(password);
                    break;
                case 4:
                    cin.ignore(100, '\n');
                    check_input(&phone_number, PHONE_NUMBER);
                    temp.setPHONE_NUMBER(phone_number);
                    break;
                case 5:
                    break;
                }
                Database_Employee[vector_index] = temp;
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

void EmployeeManager::displayEmployee(){
    cout <<"                              DATA Employee                              "     <<endl  
         <<"+-------------------------------------------------------------------------+"    <<endl
         <<"|  ID  |        Name       |     Phone number     |      Job Position     |"    <<endl
         <<"|-------------------------------------------------------------------------|"    <<endl;
    for (auto temp : Database_Employee){
        string position;
        switch (temp.getPOSITION()){
        case JANITOR:
            position = "JANITOR";
            break;
        case RECEPTIONIST:
            position = "RECEPTIONIST";
            break;
        case LAUNDRY_STAFF:
            position ="LAUNDRY_STAFF";
            break;
        case LAUGGAGE_STAFF:
            position ="LAUGGAGE_STAFF";
            break;
        case GRADENER:
            position ="GRADENER";
            break;
        }
        printf("| %-5d|  %-17s|  %-20s|  %-21s|\n", temp.getID(),temp.getName().c_str(), temp.getPHONE_NUMBER().c_str(), position.c_str());
    }
    cout <<"+-------------------------------------------------------------------------+"    <<endl;
}

