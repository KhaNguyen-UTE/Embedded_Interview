/*
* File Name: B2_SortString.c
* Author: Kha Nguyen Tran Minh
* Date: 25/04/2023
* Description: This is a file containing a function that sort the string in reverse and count how many times the words appear
*/

#include <stdio.h>

#define true 1;
#define false 0;

typedef int bool;

typedef struct{
    char arr[1000][20];
    int length;
}myString;

/*
* Function: exportString
* Description: This function outputs the string in the opposite direction
* Input:
*     inputString: is a struct containing an array that stores each word and the number of words in the string
* Output:
*     print the result
*/
void exportString(myString inputString)
{
    for(int i = inputString.length - 1; i >= 0; i--){
        printf("%s",inputString.arr[i]);
        if(i != 0) printf(" ");
    }
}

/*
* Function: getWords
* Description: This function extracts the words and store them in an array, counts the number of words in the string
* Input:
*     inputString[1000][20]: array that use to store the word
*     str[]: input string
*     *k: variable used to store word count
* Output:
*     This function do not have output
*/
void getWords(char inputString[1000][20], char str[], int *k)
{
    int length = 0, e = 0;
    int temp = -1;
    int i = 1;
    char *p = str;
    while (str[i-1] != '\0')
    {
        if ((str[i] == ' ') | str[i] == '\0' ){
            length = i - 1 - temp;
            temp = i;
            for (int j = 0; j < length; j++){
                inputString[e][j] = *(p+j);
            }
            e++;
            p = str + i + 1;
        }
        i++;
    }
    *k = e;
}

/*
* Function: checkWords
* Description: This function check two words in array equal or not
* Input:
*     inputString[1000][20]: array that store the word
*     i,j: position of two words in array
* Output:
*     return true if equal, false if not equal
*/
bool checkWords (char inputString[1000][20], int i, int j)
{   
    int h = 0;
    while (inputString[i][h] == inputString[j][h])
    {
        if (inputString[i][h] == '\0') return true;
        h++;
    }
    return false;
}

/*
* Function: countEqualWords
* Description: This function count how many time one word appear in the string
* Input:
*     inputString: 
* Output:
*     print the result
*/
void countEqualWords(myString inputString)
{
    printf("\n\n");
    int n = inputString.length;

    /* Initialize array b[] with length equal to inputString.length with all elements at the beginning = 1 */
    int b[n];
    for(int k = 0; k < n; k++)    b[k] = 1;
    for(int i = 0; i < n; i++)
    {
        int count =1;
        if(b[i]==1)  
        {
            for (int j = i + 1; j < n; j++)
            {
                bool k =checkWords(inputString.arr,i,j);
                if(k == 1)
                { 
                    count++;
                    b[j] = 0; /* If a word has already been browsed, change the position of the array b at that position to zero to not re-read it again */
                }
            }
            printf("Phan tu - %s - xuat hien %d lan\n", inputString.arr[i], count);
        }  
    }
}