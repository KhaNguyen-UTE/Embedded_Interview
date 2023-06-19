/*
* File Name: Employee.cpp
* Author: Nguyen Tran Minh Kha
* Date: 15/06/2023
* Description: The program is used to setup the function for Class Employee
*/

#include <Hotel.hpp>

/*
* Function: Employee()
* Description: get Employee data
* Input:
*   name - string
*   phone - string
*   password - string
*   position - TypeJobPosition
* Output:
*   None
*/
Employee::Employee(string name, string phone, string password, TypeJobPosition position){
    static int id = 100;
    this->ID = id;
    this->NAME = name;
    this->PHONENUMBER = phone;
    this->POSITION = position;
    this->PASSWORD = password;
    id++;
}

/*
* Function: getName()
* Description: get name for Employee
* Input:
*   none
* Output:
*   return name in type of string
*/
string Employee::getName(){
     return Employee::NAME;
}

/*
* Function: setName()
* Description: set name for Employee
* Input:
*   NAME - string
* Output:
*   none
*/
void Employee::setName(string name){
    this->NAME = name;
}

/*
* Function: getPHONE_NUMBER()
* Description: get phonenumber of Employee
* Input:
*   none
* Output:
*   return phone number in type of string
*/
string Employee::getPHONE_NUMBER(){
     return Employee::PHONENUMBER;
}

/*
* Function: setPHONE_NUMBER()
* Description: set phone number for Employee
* Input:
*   phone_number - string
* Output:
*   none
*/
void Employee::setPHONE_NUMBER(string phone_number){
    this->PHONENUMBER = phone_number;
}

/*
* Function: getPASSWORD()
* Description: get password of Employee
* Input:
*   none
* Output:
*   return password in type of string
*/
string Employee::getPASSWORD(){
    return Employee::PASSWORD;
}

/*
* Function: setPASSWORD()
* Description: set password for Employee
* Input:
*   password - string
* Output:
*   none
*/
void Employee::setPASSWORD(string password){
    this->PASSWORD = password;
}

/*
* Function: getPOSITION()
* Description: get position for Employee
* Input:
*   none
* Output:
*   return the position in type of TypeJobPosition
*/
TypeJobPosition Employee::getPOSITION(){
    return this->POSITION;
}

/*
* Function: setPOSITION()
* Description: set position for Employee
* Input:
*   position - TypeJobPosition
* Output:
*   none
*/
void Employee::setPOSITION(TypeJobPosition position){
    this->POSITION = position;
}

/*
* Function: addSchedule()
* Description: set position for Employee
* Input:
*   shift : TypeShift
* Output:
*   none
*/
void Employee::addSchedule(TypeShift shift){
    SHIFT.push_back(shift);
}

/*
* Function: getID()
* Description: get ID of Employee
* Input:
*   none
* Output:
*   return ID in type of int
*/
int Employee::getID(){
    return Employee::ID;
}

/*
* Function: check_password()
* Description: use for checking input password
* Input:
*   ID : int
* Output:
*   return true if right password or return false
*/
bool EmployeeManager::check_password(int ID){
    string password;
    if (ID == 100){
        INPUT_DATA_NO_SPACE("Enter your Manager password: ", password);
    }
    else{
        INPUT_DATA_NO_SPACE("Enter your Employee password: ", password);
    }
    
    for (auto &temp : *Database_Employee){
        if (ID == temp.getID()){
            if (password == temp.getPASSWORD()) return true;
        }
    }
    return false;
}

/*
* Function: check_ID()
* Description: use for checking employee ID
* Input:
*   ID : int
* Output:
*   return true if have ID in Database or return false
*/
bool EmployeeManager::check_ID(int ID){
    for( auto &temp : *Database_Employee){
        if (ID == temp.getID()) return true;
    }
    return false;
}

/*
* Function: check_Position()
* Description: use for checking employee position
* Input:
*   ID : int
*   position : TypeJobPosition
* Output:
*   return true if have right input in Database or return false
*/
bool EmployeeManager::check_Position(int ID, TypeJobPosition position){
    for(auto &temp : *Database_Employee){
        if( ID == temp.getID()){
            if (position == temp.getPOSITION()) return true;
        }
    }
    return false;
}

