#ifndef __DO_UONG_H
#define __DO_UONG_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>

using namespace std;

typedef enum{
    COCA,
    PEPSI,
    SEVEN_UP,
    STING,
    MIRRINDA
}TypeBeverage;

typedef enum{
    MANAGER,
    STAFF
}TypePosition;

#define INPUT_DATA(test, value)     \
cout <<test;                        \
cin  >> value;                      \

class MainMenu{
    private:
        TypePosition POSITION;
    public:
        MainMenu();
        TypePosition getPosition();
};

class ListBeverage{
    private:
        uint8_t ID;
        TypeBeverage NAME;
        int QUANTITY;
        float PRICE;
    public:
        ListBeverage(TypeBeverage NAME, int QUANTITY, float PRICE);
        void setName(TypeBeverage NAME);
        TypeBeverage getName();

        void setPrice(float PRICE);
        float getPrice();

        void setQuantity(int quantity);
        int getQuantity();
        uint8_t getID();
};

class ManageOrder{
    private:
        vector <ListBeverage> DatabaseBeverage;
    public:
        ManageOrder();
        void addBeverage();
        void updateBeverage();
        void deleteBeverage();
        void listBeverage();
        
};

typedef enum{
    BOOKED,
    NOT_BOOKED
}TypeTableStatus;

class Staff{
    private:
        TypeTableStatus STATUS;
        uint8_t TABLE_ID;

    public:
        void setStatus(TypeTableStatus STATUS);
        TypeTableStatus getStatus();

        void setTable(uint8_t TABLE);
        uint8_t getTable();
};
                                                                                            
class Table{
    private:
        vector <Staff> DataOrder;
        uint8_t TABLE_ID;
    public:
        Table(); 
        void orderBeverage();
        void updateBeverage();
        void deleteBeverage();
        void listBeverage();
        vector <ListBeverage> getListBeverage();
};


#endif
