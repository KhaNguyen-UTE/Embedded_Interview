/*
* File Name: B4_Checkday.c
* Author: Kha Nguyen Tran Minh
* Date: 20/04/2023
* Description: This is a file containing a function that check what is the date entered from the user
*/

#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

/* Use to store input Time and first Time */
typedef struct
{
    int day;
    int month;
    int year;
}Time;

/* 1/1/1 is Monday */
const Time original_Time = {1,1,1};

/*
* Function: inputTime
* Description: This function uses to input day, month and year that we want to check
* Input:
*   *Current: information about the input Time
* Output:
*   This function don't have output
*/
void inputTime(Time *Current)
{  
    printf("Nhap ngay: ");
    scanf("%d",&Current->day);
    printf("Nhap thang: ");
    scanf("%d",&Current->month);
    printf("Nhap nam: ");
    scanf("%d",&Current->year);
}

/*
* Function: checkLeapYear
* Description: This function uses to check whether the year entered is a leap year or not
* Input:
*   check_year: input year to check leap year
* Output:
*   return true if input is a leap year and return false if not
*/
bool checkLeapYear(const int check_year)
{
    if (((check_year % 4 == 0) && (check_year % 100 != 0)) || (check_year % 400 == 0)) return true;
    return false;  
}

/*
* Function: countLeapYear
* Description: This function use to count how many leap year from 1 to the year input
* Input:
*   currentyear: input year
*   original_Timeyear: original year (1)
* Output:
*   return i _ sum of leap year
*/
int countLeapYear(const Time current, const Time original_Time)
{
    int i=0;
    for (int year = original_Time.year; year < current.year; year++)
    {
        if (checkLeapYear(year) == true)
        i++;
    }
    return i;
}

/*
* Function: countImpossibleDay
* Description: This function checks the maximun days possible in specific month
* Input:
*    currentyear: input year
*    index_month: month want to check maximun days
* Output:
*    maximun days in index_month 
*/
int countImpossibleDay(const Time current, const int index_month)
{
    int i;
    switch (index_month)
    {
        case 1: 
        case 3: 
        case 5:
        case 7: 
        case 8: 
        case 10:
        case 12: i = 31; break;

        case 4: 
        case 6: 
        case 9: 
        case 11: i = 30; break;

        case 2: i = 28; break;
    }
    if(checkLeapYear(current.year) == true && index_month == 2) i = 29;
    return i;
}

/*
* Function: checkErrorDay
* Description: This function check inputed Time is valid or not
* Input:
*     current: input Day, Month, Year
* Output:
*     return true if valid, false if not valid
*/
bool checkErrorDay(const Time current)
{
    if (current.year > 0 && current.month > 0 && current.month <13 && current.day > 0 && current.day <= countImpossibleDay(current, current.month)) return true;
    else return false;
}


/*
* Function: countDayFullMonth
* Description: This function counts all day in month have full day from 1 to input month
* Input:
*     Current: Day, Month, Year input
*     orginalmonth: original month (1)
* Output:
*     return all day in full month from 1 to month input
*/
int countDayFullMonth(const Time current,const Time original_Time)
{
    int temp = 0;
    for (int i = original_Time.month; i < current.month; i++)
    {
        temp = temp + countImpossibleDay(current,i);
    }
    return temp;
}

/*
* Function: calAllDay
* Description: This function calculates all days from original Time to input Time
* Input:
*   Current: Day, Month, Year input
*   original_Time: Day, Month,Year original
* Output:
*   return the number of days from 1/1/1 to input Time
*/
int calAllDay(const Time Current, const Time original_Time)
{
    int year_duration = Current.year - original_Time.year;

    /* Use to calculate the number of day from 1/1/1 -> 1/1/inputYear */
    int day_from_original_to_currentyear = (year_duration - countLeapYear(Current,original_Time)) * 365 + countLeapYear(Current,original_Time) * 366;

    /* Use to calculate the number of day from 1/1/inputYear -> inputDay/inputMonth/inputYear */
    int day_all_month = countDayFullMonth(Current, original_Time);
    int sum_of_day = day_from_original_to_currentyear + day_all_month + Current.day - 1; 
    return sum_of_day;
}


/*
* Function: exportDate
* Description: This function prints the statement
* Input:
*    Current: Day, Month, Year input
*    original_Time: Day, Month,Year, status original 
* Output:
*    print the value
*/
void exportDate(const Time Current, const Time original_Time)
{
    int sum = calAllDay(Current, original_Time);
    int temp = sum % 7 +1;
    switch (temp)
    {
        case 1: printf("That day is Monday"); break;
        case 2: printf("That day is Tuesday"); break;
        case 3: printf("That day is Wednesday"); break;
        case 4: printf("That day is Thursday"); break;
        case 5: printf("That day is Friday"); break;
        case 6: printf("That day is Saturday"); break;
        case 7: printf("That day is Sunday"); break;
    }
}
