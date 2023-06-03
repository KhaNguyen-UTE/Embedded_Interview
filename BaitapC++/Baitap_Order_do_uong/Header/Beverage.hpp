#ifndef __DO_UONG_H
#define __DO_UONG_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>

using namespace std;

typedef enum{
    MANAGER,
    STAFF
}TypePosition;

typedef struct{
    string NAME;
    int QUANTITY;
}OrderBeverage;

typedef struct{
    int NUM_TABLE;
    bool TABLE_STATUS;
    vector <OrderBeverage> Database_Oder;
}Table;

typedef enum{
    NAME,
    QUANTITY,
    PRICE
}TypeObject;

#define INPUT_DATA(test, value)     \
cout << test;                       \
cin  >> value;                      \

class ListBeverage{
    private:
        uint8_t ID;
        string NAME;
        int QUANTITY;
        float PRICE;
    public:
        ListBeverage(string name, int quantity , float price);
        void setName(string NAME);
        string getName();

        void setPrice(float PRICE);
        float getPrice();

        void setQuantity(int quantity);
        int getQuantity();
        uint8_t getID();
};

class MainMenu{
    private:
        vector <ListBeverage > Database_Beverage;
        vector <OrderBeverage> Database_Oder;
        int numTable = 0;
        TypePosition POSITION;
    public:
        MainMenu();
        TypePosition getPosition();
};

class Manage{
    private:
        vector <ListBeverage > *Database_Beverage;
        int *numTable;
        void checkInput(void * value, TypeObject object);
        void numberOfTable();
        void addBeverage();
        void updateBeverage();
        void deleteBeverage();
        int getNumTable();
    public:
        Manage(vector <ListBeverage> &Database_Beverage, int &numtable);
        vector <ListBeverage> getDatabase_Beverage();
        void displayMenu();
        void listBeverage();
        
};

class Staff{
    private:
        vector <ListBeverage> getDatabase_Beverage();
        vector <OrderBeverage> *Database_Oder;
        vector <Table> Database_Table;
        vector <ListBeverage > *Database_Beverage;
        int *numTable;
        void orderBeverage(int TABLE_ID);
        void updateBeverage(int TABLE_ID);
        void deleteBeverage(int TABLE_ID);
        void listBeverage(int TABLE_ID);
        void createTable(int TABLE_ID);
        void payBeverage(int TABLE_ID);
        
    public:
        Staff(vector <ListBeverage> &Database_Beverage, int &numTable,vector <OrderBeverage> &Database_Oder);
        void displayStaffMenu();
        void checkTable(int Table_ID);
};
                                                                                            
#endif
