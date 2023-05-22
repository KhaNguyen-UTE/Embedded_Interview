/*
* File Name: Baitap2.cpp
* Author: Nguyen Tran Minh Kha
* Date: 20/05/2023
* Description: The program calculates the perimeter, area and diagonal of a rectangle. Check if it is square or not
*/

#include <stdio.h>
#include <math.h>

/*
* Function: Class hinhChuNhat
* Description: The class represents the properties and methods of the object rectangle
* Input:
*    None
* Output:
*    None
*/
class hinhChuNhat {
  private:  
    int chieuDai;
    int chieuRong;
  public:
    hinhChuNhat(int dai = 0, int rong = 0);
    int chuVi();
    int dienTich();
    double duongCheo();
    bool kiemTra();
};

hinhChuNhat::hinhChuNhat(int dai, int rong){
  chieuDai = dai;
  chieuRong = rong;
}

/*
* Function: chuVi
* Description: calculate the perimeter of the rectangle
* Input:
*    None
* Output:
*    return perimeter of a rectangle
*/
int hinhChuNhat::chuVi() {
  return (hinhChuNhat::chieuDai + hinhChuNhat::chieuRong) * 2;
}

/*
* Function: dienTich
* Description: calculate the area of ​​a rectangle
* Input:
*    None
* Output:
*    return area of a rectangle
*/
int hinhChuNhat::dienTich() {
  return (hinhChuNhat::chieuDai * hinhChuNhat::chieuRong);
}

/*
* Function: duongCheo
* Description: calculate the diagonal of the rectangle
* Input:
*    None
* Output:
*    return diagnoal of a rectangle
*/
double hinhChuNhat::duongCheo() {
  return sqrt( pow(hinhChuNhat::chieuDai, 2) + pow(hinhChuNhat::chieuRong, 2));
}

/*
 * Function: kiemTra
 * Description: check if it is square or not
 * Input:
 *    None
 * Output:
 *    return true if it is square, false if it isn't
*/
bool hinhChuNhat::kiemTra() {
  if(hinhChuNhat::chieuDai == hinhChuNhat::chieuRong) return true;
  else return false;
}

int main() {
  hinhChuNhat *hinhData;
  hinhData = new hinhChuNhat(20, 20);

  printf("Chu vi: %d\n", hinhData->chuVi());
  printf("Dien tich: %d\n",hinhData->dienTich());
  printf("Duong cheo: %.2f\n", hinhData->duongCheo());

  if(hinhData->kiemTra()) printf("Day la hinh vuong");
  else  printf("Day la hinh chu nhat");

  delete hinhData;
  return 0;
}