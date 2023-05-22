/*
* File Name: B5_Findnum.c
* Author: Kha Nguyen Tran Minh
* Date: 20/04/2023
* Description: This is a file containing a function that check the number whether or not appear in the random array
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
* Function: swapArr
* Description: This function swap the value of two assiged elements in the array
* Input:
*     a[]: the random array
*     i,j: numeric value indicate the element in the array
* Output:
*     This function do not have output
*/
void swapArr (int arr[],int i, int j)
{
    int temp = 0;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
* Function: sortArr
* Description: This function sort array in assending
* Input:
*     a[]: the random array
* Output:
*     This function do not have output
*/
void sortArr (int arr[])
{
    for (int i = 0; i < 10000; i++)
    {
        for (int j = i + 1 ; j < 10000; j++)
        {
            if (arr[i]> arr[j]) swapArr (arr,i,j);
        }
    }
}

/*
* Function: randomArr
* Description: This function uses rand() to create random array with value between 1 and 10000
* Input:
*     a[]: the random array 
* Output:
*     This function do not have output
*/
void randomArr(int arr[])
{
    for (int i = 0; i < 10000; i++)
    arr[i] = 1 + rand() % (10000 - 1 + 1);
}

/*
* Function: exportArr
* Description: This function print the array
* Input:
*      a[]: the random array
* Output:
*      print the array
*/
void exportArr(int arr[])
{
    printf("\n");
    for (int i = 0; i < 10000; i++)
    printf("%d ", arr[i]);
}

/*
* Function: binary_searchArr
* Description: This function use binary search method to search the number in the array
* Input:
*     arr[]: the random array
*     targetnum: the input number that want to check whether or not appear in array
* Output:
*     print the result
*/
void binary_searchArr(int arr[], int targetnum) 
{
    int check_status = 0;
    int index_low = 0, index_high = 10000;
    int count = 0;
    while (index_low <= index_high) {
        int index_mid = (index_high + index_low) / 2;
        count++;
        printf("Da quet %d lan voi vi tri mid = %d, low = %d, high = %d\n", count, index_mid, index_low, index_high);
        if (arr[index_mid] == targetnum)
        {
             check_status = 1;
             break;
        }      	
        else if (arr[index_mid] < targetnum)
            index_low = index_mid + 1;
        else
            index_high = index_mid - 1;
        
    }
    if(check_status == 1 ) printf("Co so dang tim trong day");
    else                   printf("Khong co so dang tim trong day");
    
}    	
