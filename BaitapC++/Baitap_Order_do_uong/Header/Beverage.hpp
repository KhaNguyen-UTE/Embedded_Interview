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
    uint8_t QUANTITY;
}OrderBeverage;

typedef struct{
    int NUM_TABLE;
    bool TABLE_STATUS;
    vector <OrderBeverage> Database_Oder;
}Table;

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
        vector <Table> Database_Table;
        int numTable = 0;
        
        TypePosition POSITION;
    public:
        MainMenu();
        TypePosition getPosition();
};

typedef enum{
    NAME,
    QUANTITY,
    PRICE
}TypeObject;

class Manage{
    private:
        vector <ListBeverage > *Database_Beverage;
        int *numTable;
        void checkInput(void * value, TypeObject object);
        
    public:
        Manage(vector <ListBeverage> &Database_Beverage, int &numtable);
        vector <ListBeverage> getDatabase_Beverage();
        void displayMenu();
        void numberOfTable();
        void addBeverage();
        void updateBeverage();
        void deleteBeverage();
        void listBeverage();
        int getNumTable();
};



class Staff{
    private:
        vector <ListBeverage> getDatabase_Beverage();
        vector <Table> Database_Table;
        vector <ListBeverage > *Database_Beverage;
        int *numTable;
        void orderBeverage(uint8_t TABLE_ID);
        void updateBeverage();
        void deleteBeverage();
        void listBeverage(uint8_t TABLE_ID);
        void createTable(uint8_t TABLE_ID);
        void resetTable();
    public:
        Staff(vector <ListBeverage> &Database_Beverage, int &numTable);
        void displayStaffMenu();
        
};
                                                                                            
#endif
