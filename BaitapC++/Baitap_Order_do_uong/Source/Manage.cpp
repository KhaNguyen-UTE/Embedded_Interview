/*
* File Name: Manage.cpp
* Author: Nguyen Tran Minh Kha
* Date: 04/06/2023
* Description: The program is used to setup for Class Manage
*/

#include "Beverage.hpp"

/*
* Function: Constructor Manage
* Description: get data
* Input:
*   &Database_Beverage - vector <ListBeverage>
*   &numTable - int
* Output:
*   none
*/
Manage::Manage(vector <ListBeverage> &Database_Beverage, int &numtable){
    this ->Database_Beverage = &Database_Beverage;
    this ->numTable = &numtable;
}

/*
* Function: displayMenu()
* Description: print the Menu of Manager
* Input:
*   none
* Output:
*   print the result
*/
void Manage::displayMenu(){
    int status;
    while (status != 6){
        cout<<" +------------------------------+" <<endl
            <<" |            MANAGER           |" <<endl
            <<" | 1. Add beverage to stock     |" <<endl
            <<" | 2. Update beverage in stock  |" <<endl
            <<" | 3. Delete beverage in stock  |" <<endl
            <<" | 4. List of beverage in stock |" <<endl
            <<" | 5. Enter number of table     |" <<endl
            <<" | 6. Back to Main Menu         |" <<endl
            <<" +------------------------------+" <<endl;
        INPUT_DATA ("Enter your selection: ", status);

        if (status < 1 || status > 6 || cin.fail() == true){
            cin.clear();
            cin.ignore(100, '\n');
            cout <<"--Please enter the selection in Manager menu--" <<endl;
            continue;;
        }

        switch (status){
            case 1: 
                addBeverage();
                break;
            case 2:
                updateBeverage();
                break;
            case 3:
                deleteBeverage();
                break;
            case 4:
                Manage::listBeverage();
                break;
            case 5: 
                numberOfTable();
                break;
        }
    }
}

/*
* Function: numberOfTable()
* Description: enter number of Table
* Input:
*   none
* Output:
*   none
*/
void Manage::numberOfTable(){
    INPUT_DATA("Enter the number of table: ", *numTable);
}

/*
* Function: getNumTable()
* Description: get number of Table
* Input:
*   none
* Output:
*   return the number of Table
*/
int Manage::getNumTable(){
    return *numTable;
}

/*
* Function: addBeverage()
* Description: add beverage into Database of Beverage
* Input:
*   none
* Output:
*   print the result
*/
void Manage::addBeverage(){
    string Name;
    int i_Quantity;
    float f_Price;
    cout <<"Add beverage to the stock" <<endl
         <<"-------------------------" <<endl;
    
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Name: ";
    getline(cin, Name );

    importQuantity:
    INPUT_DATA ("Quantity: ", i_Quantity);
    if (i_Quantity <= 0 || cin.fail() == true){
        cin.clear();
        cin.ignore(100, '\n');
        cout <<"--Please enter the right quantity--" <<endl;
        goto importQuantity;
    }
    
    importPrice:
    INPUT_DATA ("Price: ", f_Price);
    if (f_Price <= 0 || cin.fail() ==true){
        cin.clear();
        cin.ignore(100, '\n');
        cout <<"--Please enter the right price--" <<endl;
        goto importPrice;
    }
    
    ListBeverage beverage(Name, i_Quantity, f_Price);
    Database_Beverage->push_back(beverage);
    cout <<"--Added successfully--" <<endl;
}

/*
* Function: updateBeverage()
* Description: update beverage into Database of Beverage
* Input:
*   none
* Output:
*   print the result
*/
void Manage::updateBeverage(){
    int update_selection;
    bool status = false;
    int vector_index = 0;
    string Name;
    int i_Quantity;
    float f_Price;
    INPUT_DATA("Enter name of beverage: ", Name);
    for (ListBeverage &temp : *Database_Beverage){
        if (Name == temp.getName()){
                cout <<" Enter your selection:"          <<endl
                     <<"         1. Update Name"         <<endl
                     <<"         2. Update Quantity"     <<endl
                     <<"         3. Update Price"        <<endl
                     <<" Selection:...";
                cin >> update_selection;
                status = true;
                switch (update_selection){
                        case 1: 
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << " Name: ";
                                getline(cin, Name );
                                temp.setName(Name);
                                break;
                        case 2: 
                                importQuantity:
                                INPUT_DATA (" Quantity: ", i_Quantity);
                                if (i_Quantity <= 0 || cin.fail() == true){
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                    cout <<"--Please enter the right quantity--" <<endl;
                                    goto importQuantity;                         
                                }
                                temp.setQuantity(i_Quantity);  
                                break;
                        case 3: 
                                importPrice:
                                INPUT_DATA (" Price: ", f_Price);
                                if (f_Price <= 0 || cin.fail() ==true){
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                    cout <<"--Please enter the right price--" <<endl;
                                    goto importPrice;
                                }
                                temp.setPrice(f_Price);
                                break;
                } 
                (*Database_Beverage)[vector_index] = temp;    
        }
        vector_index++;
    }
    if (status == false) cout << "--DON'T HAVE BEVERAGE IN STOCK--" << endl;
}

/*
* Function: deleteBeverage()
* Description: delete beverage in Database of Beverage
* Input:
*   none
* Output:
*   print the result
*/
void Manage::deleteBeverage(){
    string Name;
    bool status = false;
    vector<ListBeverage>::iterator vector_index = (*Database_Beverage).begin();
    INPUT_DATA("Enter name of beverage: ", Name);
    for (ListBeverage &temp : *Database_Beverage){
        if (Name == temp.getName()){
            (*Database_Beverage).erase(vector_index);
            status = true;
            cout <<"SUCCESSFULLY DELETED" <<endl;
        }
        vector_index++;
    }
    if (status == false) cout << "--DON'T HAVE BEVERAGE IN STOCK--" << endl;
}

/*
* Function: listBeverage()
* Description: show beverage data in Database of Beverage
* Input:
*   none
* Output:
*   print the result
*/
void Manage::listBeverage(){
    cout <<"                 BEVERAGE IN STOCK"                  <<endl
         <<"+-------------------------------------------------+" <<endl
         <<"|  ID  |      Name      |  Quantity |    Price    |" <<endl
         <<"|-------------------------------------------------|" <<endl;
    for (auto temp : *Database_Beverage){
        printf("| %-5d| %-15s| %-10d| %-12.2f|\n", temp.getID(), temp.getName().c_str() ,temp.getQuantity(), temp.getPrice());
    }
    cout <<"+-------------------------------------------------+" <<endl;
}

/*
* Function: getDatabase_Beverage()
* Description: get beverage in Database of Beverage
* Input:
*   none
* Output:
*   return Database in type of vector <ListBeverage>
*/
vector <ListBeverage> Manage::getDatabase_Beverage(){
       return *Database_Beverage;
    }

