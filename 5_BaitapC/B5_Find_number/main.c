/*
* File Name: main.c
* Author: Kha Nguyen Tran Minh
* Date: 20/04/2023
* Description: This file use to check if the number appears in a random array and then print the result
*/

#include "B5_Findnum.c"

int main()
{
    int arr[10000];
    int targetnum; 
    srand(time(NULL));
    randomArr(arr);
    sortArr(arr);
    exportArr(arr);
    printf("\nNhap so can kiem tra: ");
    scanf("%d",&targetnum);
    arr[0] = -2;
    binary_searchArr(arr, targetnum);
}