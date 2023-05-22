/*
* File Name: Baitap9.cpp
* Author: Kha Nguyen Tran Minh
* Date: 20/05/2023
* Description: The program is used to enter color information, engine type and mileage. Calculation of maintenance and in vehicle information
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

/*
 * Function: Class Car
 * Description: The class represents the properties and methods of the car
 * Input:
 *    None
 * Output:
 *    None
*/
class Car{
    private:
        string color;
        string engine;
        int km;
    public:
        Car(string cl, string eng, float numkm);
        int cost();
        int checkCar();
        void exportData();
};

/*
* Function: Constructor Car
* Description: get data
* Input:
*    car_color - string
*    car_eng - string
*    car_km - int
* Output:
*    None
*/
Car::Car(string car_color, string car_eng, float car_km) {
    Car::color = car_color;
    Car::engine = car_eng;
    Car::km = car_km;
}

/*
 * Function: cost
 * Description: calculate cost of maintenance
 * Input:
 *    None
 * Output:
 *    return cost
*/
int Car::cost(){
    return Car::km * 5;
};

/*
 * Function: checkCar
 * Description: check the number of kilometer traveled
 * Input:
 *    None
 * Output:
 *    return the result
*/
int Car::checkCar() {
  return Car::km;
};

/*
 * Function: exportData
 * Description: export the data of Car
 * Input:
 *    None
 * Output:
 *    print the result
*/
void Car::exportData(){
    printf("Color: %s\n", Car::color.c_str());
    printf("Engine Type: %s\n",Car::engine.c_str());
    printf("The number of kilometers traveled: %.d\n", checkCar());
}

int main() {
    Car *setCar;
    setCar = new Car("Red", "V8", 1000);
    setCar->exportData();
    printf("Chi phi bao tri: %d$\n", setCar->cost());
}