/*
* File Name: Baitap5.cpp
* Author: Nguyen Tran Minh Kha
* Date: 20/05/2023
* Description: The program printf the information of human
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

/*
 * Function: Class nguoi
 * Description: The class represents the properties and methods of the object human
 * Input:
 *    None
 * Output:
 *    None
*/

class nguoi{
    private:
        string name;
        string address;
        int yearOfBirth;
    public:
        nguoi(string name, int yearOfBirth, string address);
        void getData();
        int getAge();
};

nguoi::nguoi(string name, int yearOfBirth, string address){
    nguoi::name = name;
    nguoi::yearOfBirth = yearOfBirth;
    nguoi::address = address;
};

/*
 * Function: getData
 * Description: print information
 * Input:
 *     None
 * Output:
 *     print the data
*/
void nguoi::getData(){
    printf("Ten: %s\n", nguoi::name.c_str());
    printf("Nam sinh: %d\n", nguoi::yearOfBirth);
    printf("Dia chi: %s\n", nguoi::address.c_str());
}

/*
 * Function: getAge
 * Description: calculate a person's age as of 2023
 * Input:
 *    None
 * Output:
 *    return age
*/
int nguoi::getAge() {
    return 2023 - nguoi::yearOfBirth;
}

int main() {
    nguoi *setHuman;
    setHuman = new nguoi("Nguyen Tran Minh Kha", 2000, "Ba Ria - Vung Tau");

    setHuman->nguoi::getData();
    printf("Tuoi: %d\n", setHuman->getAge());
    delete setHuman;
    return 0;
}