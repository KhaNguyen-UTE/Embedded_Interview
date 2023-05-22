/*
* File Name: B3_Read_num.c 
* Author: Kha Nguyen Tran Minh
* Date: 25/04/2023
* Description: This is a file containing a function that read the input number in a type unsigned int with value from 0 to 999.999.999
*/

#include <stdio.h>

/*
* Function: enterNum
* Description: This function uses to enter the number
* Input:
*     *num: variable that stores the value of the input number
* Output:
*     This function do not have output
*/
void enterNum(int *num)
{
    printf("Enter the number: ");
    scanf("%d",num);
}

/*
* Function: lengthNum
* Description: This function count the length of the number entered
* Input:
*     inputNum: the entered number
* Output:
*     return length of the number
*/
int lengthNum(const int inputNum)
{
    int temp = inputNum;
    int length = 0;
    while (temp != 0)
    {
        temp = temp / 10;
        length++;
    }
    return length;
}

/*
* Function: sepNumtoArr
* Description: This function use to separate the digits and store in array arr
* Input:
*     inputNum: the entered number
*     arr[]: the array use to store digit after separate
* Output:
*     This function do not have output
*/	
void sepNumtoArr(const int inputNum, int arr[])
{
    int count = 0;
    int digit = inputNum;
    while (digit != 0)
    {
        arr[count] = digit % 10;
        digit = digit / 10;
        count++;
    }
}

/*
* Function: readThreeNum
* Description: This function that reads 3 digits at a time in hundreds, tens, and units
* Input:
*     arr[][3]: 3-digit cluster has been divided
*     k: the index represents the position of the cluster of 3-digit in the array arr
* Output:
*     print the result of read 3-digit cluster number
*/
void readThreeNum(const int arr[][3], const int index, const int length)
{
    /* Read the digit in hundreds */
    switch(arr[index][2]){
        case 1: printf("mot tram ");break;
        case 2: printf("hai tram ");break;
        case 3: printf("ba tram ");break;
        case 4: printf("bon tram ");break;
        case 5: printf("nam tram ");break;
        case 6: printf("sau tram ");break;
        case 7: printf("bay tram ");break;
        case 8: printf("tam tram ");break;
        case 9: printf("chin tram ");break;
    }

    /* Check the special case with the number 0 */  
    if(index == length -1 && arr[index][1] == 0 && arr[index][2] != 0)    printf("le ");                                                    
    if(arr[index][1] == 0 && arr[index][0] != 0 && index < length - 1)    printf("le ");

    /* Read the digit in tens */
    switch(arr[index][1]){
        case 1: printf("muoi ");break;
        case 2: printf("hai muoi ");break;
        case 3: printf("ba muoi ");break;
        case 4: printf("bon muoi ");break;
        case 5: printf("nam muoi ");break;
        case 6: printf("sau muoi ");break;
        case 7: printf("bay muoi ");break;
        case 8: printf("tam muoi ");break;
        case 9: printf("chin muoi ");break;
    }

    /* Check the special case with the number 5 */ 
    if(arr[index][1] == 0 && arr[index][0] ==5)   printf("nam ");

    /* Read the digit in units*/
    else
    {
        switch(arr[index][0]){
            case 1: printf("mot ");break;
            case 2: printf("hai ");break;
            case 3: printf("ba ");break;
            case 4: printf("bon ");break;
            case 5: printf("lam ");break;
            case 6: printf("sau ");break;
            case 7: printf("bay ");break;
            case 8: printf("tam ");break;
            case 9: printf("chin ");break;
        }
    }
}

/*
* Function: readAllNum
* Description: This function read full entered number
* Input:
*   arr[]: the array store the value of entered number after separate in function sepNumtoArr()
*   length: the length of the entered number
* Output:
*   print the result of full entered number
*/	
void readAllNum(const int arr[], int length)
{
    /* Divide the number into clusters of 3 digits */
    if (length % 3 == 0) length = length / 3;
    else length = length / 3 + 1;

    /* Initialize array to store each cluster of 3 numbers */
    int arr_to_count[length][3];
    int count =0;
    for (int i=0; i<length;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr_to_count[i][j] = arr[count];
            count ++;
        }
    }

    /* Read each 3-digit phrase and add suffixes like thousands and millions */
    for (int index = length - 1; index >= 0; index--)
    {
        readThreeNum(arr_to_count,index,length);
        if (index + 1 == 3) printf("trieu ");
        if (index + 1 == 2) printf("nghin ");
    }
}

/*
* Function: checkZero
* Description: This function check the entered number equal 0 or not
* Input:
*     num: the entered number
* Output:
*     print "khong" if the entered number is 0
*/	
void checkZero(int num)
{
    if (num == 0) printf("khong");
}
