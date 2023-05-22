/*
* File Name: Baitap3.cpp
* Author: Nguyen Tran Minh Kha
* Date: 20/05/2023
* Description: The program calculates the perimeter, area and diagonal of a circle
*/

#include <stdio.h>
#include <math.h>

const float pi = 3.14;

/*
 * Function: Class hinhTron
 * Description: The class represents the properties and methods of the circle
 * Input:
 *    None
 * Output:
 *    None
*/
class hinhTron {
  private:
    int banKinh;
  public:
    hinhTron(float bk);
    float chuViHinhTron();
    float dienTichHinhTron();
};

hinhTron::hinhTron(float bk){
    hinhTron::banKinh = bk;
}

/*
 * Function: chuViHinhTron
 * Description: calculate the perimeter of the circle
 * Input:
 *    None
 * Output:
 *    return the perimeter of the circle
*/
float hinhTron::chuViHinhTron() {
    return (2 * pi * hinhTron::banKinh);
};

/*
 * Function: dienTichHinhTron
 * Description: calculate the area of the circle
 * Input:
 *    None
 * Output:
 *    return the area of the circle
*/
float hinhTron::dienTichHinhTron(){
  return (pow(hinhTron::banKinh, 2) * pi);
};


int main() {
    hinhTron *setHinhTron;
    setHinhTron= new hinhTron((float)15);
    printf("chu vi ht la: %.2f\n", setHinhTron->chuViHinhTron());
    printf("dien tich ht la: %.2f\n",setHinhTron->dienTichHinhTron());
    delete setHinhTron;
    return 0;
}