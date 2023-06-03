#include "Beverage.hpp"

ListBeverage::ListBeverage(string name, int quantity , float price){
    static uint8_t id = 100;
    ListBeverage::ID = id;
    ListBeverage::NAME = name;
    ListBeverage::QUANTITY = quantity;
    ListBeverage::PRICE = price;
    id++;
}

void ListBeverage::setName(string NAME){
    ListBeverage::NAME = NAME;
}

string ListBeverage::getName(){
    return ListBeverage::NAME;
}

void ListBeverage::setPrice(float PRICE){
    ListBeverage::PRICE = PRICE;
}

float ListBeverage::getPrice(){
    return  ListBeverage::PRICE;
}

void ListBeverage::setQuantity(int quantity){
    ListBeverage::QUANTITY = quantity;
}

int ListBeverage::getQuantity(){
    return ListBeverage::QUANTITY;
}

uint8_t ListBeverage::getID(){
    return ListBeverage::ID;
}




