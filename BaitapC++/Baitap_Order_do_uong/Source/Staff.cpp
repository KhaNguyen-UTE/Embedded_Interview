/*
* File Name: Staff.cpp
* Author: Nguyen Tran Minh Kha
* Date: 04/06/2023
* Description: The program is used to setup for Class Staff
*/

#include "Beverage.hpp"

/*
* Function: Constructor Staff
* Description: get data
* Input:
*   &Database_Beverage - vector <ListBeverage>
*   &numTable - int
*   &Database_Oder - vector <OrderBeverage>
* Output:
*   None
*/
Staff::Staff(vector <ListBeverage> &Database_Beverage, int &numTable,vector <OrderBeverage> &Database_Oder){
    this->Database_Beverage = &Database_Beverage;
    this->numTable = &numTable;
    this->Database_Oder = &Database_Oder;
}

/*
* Function: checkTable()
* Description: set status for Table
* Input:
*   Table_ID - int
* Output:
*   none
*/
void Staff::checkTable(int Table_ID){
    for (int i = Table_ID; i <= *numTable; i++){
        Table tb;
        tb.NUM_TABLE = i;
        tb.TABLE_STATUS = false;
        Database_Table.push_back(tb);
    }
}

/*
* Function: displayStaffMenu()
* Description: show the Staff menu
* Input:
*   none
* Output:
*   print the Menu
*/
 void Staff::displayStaffMenu(){
    static bool start_status = false;
    static int fixTableID;
    if(start_status == false){
        Database_Table.clear();
        checkTable(1);
        fixTableID = *numTable;
        start_status = true;
    }

    if(fixTableID < * numTable){
        fixTableID++;
        checkTable(fixTableID);
        fixTableID = *numTable;
    }
    else if(fixTableID > *numTable){
        for (int i = 0; i < fixTableID - *numTable; i++) Database_Table.pop_back();
        fixTableID = *numTable;
    }

    int table_id;
    printf("+----------");
    for(auto table : Database_Table) printf("----");
    printf("+\n");
    printf("| Staff    ");
    for(auto table : Database_Table) printf("    ");
    printf("|\n");
    printf("|   Table ");
    for(auto table : Database_Table) printf("| %-2d", table.NUM_TABLE);
    printf(" |\n");
    printf("|   ------");
    for(auto table : Database_Table) printf("----");
    printf(" |\n");
    printf("|   Status");
    for(auto table : Database_Table){
        char tableStatus;
        if (table.TABLE_STATUS == false) tableStatus = 'O';
        else tableStatus = 'X';
        printf("| %-2c", tableStatus);
    }
    printf(" |\n");
    printf("+----------");
    for(auto table : Database_Table) printf("----");
    printf("+\n");

    INPUT_DATA("Enter your selection: ", table_id);
    if (table_id <= *numTable && table_id > 0)
    {
        createTable(table_id);
    }
    else{
        cout <<"--Please enter the right table in range of menu--" <<endl;
    }
}

/*
* Function: createTable()
* Description: show the Table menu and get function
* Input:
*   TABLE_ID - int
* Output:
*   print the result
*/
void Staff::createTable(int TABLE_ID){
    int orderSelection = 0;
    while(true){
    cout << "+--------------------------+" <<endl;
    printf( "| Table: %-17d |\n", TABLE_ID );
    cout << "|    1. Add beverage       |" <<endl 
         << "|    2. Update beverage    |" <<endl
         << "|    3. Delete beverage    |"<<endl
         << "|    4. List of order      |"<<endl
         << "|    5. Pay for beverage   |" <<endl
         << "+--------------------------+" <<endl;
    INPUT_DATA ("Enter your selection / 0 for back to Main Menu: ", orderSelection);
    if (orderSelection == 0 ) break;

    char create_status;
    do{
        switch (orderSelection){
            case 1: 
                STAFF_RUN_SELECTION("--DON'T HAVE BEVERAGE IN STOCK--",(*Database_Beverage).empty(),
                create_status, Staff::orderBeverage(TABLE_ID));
                break;
            case 2:
                STAFF_RUN_SELECTION("--TABLE HAVEN'T ORDER--",Database_Table[TABLE_ID-1].Database_Oder.empty(),
                create_status, Staff::updateBeverage(TABLE_ID));
                break;
            case 3:
                STAFF_RUN_SELECTION("--TABLE HAVEN'T ORDER--",Database_Table[TABLE_ID-1].Database_Oder.empty(),
                create_status,  Staff::deleteBeverage(TABLE_ID));
                break;
            case 4:
                STAFF_RUN_SELECTION("--TABLE HAVEN'T ORDER--",Database_Table[TABLE_ID-1].Database_Oder.empty(),
                create_status,  Staff::listBeverage(TABLE_ID));
                break;
            case 5:
                STAFF_RUN_SELECTION("--TABLE HAVEN'T ORDER--",Database_Table[TABLE_ID-1].Database_Oder.empty(),
                create_status,  Staff::payBeverage(TABLE_ID));
                break;         
        }
    }
    while(create_status == '1');
    }
}

