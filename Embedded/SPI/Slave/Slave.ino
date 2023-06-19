/*
* File Name: Slave.ino
* Author: Nguyen Tran Minh Kha
* Date: 15/06/2023
* Description: The program is used for creating the program for Slave received data from Master as SPI 
*/

//Set pin for circuit
#define SCK 2
#define MISO 3
#define MOSI 4
#define SS 5 

//Declare functions for Slave
void startSPI();               //Use to Start SPI
void createClock();            //Use to create Clock signal
void SlaveRecieve();           //Use to receive data from Master

int val = 0;
uint8_t arr[50];       // the data use for recieve
uint8_t temp = 0;
int i = 0;

/*
* Function: setup()
* Description: create the initial data
* Input:
*   none
* Output:
*   none
*/
void setup() {
    delay(2000);              //Delay 2s when plug-in
    pinMode(SCK, INPUT);
    pinMode(MISO, OUTPUT);
    pinMode(MOSI, INPUT);
    pinMode(SS, INPUT);

    Serial.begin(115200);
}

/*
* Function: loop()
* Description: the main function for program, have the function receive then print the received data to the monitor
* Input:
*   none
* Output:
*   print the data
*/
void loop() {
    temp = 0;
    SlaveRecieve();
    arr[i] = temp;
    i++;
    Serial.print("Recieved: ");
    for(int j =0; j <i; j++) Serial.print((char)arr[j]);
    Serial.println("");
    delay(20);
}

/*
* Function: SlaveRecieve()
* Description: have the function receive the data base on input signal then print the received data to the monitor
* Input:
*   none
* Output:
*   print the data
*/
void SlaveRecieve(){
    int i = 0;
    while(i < 8){
      val = digitalRead(SCK);
      if(val == HIGH){
        if(digitalRead(SS) == LOW){
            uint8_t x  = digitalRead(MOSI);
            Serial.print(x);
            temp = temp << 1;
            temp = temp | x;

            i++;
            Serial.print("     ");
            Serial.println(temp);
            delay(500);
        }
      }
      }
    Serial.println((char)temp);     //print the data in type of char
}