/*
* File Name: main.c
* Author: Kha Nguyen Tran Minh
* Date: 25/04/2023
* Description: This file has the function to sort the string in the reverse direction and counts how many times the words in the string appear. 
*/

#include "B2_SortString.c"

int main()
{
    myString inputString;
    char str[]="I am Kha I am a student I live in HCM I want to become a coder and I am 23 years old";
    getWords(inputString.arr, str, &inputString.length);
    exportString(inputString);
    countEqualWords(inputString);
}