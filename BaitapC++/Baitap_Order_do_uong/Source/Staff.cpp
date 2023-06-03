#include "Beverage.hpp"

Staff::Staff(vector <ListBeverage> &Database_Beverage, int &numTable){
    this->Database_Beverage = &Database_Beverage;
    this->numTable = &numTable;
}
void Staff::resetTable(){
    Database_Table.clear();
    for (int i = 1; i <= *numTable; i++){
        Table tb;
        tb.NUM_TABLE = i;
        tb.TABLE_STATUS = false;
        Database_Table.push_back(tb);
    }
}

 void Staff::displayStaffMenu(){

    uint8_t table_id;
    printf("+----------");
    for(auto table :Database_Table) printf("----");
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
    for(auto table : Database_Table) printf("| %-2d", table.TABLE_STATUS);
    printf(" |\n");
    printf("+----------");
    for(auto table : Database_Table) printf("----");
    printf("+\n");

    INPUT_DATA("Enter your selection: ", table_id);
    if (table_id < *numTable && table_id > 0)
    {
        createTable(table_id);
    }
    else{
        cout <<"--Please enter the right table in range of menu--" <<endl;
    }
}

void Staff::createTable(uint8_t TABLE_ID){
    uint8_t orderSelection;
    Database_Table[TABLE_ID -1].TABLE_STATUS = true;
    cout << "+--------------------------+" <<endl;
    printf( "| Table: %-7d |\n", TABLE_ID );
    cout << "|    1. Add beverage       |" <<endl 
         << "|    2. Update beverage    |" <<endl
         << "|    3. Delete beverage    |"<<endl
         << "|    4. List of order      |"<<endl
         << "|    5. Pay for beverage   |" <<endl
         << "+--------------------------+" <<endl;
    INPUT_DATA ("Enter your selection: ", orderSelection);

    switch (orderSelection){
        case 1: 
                orderBeverage(TABLE_ID);
        case 2:
                listBeverage(TABLE_ID);
                
    }
}

void Staff::orderBeverage(uint8_t TABLE_ID){
    OrderBeverage order;
    INPUT_DATA("Name of beverage: ", order.NAME);
    INPUT_DATA("Quanity of beverage: ", order.QUANTITY);
    
    Database_Table[TABLE_ID-1].Database_Oder.push_back(order);
}

void Staff::listBeverage(uint8_t TABLE_ID){
    for(auto temp : Database_Table[TABLE_ID -1].Database_Oder){
        printf("Do an: %s", temp.NAME.c_str());
    }
}