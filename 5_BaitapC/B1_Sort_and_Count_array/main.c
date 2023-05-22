/*
* File Name: main.c
* Author: Kha Nguyen Tran Minh
* Date: 20/04/2023
* Description: Sorting the array of type int in ascending and counts how many times the numbers appear in the array  
*/
#include "Baitap1_Xapxeptangdan.c"

int main()
{
    int isoluong;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&isoluong);
    int arr[isoluong];
    importArr(arr,isoluong);
    exportArr(arr,isoluong);
    convertArr(arr,isoluong);
    exportArr(arr,isoluong);
    countNumInArr(arr,isoluong);
}