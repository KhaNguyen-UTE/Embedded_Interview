/*
* File Name: Baitap6.cpp
* Author: Nguyen Tran Minh Kha
* Date: 20/05/2023
* Description: The program calculates sum, difference, product, quotient of 2 fractions
*/

#include <stdio.h>

/*
 * Function: Class PhanSo
 * Description: The class represents the properties and methods of the fraction
 * Input:
 *    None
 * Output:
 *    None
*/
class phanSo{
    private:
        int tuSo;
        int mauSo;
    public:
        phanSo(int tu = 0, int mau = 1);
        float getPhanSo();
};

/*
* Function: Constructor phanSo
* Description: get data
* Input:
*    tu - int
*    mau - int
* Output:
*    None
*/
phanSo::phanSo(int tu, int mau){
        phanSo::tuSo = tu;
        phanSo::mauSo = mau;
}

/*
 * Function: getPhanSo
 * Description: convert two numbers to fraction
 * Input:
 *    None
 * Output:
 *    return the fraction
*/
float phanSo::getPhanSo() {
  return (float)phanSo::tuSo / (float)phanSo::mauSo;
};

/*
 * Function: Class calPhanSo
 * Description: The class represents the properties and methods of the fraction
 * Input:
 *    None
 * Output:
 *    None
*/
class calPhanSo{
    private:
        phanSo A;
        phanSo B;
    public:
        calPhanSo(phanSo a, phanSo b);
        float congPhanSo();
        float truPhanSo();
        float nhanPhanSo();
        float chiaPhanSo();
};

/*
* Function: Constructor calPhanSo
* Description: get two fraction
* Input:
*    phanSo a
*    phanSo b
* Output:
*    None
*/
calPhanSo::calPhanSo(phanSo a, phanSo b){
    calPhanSo::A = a;
    calPhanSo::B = b;
}

/*
 * Function: congPhanSo
 * Description: sum of two fraction
 * Input:
 *    None
 * Output:
 *    return the result
*/
float calPhanSo::congPhanSo(){
  return A.getPhanSo() + B.getPhanSo();
}

/*
 * Function: truPhanSo
 * Description: subtract of two fraction
 * Input:
 *    None
 * Output:
 *    return the result
*/
float calPhanSo::truPhanSo() {
  return A.getPhanSo() - B.getPhanSo();
}

/*
 * Function: nhanPhanSo
 * Description: multiply of two fraction
 * Input:
 *    None
 * Output:
 *    return the result
*/
float calPhanSo::nhanPhanSo() {
  return A.getPhanSo() * B.getPhanSo();
}

/*
 * Function: chiaPhanSo
 * Description: divide of two fraction
 * Input:
 *    None
 * Output:
 *    return the result
*/
float calPhanSo::chiaPhanSo(){
  return A.getPhanSo() / B.getPhanSo();
}

int main() {
  printf("Tong 2 phan so = %.2f\n", calPhanSo(phanSo(1,15), phanSo(12,5)).congPhanSo());
  printf("Hieu 2 phan so = %.2f\n", calPhanSo(phanSo(123,11), phanSo(12,5)).truPhanSo());
  printf("Tich 2 phan so = %.2f\n", calPhanSo(phanSo(7,11), phanSo(1,5)).nhanPhanSo());
  printf("Thuong 2 phan so = %.2f\n", calPhanSo(phanSo(9,11), phanSo(12,5)).chiaPhanSo());
  return 0;
}