/*
* File Name: Baitap7.cpp
* Author: Nguyen Tran Minh Kha
* Date: 20/05/2023
* Description: The program calculates the age of human and check holiday or not
*/

#include <stdio.h>

/*
 * Function: Class Date
 * Description: the class represents the properties and methods of the Date
 * Input:
 *    None
 * Output:
 *    None
*/
class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int d, int m, int y);
        int calAge(Date* setDate, Date* currentDate);
        bool checkHoliday();
};

/*
* Function: Constructor Date
* Description: get data of Date
* Input:
*    d - int
*    m - int
*    y - int
* Output:
*    None
*/
Date::Date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

/*
 * Function: calAge
 * Description: calculate age
 * Input:
 *    setDate
 *    currentDate
 * Output:
 *    return age in type int
*/
int Date::calAge(Date* setDate, Date* currentDate) {
    return currentDate->year - setDate->year;
}

/*
 * Function: checkHoliday
 * Description: check holiday or not
 * Input:
 *    None
 * Output:
 *    return true if that day is holiday and false if it is not
*/
bool Date::checkHoliday() {
    if (Date::day == 2 && Date::month == 9) return true;
    return false;
}

int main() {
    Date *setDate, *currentDate;
    setDate = new Date(4, 10, 2000);
    currentDate = new Date(20, 10, 2023);
    printf("Tuoi: %d\n", setDate->calAge(setDate, currentDate));
    if(setDate->checkHoliday() == true)   printf("Day la ngay le\n");
    else  printf("Day khong phai ngay le");
    delete setDate, currentDate;
    return 0;
}