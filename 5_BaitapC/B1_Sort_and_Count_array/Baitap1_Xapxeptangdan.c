/*
* File Name: Baitap1_Xapxeptangdan.c
* Author: Kha Nguyen Tran Minh
* Date: 20/04/2023
* Description: This is a file containing a function that sort the array of type int and counts how many times the numbers appear in the array
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
* Function: convertArr
* Description: This function converts position of 2 elements of type int in array if the preceding element is greater than the behind element
* Input:
*   n: size of array
*   arr: array
* Output:
*   returns the sorted array
*/
void convertArr(int arr[], int n)
{
    for (int i =0; i<n; i++)
    {
        for (int j = i+1; j<n;j++)
        {   
         if(arr[i]>arr[j])
            {
                int temp;
                temp= arr[i];
                arr[i] = arr[j];
                arr[j]= temp;
            }
        }
    }
}

/*
* Function: exportArr
* Description: This function prints the array 
* Input:
*   n: size of array
*   arr: array
* Output:
*   Print the input array
*/
void exportArr(int arr[], int n)
{
    printf("Mang la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/*
* Function: importArr
* Description: This function assigns random values from 1 to 50 by rand() to the members of the array
* Input:
*   isoluong: size of array that user input
*   arr: array
* Output:
*   returns the random array
*/
void importArr(int arr[],int isoluong)
{
    srand((int) time(0));
    for (int i = 0; i < isoluong; i++)
    {
        arr[i]= 1 + rand() % ( 50 + 1 - 1);
    }
}

/*
* Function: countNumInArr
* Description: This function uses array b[] with length equal to arr[] with all elements at the beginning with 1 to count how many times the element appears in the array
* Input:
*   isoluong: size of array that user input
*   arr: array
* Output:
*   print the number of times the element appears
*/
void countNumInArr(int arr[], int isoluong)
{
    int b[isoluong];
    for (int i = 0; i < isoluong; i++)  b[i] = 1;
    for (int i = 0; i < isoluong; i++)
    {
        int count = 1;
        if(b[i] == 1)
        {
           
            for (int j = i + 1; j < isoluong; j++)
            {
                if (arr[i] == arr[j])
                {
                count++;
                b[j] = 0;
                }
            }
        printf("Phan tu %d xuat hien %d lan\n", arr[i], count);
        }
        
    }
}

