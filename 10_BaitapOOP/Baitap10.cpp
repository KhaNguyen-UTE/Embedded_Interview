/*
* File Name: Baitap10.cpp
* Author: Kha Nguyen Tran Minh
* Date: 20/05/2023
* Description: The program is used to enter infomation such as Name, year public, Author and the number of books remaining. Export the infomation then check borrow and back
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

/*
* Function: Class Book
* Description: The class represents the properties and methods of the book
* Input:
*    None
* Output:
*    None
*/
class Book{
    private:
        string name;
        string author;
        int public_year;
        int remain_book;
    public:
        Book(string nameBook, string authorBook, int year, int number);
        void borrowBook();
        void backBook();
        void infoBook();
};

/*
* Function: Constructor Book
* Description: get data of book
* Input:
*    nameBook - string
*    authorBook - string
*    year - int
*    number - int
* Output:
*    None
*/
Book::Book(string nameBook, string authorBook, int year, int number){
    Book::name = nameBook;
    Book::author = authorBook;
    Book::public_year = year;
    Book::remain_book = number;
}

/*
* Function: infoBook
* Description: show the infomation of book
* Input:
*    None
* Output:
*    return info
*/
void Book::infoBook(){
    printf("\nThong tin sach: \n");
    printf("Ten sach: %s\n", Book::name.c_str());
    printf("Tac gia: %s\n", Book::author.c_str());
    printf("Nam xuat ban: %d\n", public_year);
    printf("So luong con lai: %d\n", remain_book);
}

/*
* Function: borrowBook
* Description: show the status of borrow book
* Input:
*    None
* Output:
*    print borrow status
*/
void Book::borrowBook(){
    if(Book::remain_book <= 0) printf("Khong the muon sach '%s' vi da het so luong\n", Book::name.c_str());
    else printf("Ban da dang ky muon sach '%s' thanh cong\n", Book::name.c_str());
}

/*
* Function: backBook
* Description: show status of back book
* Input:
*    None
* Output:
*    return the status
*/
void Book::backBook(){
    printf("Ban da tra thanh cong sach '%s' cua tac gia '%s'. Xin cam on va hen gap lai.\n", Book::name.c_str(), Book::author.c_str());
}

int main(){
    Book *setBookData_1, *setBookData_2, *setBookData_3 ;
    setBookData_1 = new Book("Toan Cao Cap", "Giao Su A", 1900, 5);
    setBookData_2 = new Book("Hoa Dai Cuong", "Giao Su B", 1985, 0);
    setBookData_3 = new Book("Vat ly 1", "Giao Su C", 1950, 5);
    setBookData_1->infoBook();
    setBookData_2->infoBook();
    setBookData_3->infoBook();
    setBookData_1->borrowBook();
    setBookData_2->borrowBook();
    setBookData_3->backBook();
}