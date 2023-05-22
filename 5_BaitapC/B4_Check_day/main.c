/*
* File Name: main.c
* Author: Kha Nguyen Tran Minh
* Date: 20/04/2023
* Description: Print the value of Time when input Day, Month and Year  
*/

#include "B4_Checkday.c"

int main()
{
    Time Current;
    inputTime(&Current);
    /*Check the input Time is valid or not*/
    if(checkErrorDay(Current)== false) printf("Error day");
    else{
        printf("%d/",Current.day);
        printf("%d/",Current.month);
        printf("%d\n",Current.year);
        exportDate(Current,original_Time);
    }
}