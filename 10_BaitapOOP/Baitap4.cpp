/*
* File Name: Baitap4.cpp
* Author: Nguyen Tran Minh Kha
* Date: 20/05/2023
* Description: The program calculate BMI then compare animal weight and age base on input data
*/
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

/*
 * Function: Class dongVat
 * Description: The class represents the properties and methods of the object animal
 * Input:
 *    None
 * Output:
 *    None
*/
class dongVat {
    private:
        string name;
        int age;
        float weight;
        float height;
    public:
        dongVat(string sName, int iAge, float fWeight, float fheight);
        float getBMI();
        string getName();
        float getAge();
        float getWeight();
};

dongVat::dongVat(string sName, int iAge, float fWeight, float fheight)
 {
    name = sName;
    age = iAge;
    weight = fWeight;
    height = fheight;
}

/*
 * Function: getName
 * Description: get name of the animal
 * Input:
 *    None
 * Output:
 *    return name
*/
string dongVat::getName() {
    return dongVat::name;
}

/*
 * Function: getAge
 * Description: get age of the animal
 *    None
 * Output:
 *    return age
*/
float dongVat::getAge() {
    return dongVat::age;
}

/*
 * Function: getWeight
 * Description: get weight of the animal
 * Input:
 *    None
 * Output:
 *    return weight
*/
float dongVat::getWeight() {
    return dongVat::weight;
}

/*
 * Function: getBMI
 * Description: calculate BMI index
 * Input:
 *    None
 * Output:
 *    return BMI index
*/
float dongVat::getBMI() {
    return (dongVat::weight / pow(dongVat::height, 2));
}

/*
 * Function: compareWeight
 * Description: compare weight between two animal object
 * Input:
 *    dongVat_1
 *    dongVat_2
 * Output:
 *    prinf the result
*/
void compareWeight(dongVat* dongVat_1, dongVat* dongVat_2){
    if (dongVat_1->getWeight() > dongVat_2->getWeight())  printf("Con %s nang hon con %s\n",dongVat_1->getName().c_str(),dongVat_2->getName().c_str());
    else if ((dongVat_1->getWeight() > dongVat_2->getWeight()))   printf("Con %s co trong luong bang con %s\n",dongVat_1->getName().c_str(),dongVat_2->getName().c_str());
    else   printf("Con %s nhe hon con %s\n",dongVat_1->getName().c_str(),dongVat_2->getName().c_str());
};

/*
 * Function: compareAge
 * Description: compare age between two animal object
 * Input:
 *    dongVat_1
 *    dongVat_2
 * Output:
 *    print the result
*/
void compareAge(dongVat* dongVat_1, dongVat* dongVat_2){
    if (dongVat_1->getAge() > dongVat_2->getAge())  printf("Con %s lon tuoi hon con %s\n",dongVat_1->getName().c_str(),dongVat_2->getName().c_str());
    else if ((dongVat_1->getAge() > dongVat_2->getAge()))   printf("Con %s lon bang con %s\n",dongVat_1->getName().c_str(),dongVat_2->getName().c_str());
    else   printf("Con %s nho tuoi hon con %s\n",dongVat_1->getName().c_str(),dongVat_2->getName().c_str());
};

int main() {
    dongVat *animal[2];
 
    animal[0] = new dongVat("Dog", 2, (float)20, (float)0.5);
    animal[1] = new dongVat("Cat", 3, (float)2, (float)0.3);
    
    for (int i = 0; i < 2; i++){
        printf("Chi so BMI cua con %s la: %.2f\n",animal[i]->dongVat::getName().c_str(), animal[i]->dongVat::getBMI());
    }
    compareWeight(animal[0], animal[1]);
    compareAge(animal[0], animal[1]);

    delete animal[2];
    return 0;
}