/*
* Function: addShift()
* Description: add Shift into Database of Shift
* Input:
*   id : int
* Output:
*   print the result and function
*/
void EmployeeManager::addShift(int ID){
    int shift;
    chose:
    cout <<"Choose shifft "      <<endl
         <<"      1. Morning"    <<endl
         <<"      2. Afternoon"  <<endl
         <<"      3. Night"      <<endl
         <<"      4. All day"    <<endl;
    INPUT_DATA_NO_SPACE("Your choice: ", shift);
    if (shift <= 0 || shift > 4 || cin.fail() == true){        // If input type is wrong, then require enter data again
        cin.clear();
        cin.ignore(100, '\n');
        cout <<endl << "-- Please enter the right option  --" << endl;
        goto chose;
    }

    TypeShift emp_shift;

    switch (shift)
    {
    case 1:
        emp_shift = DAY_SHIFT;
        break;
    case 2:
        emp_shift = AFTERNOON_SHIFT;
        break;
    case 3:
        emp_shift = NIGHT_SHIFT;
        break;
    case 4:
        emp_shift = ALL_DAY;
        break;  
    }
    
    for (auto &temp : *Database_Employee){
        if (ID == temp.getID()){
            temp.SHIFT.push_back(emp_shift);
        }
    }
}

/*
* Function: addShift()
* Description: add Shift into Database of Shift
* Input:
*   id : int
*   shift : TypeShift 
* Output:
*   print the result and function
*/
void EmployeeManager::addShift(int ID, TypeShift shift){
    for (auto &temp : *Database_Employee){
        if (ID == temp.getID()){
            temp.SHIFT.push_back(shift);
        }
    }
}

/*
* Function: createManager()
* Description: create initial Manager then push into Database of Employee
* Input:
*   none
* Output:
*   none
*/
void EmployeeManager::createManager(){
    string name = "Kha Nguyen";
    string password = "admin";
    string phone = "0123456789";
    TypeJobPosition position = MANAGER;
    TypeShift shift = ALL_DAY;
    Employee create(name,phone,password,position);
    
    (*Database_Employee).push_back(create);
    addShift(100, shift);
}

/*
* Function: transfer_position()
* Description: use to get the data off position in type of TypeJobPosition
* Input:
*   value : int
*   *TypeJobPosition : TypeJobPosition
* Output:
*   none
*/
void EmployeeManager::transfer_position(int value, TypeJobPosition *TypeJobPosition){
    switch (value){
        case 1:
            *TypeJobPosition = JANITOR;
            break;
        case 2:
            *TypeJobPosition = RECEPTIONIST;
            break;
        case 3:
            *TypeJobPosition = LAUNDRY_STAFF;
            break;
        case 4:
            *TypeJobPosition = LAUGGAGE_STAFF;
            break;
        case 5:
            *TypeJobPosition = GRADENER;
            break;
        case 6:
            *TypeJobPosition = MANAGER;
            break;
    }
}

/*
* Function: Constructor EmployeeManager
* Description: get data
* Input:
*   &Database_Employee - vector <Employee>
* Output:
*   none
*/
EmployeeManager::EmployeeManager(vector <Employee> &Database_Employee){
    this->Database_Employee = &Database_Employee;
}

/*
* Function: addEmployee()
* Description: add Employee into Database of Employee
* Input:
*   id : int
* Output:
*   print the result and function
*/
void EmployeeManager::addEmployee(){
    string name;
    string phone_number;
    int s_jobPosition;
    string password;
    TypeJobPosition jobPosition;
    cin.ignore(100, '\n');
    check_input(&name, NAME);
    check_input(&phone_number, PHONE_NUMBER);
    check_input(&s_jobPosition, POSITION);
    transfer_position(s_jobPosition, &jobPosition);
    INPUT_DATA_NO_SPACE("Enter password: ", password);
    cin.ignore(100, '\n');
    Employee add(name,phone_number, password, jobPosition);
    (*Database_Employee).push_back(add);
    cout <<"-- Successfulled Add Employee --" <<endl;

}

/*
* Function: check_num_Receptionist()
* Description: check the number of Receptionist ( if the number <1 => Do not allow to enter Receptionist Menu)
* Input:
*   None
* Output:
*   true if have receptionist in Database_Employee, false if do not have
*/
bool EmployeeManager::check_num_Receptionist(){
    for (auto &temp : *Database_Employee){
        if (temp.getPOSITION() == RECEPTIONIST) return true;
    }
    return false;
}

