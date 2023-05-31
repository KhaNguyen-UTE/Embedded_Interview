#include "Do_uong.h"

ListBeverage::ListBeverage(TypeBeverage NAME, int QUANTITY, float PRICE)
{
    static uint8_t ID = 100;
    ListBeverage::ID = ID;
    ListBeverage::NAME = NAME;
    ListBeverage::QUANTITY = QUANTITY;
    ListBeverage::PRICE = PRICE;
    ID++;
}

void ListBeverage::setName(TypeBeverage NAME)
{
    ListBeverage::NAME = NAME;
}

TypeBeverage ListBeverage::getName()
{
    return ListBeverage::NAME;
}

void ListBeverage::setPrice(float PRICE){
    ListBeverage::PRICE = PRICE;
}
float ListBeverage::getPrice(){
    return  ListBeverage::PRICE;
}

void ListBeverage::setQuantity(int QUANTITY){
    ListBeverage::QUANTITY = QUANTITY;
}

int ListBeverage::getQuantity(){
    return ListBeverage::QUANTITY;
}

uint8_t ListBeverage::getID(){
    return ListBeverage::ID;
}
