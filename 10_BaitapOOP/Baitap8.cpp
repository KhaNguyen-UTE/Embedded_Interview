/*
* File Name: Baitap8.cpp
* Author: Nguyen Tran Minh Kha
* Date: 20/05/2023
* Description: The program to enter account information for deposit and withdrawal
*/

#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * Function: Class account
 * Description: The class represents the properties and methods of the account
 * Input:
 * Input:
 *    None
 * Output:
 *    None
*/
class account {
    private:
        string accName; 
        int accNumber;
        int accBalance;
    public:
        account(string name, int number, int balance);
        uint16_t getBalance();
        void napTien(int soTien);
        void rutTien(int soTien);
};

/*
* Function: Constructor account
* Description: input account data
* Input:
*    name - string
*    number - int
*    balance - int
* Output:
*    None
*/
account::account(string name, int number, int balance){
    account::accName = name;
    account::accNumber = number;
    account::accBalance = balance;
}

/*
 * Function: napTien
 * Description: deposit money into account
 * Input:
 *    soTien - int
 * Output:
 *    printf the result
*/
void account::napTien(int soTien){
    printf("So tien hien co la: %d\n", account::accBalance);
    account::accBalance += soTien;
    printf("So tien sau khi nap la: %d\n", account::accBalance);
}

/*
* Function: rutTien
* Description: withdraw money from account
* Input:
*    soTien - int
* Output:
*    printf the result
*/
void account::rutTien(int soTienRut){
    if(soTienRut > account::accBalance) printf("So du khong du de rut\n");
    else{
        account::accBalance -= soTienRut;
        printf("So tien sau khi rut la: %d\n",account::accBalance);
    }
}

int main() {
    account *setData;
    setData = new account("Minh Kha", 123456456, 10000);
    setData->napTien(5000);
    setData->rutTien(10000);
    setData->rutTien(11000);
    return 0;
}