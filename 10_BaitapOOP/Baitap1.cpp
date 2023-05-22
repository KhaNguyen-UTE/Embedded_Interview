/*
* File Name: Baitap1.cpp
* Author: Kha Nguyen Tran Minh
* Date: 20/05/2023
* Description: The program is used to create a layer of points in a 2D coordinate system and write methods to calculate the distance between two points, 
               calculate the area of the triangle formed by three points.
*/

#include <stdio.h>
#include <math.h>

/*
 * Function: Class Diem
 * Description: Class get the data of the point
 * Input:
 *    None
 * Output:
 *    None
*/
class Diem{
    private:
        int X;
        int Y;
    public:
        Diem(int X = 0, int Y = 0);
        int getX();
        int getY();
};

/*
* Function: Constructor Diem
* Description: convert data into point
* Input:
*   x - int
*   y - int
* Output:
*   None
*/
Diem::Diem(int x, int y){
    Diem::X = x;
    Diem::Y = y;
}

int Diem::getX(){
    return Diem::X;
}

int Diem::getY(){
    return Diem::Y;
}

/*
 * Function: Class calData
 * Description: Class calculate the area of triangle and length of line
 * Input:
 *    None
 * Output:
 *    None
*/
class calData{
    private:
        Diem A;
        Diem B;
        Diem C;
    typedef enum{
        KHOANG_CACH,
        DIEN_TICH
    }PhepToan;

    PhepToan kiemTra;
    public:
        calData(Diem a, Diem b, Diem c);
        calData(Diem a, Diem b);
        void khoangCachHaiDiem();
        void dienTichTamgiac();
};

/*
* Function: Constructor calData
* Description: get input data
* Input:
*   x - int
*   y - int
*   z - int
* Output:
*   None
*/
calData::calData(Diem a, Diem b){
    calData::A = a;
    calData::B = b;
    kiemTra = KHOANG_CACH;
}

calData::calData(Diem a, Diem b, Diem c){
    calData::A = a;
    calData::B = b;
    calData::C = c;
    kiemTra = DIEN_TICH;
}

/*
* Function: khoangCachHaiDiem()
* Description: calculate the length of line
* Input:
*   None
* Output:
*   print the result
*/
void calData::khoangCachHaiDiem(){
    if ( kiemTra == KHOANG_CACH){
        double khoangCach = (double)sqrt((A.getX()-B.getX())*(A.getX()-B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY()));
        printf("%f\n",khoangCach);
    }
    else 
        printf("Khong co chuc nang tinh khoang cach\n");
}

/*
* Function: dienTichtamgiac()
* Description: calculate the area of triangle
* Input:
*   None
* Output:
*   print the result
*/
void calData::dienTichTamgiac(){
    if ( kiemTra == DIEN_TICH){
        double dienTich = (double)abs((B.getX() - A.getX()) * (C.getY() - A.getY()) - (C.getX() -A.getX()) * (B.getY() - A.getY())) / (double)2;
        printf("%.2f\n",dienTich);
    }
    else 
        printf("Khong co chuc nang tinh dien tich\n");
}


int main(){
    calData point(Diem(1,2), Diem(1,5), Diem(5,5));
    point.khoangCachHaiDiem();
    point.dienTichTamgiac();
}