/*
* File Name: main.c
* Author: Kha Nguyen Tran Minh
* Date: 25/04/2023
* Description: Enter an unsigned int number with a value between 0 and 999,999,999 and then output the reading of that number
*/

#include "B3_Read_num.c"

int main()
{
    unsigned int num;
    int arr[10]={0};
    enterNum(&num);
    checkZero(num);
    sepNumtoArr(num,arr);
    readAllNum(arr,lengthNum(num));
    
}