/*
* Function: orderBeverage()
* Description: add beverage into Database of Table
* Input:
*   TABLE_ID - int
* Output:
*   print the result
*/
void Staff::orderBeverage(int TABLE_ID){
    OrderBeverage order;
    Database_Table[TABLE_ID - 1].TABLE_STATUS = true;
    
    cout <<"                 BEVERAGE IN STOCK"                  <<endl
         <<"+-------------------------------------------------+" <<endl
         <<"|  ID  |      Name      |  Quantity |    Price    |" <<endl
         <<"|-------------------------------------------------|" <<endl;
    for (auto temp : *Database_Beverage){
        printf("| %-5d| %-15s| %-10d| %-12.2f|\n", temp.getID(), temp.getName().c_str() ,temp.getQuantity(), temp.getPrice());
    }
    cout <<"+-------------------------------------------------+" <<endl;

    cout <<"                       ORDER"                        <<endl
         <<"+-------------------------------------------------+" <<endl;
    bool status = true;;
    while (status == true){
        INPUT_DATA("    Name of beverage: ", order.NAME);
        int vector_index = 0;
        for (auto temp : *Database_Beverage){
            if( order.NAME == temp.getName()){
                inputQuantity:
                    INPUT_DATA("    Quanity of beverage: ", order.QUANTITY);
                    if(order.QUANTITY > temp.getQuantity()){
                        cout <<"--Please choose the quantity available in stock--" <<endl;
                        goto inputQuantity;
                    }
                status = false;
                int remainQuantity = temp.getQuantity() - order.QUANTITY;
                (*Database_Beverage)[vector_index].setQuantity(remainQuantity); 
                break;
            }
            vector_index++;
        }
        if(status ==true) cout <<"--Please choose beverage available in stock--" <<endl;
    }
    Database_Table[TABLE_ID-1].Database_Oder.push_back(order);
}

/*
* Function: updateBeverage()
* Description: update beverage in Database of Table
* Input:
*   TABLE_ID - int
* Output:
*   print the result
*/
void Staff::updateBeverage(int TABLE_ID){
    OrderBeverage order;
    bool update_status =false;
    int vector_index = 0;
    int remainQuantity;
    listBeverage(TABLE_ID);
    INPUT_DATA("    Name of beverage: ", order.NAME);
    for(auto temp : Database_Table[TABLE_ID -1].Database_Oder){
        if(order.NAME == temp.NAME){
            update_status = true;
            remainQuantity = temp.QUANTITY;
            inputQuantity:
            INPUT_DATA("    Quanity of beverage: ", order.QUANTITY);
            for (auto available : *Database_Beverage){
                if(available.getName() == order.NAME)
                if(order.QUANTITY > available.getQuantity()){
                    cout <<"--Please choose the quantity available in stock--" <<endl
                         <<"  AVAILABLE: " <<available.getQuantity()           <<endl;
                    goto inputQuantity;
                }
            }
            Database_Table[TABLE_ID -1].Database_Oder[vector_index] = order;
        }
        vector_index++;
    }
    vector_index = 0;
    for(auto remain : *Database_Beverage){
        if(remain.getName() == order.NAME){
            remainQuantity = remainQuantity - order.QUANTITY + remain.getQuantity();
            (*Database_Beverage)[vector_index].setQuantity(remainQuantity); 
        }
        vector_index++;
    }
    if(update_status == false) cout <<"--HAVEN'T ORDERED THIS YET--" <<endl;
}

/*
* Function: deleteBeverage()
* Description: delete beverage in Database of Table
* Input:
*   TABLE_ID - int
* Output:
*   print the result
*/
void Staff::deleteBeverage(int TABLE_ID){
    OrderBeverage order;
    cout <<" -DELETE- " <<endl; 
    INPUT_DATA("    Name of beverage: ", order.NAME);
    bool delete_status = false;
    vector <OrderBeverage> :: iterator vector_index = Database_Table[TABLE_ID - 1].Database_Oder.begin();
    for( auto temp : Database_Table[TABLE_ID - 1].Database_Oder){
        if(order.NAME == temp.NAME){
            Database_Table[TABLE_ID - 1].Database_Oder.erase(vector_index);
            delete_status = true;
            cout <<"SUCCESSFULLY DELETED" <<endl;
        }
        vector_index++;
    }
    if(delete_status == false) cout <<"--Haven't ordered this yet--" <<endl;
}

/*
* Function: payBeverage()
* Description: calculate the price of beverage in Database of Table then deleted Table Data
* Input:
*   TABLE_ID - int
* Output:
*   print the result
*/
void Staff::payBeverage(int TABLE_ID){
    cout <<"+------------------------------------+" <<endl
         <<"|  Pay for table: ";
    printf ("%-18d |\n",TABLE_ID);
    float total_price = 0;
    for (auto temp : Database_Table[TABLE_ID - 1].Database_Oder)
        for(auto available : *Database_Beverage){
            if(temp.NAME == available.getName())
            total_price = total_price + available.getPrice() * (float)temp.QUANTITY;
        }
    cout <<"|  Total of bill: ";
    printf ("%-18.2f |\n",total_price);
    cout <<"+------------------------------------+" <<endl;
    Database_Table[TABLE_ID-1].Database_Oder.clear();
    Database_Table[TABLE_ID - 1].TABLE_STATUS = false;
}

/*
* Function: listBeverage()
* Description: print beverage ordered in Database of Table
* Input:
*   TABLE_ID - int
* Output:
*   print the result
*/
void Staff::listBeverage(int TABLE_ID){
    cout <<"                          ORDER TABLE: " <<TABLE_ID            <<endl
         <<"+-----------------------------------------------------------+" <<endl
         <<"|  ID  |      Name      |  Quantity |  Price  | Total Price |" <<endl
         <<"|-----------------------------------------------------------|" <<endl;
    for(auto temp : Database_Table[TABLE_ID -1].Database_Oder){
        uint8_t ID;
        float price;
        for(auto available : *Database_Beverage){
            if( available.getName() == temp.NAME){
                price = available.getPrice();
                ID = available.getID();
                printf("| %-5d| %-15s| %-10d| %-8.2f| %-12.2f|\n", ID, temp.NAME.c_str() ,temp.QUANTITY, price, (float)temp.QUANTITY * price);
            }
        }
    }
    cout <<"+-----------------------------------------------------------+" <<endl; 
}