/*
* File Name: ListBeverage.cpp
* Author: Nguyen Tran Minh Kha
* Date: 04/06/2023
* Description: The program is used to setup for Class ListBeverage
*/

#include "Beverage.hpp"

/*
* Function: Constructor ListBeverage
* Description: get data
* Input:
*   name - string
*   quantity - int
*   price - float
* Output:
*   None
*/
ListBeverage::ListBeverage(string name, int quantity , float price){
    static uint8_t id = 100;
    ListBeverage::ID = id;
    ListBeverage::NAME = name;
    ListBeverage::QUANTITY = quantity;
    ListBeverage::PRICE = price;
    id++;
}

/*
* Function: setName()
* Description: set name for beverage
* Input:
*   NAME - string
* Output:
*   none
*/
void ListBeverage::setName(string NAME){
    ListBeverage::NAME = NAME;
}

/*
* Function: getName()
* Description: get name for beverage
* Input:
*   none
* Output:
*   return name in type of string
*/
string ListBeverage::getName(){
    return ListBeverage::NAME;
}

/*
* Function: setPrice()
* Description: set price for beverage
* Input:
*   PRICE - float
* Output:
*   none
*/
void ListBeverage::setPrice(float PRICE){
    ListBeverage::PRICE = PRICE;
}

/*
* Function: getPrice()
* Description: get price for beverage
* Input:
*   none
* Output:
*   return price in type of float
*/
float ListBeverage::getPrice(){
    return  ListBeverage::PRICE;
}

/*
* Function: setQuantity()
* Description: set quantityfor beverage
* Input:
*   quantity - int
* Output:
*   none
*/
void ListBeverage::setQuantity(int quantity){
    ListBeverage::QUANTITY = quantity;
}

/*
* Function: getQuantity()
* Description: get quantity for beverage
* Input:
*   none
* Output:
*   return quantity in type of int
*/
int ListBeverage::getQuantity(){
    return ListBeverage::QUANTITY;
}

/*
* Function: getID()
* Description: get ID for beverage
* Input:
*   none
* Output:
*   return ID in type of uint8_t
*/
uint8_t ListBeverage::getID(){
    return ListBeverage::ID;
}