/*
* Function: check_num_Manager()
* Description: check the number of Manager ( if the number < 2 => Do not allow to delete the infor of Manager)
* Input:
*   None
* Output:
*   true if have over 2 Manager in Database_Employee, false if reserver
*/
bool EmployeeManager::check_num_Manager(){
    int count = 0;
    for (auto &temp : *Database_Employee){
        if (temp.getPOSITION() == MANAGER) count++;
    }
    if(count > 1) return true;
    else return false;
}

/*
* Function: deleteEmployee()
* Description: delete Employee in Database of Employee
* Input:
*   ID : int
* Output:
*   print the result
*/
void EmployeeManager::deleteEmployee(int ID){
    bool status_delete = false;
    vector<Employee>::iterator vector_index = (*Database_Employee).begin();
    for (auto &temp : *Database_Employee){
        if (temp.getID() == ID){
            if( temp.getPOSITION() == MANAGER && check_num_Manager() == false){
                status_delete = true;
                cout <<"-- Please ASSIGN new MANAGER before delete --" <<endl;
                break;
            }
            (*Database_Employee).erase(vector_index);
            cout <<"--Already delete--" <<endl;
            status_delete = true;
        }
        vector_index++;
    }
    if (status_delete == false) cout <<"--Don't have ID Employee in Database--" <<endl;
}

/*
* Function: editEmployee()
* Description: update Employee into Database of Employee
* Input:
*   none
* Output:
*   print the result
*/
void EmployeeManager::editEmployee(){
    bool edit_status = false;
    int id;
    int vector_index = 0;
    INPUT_DATA_NO_SPACE("Enter ID: ", id);
    for (auto &temp : *Database_Employee){
        if (id == temp.getID()){
            
            while (edit_status == false){
            
                int s_position;
                string name;
                string phone_number;
                string password;
                TypeJobPosition jobPosition;
            
                cout <<"What do you want to edit ?" <<endl
                    <<"    1. Name"                <<endl
                    <<"    2. Job Position"        <<endl
                    <<"    3. Password"            <<endl
                    <<"    4. Phone Number"        <<endl
                    <<"    5. Back to Menu"        <<endl;
                int edit_selection;
                INPUT_DATA_NO_SPACE("Your selection: ", edit_selection);
                
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
                    INPUT_DATA_NO_SPACE("Enter new Employee password: ", password);
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
                (*Database_Employee)[vector_index] = temp;
                cout <<"--Already edited--" <<endl;
                edit_status = true;
            }
        }
        vector_index++;
    }
    if(edit_status == false) cout <<"--Don't have Employee info in Database--" <<endl;
}

/*
* Function: :displayEmployee()
* Description: show the information of All Cusstomer except for PASSWORD
* Input:
*   None
* Output:
*   print the result
*/
void EmployeeManager::displayEmployee(){
    cout <<"                                       DATA EMPLOYEE"                                               <<endl  
         <<"+---------------------------------------------------------------------------------------------+"    <<endl
         <<"|  ID  |        Name       |     Phone number     |      Job Position     |        Shift      |"    <<endl
         <<"|=============================================================================================|"    <<endl;
    int length = (*Database_Employee).size();
    for (auto &temp : *Database_Employee){
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
        case MANAGER:
            position ="MANAGER";
            break;
        }
        printf("| %-5d|  %-17s|  %-20s|  %-21s|", temp.getID(),temp.getName().c_str(), temp.getPHONE_NUMBER().c_str(), position.c_str());

        bool begin = true;
        for (auto shift : temp.SHIFT){
            string s_shift;
            switch(shift){
                case DAY_SHIFT: 
                    s_shift = "DAY_SHIFT      ";
                    break;
                case AFTERNOON_SHIFT:
                    s_shift = "AFTERNOON_SHIFT";
                    break;
                case NIGHT_SHIFT:
                    s_shift = "NIGHT_SHIFT    ";
                    break;
                case ALL_DAY:
                    s_shift = "ALL_DAY        ";
                    break;
            }
            if (begin == true) begin = false;
            else    printf("|      |                  |                      |                       |");
            cout <<"  " <<s_shift <<"  |" <<endl;
        }
        length--;
        if(temp.SHIFT.size() == 0) cout <<"                   |"<<endl;
        if(length != 0)
        cout <<"|---------------------------------------------------------------------------------------------|"    <<endl;
    }
        cout <<"+---------------------------------------------------------------------------------------------+"    <<endl;
}

