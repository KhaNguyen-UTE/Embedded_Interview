/*
* File Name: Master.ino
* Author: Nguyen Tran Minh Kha
* Date: 15/06/2023
* Description: The program is used for creating the program for Slave received data from Master as SPI 
*/

//Set pin for circuit
#define SCK 7
#define MISO 3
#define MOSI 4
#define SS 5 

//Declare functions for Slave
void startSPI();                     //Use to Start SPI
void createClock();                  //Use to create Clock signal
void masterTransfer(uint8_t data);   //Use to receive data from Master

/*
* Function: setup()
* Description: create the initial data
* Input:
*   none
* Output:
*   none
*/
void setup() {
    delay(2000);                 //Delay 2s when plug-in
    pinMode(SCK, OUTPUT);
    pinMode(MISO, INPUT);
    pinMode(MOSI, OUTPUT);
    pinMode(SS, OUTPUT);

    Serial.begin(115200);
    
    startSPI();

}

/*
* Function: loop()
* Description: the main function for program, have the function send then print the sent data to the monitor
* Input:
*   none
* Output:
*   print the data
*/
void loop() {
  uint8_t arr[] = "Embedded Interview";         // the data use for send
  int size = sizeof arr / sizeof arr[0];
  for(int i = 0; i< size; i++){
    masterTransfer(arr[i]);
    Serial.print("  Master send Data: ");
    Serial.println((char)arr[i]);
    delay(20);
  } 
  

}

/*
* Function:startSPI()
* Description: have the function start SPI
* Input:
*   none
* Output:
*   change the status of SCK, SS, MOSI pin
*/
void startSPI(){
  digitalWrite(SCK, LOW);
  digitalWrite(MOSI, LOW);
  digitalWrite(SS, LOW);
}

/*
* Function: createClock()
* Description: have the function create the Clock signal
* Input:
*   none
* Output:
*   change the status of SCK pin
*/
void createClock(){
  digitalWrite(SCK, HIGH);
  delay(500);
  digitalWrite(SCK, LOW);
  delay(500);
}

/*
* Function:  masterTransfer
* Description: have the function send the data base on input signal then print the sent data to the monitor
* Input:
*   data : uint8_t
* Output:
*   print the data
*/
void masterTransfer(uint8_t data){
  digitalWrite(SS, LOW);
  for(int i = 0; i<8 ; i++){
      uint8_t temp = data & 0x80;
      if(temp > 0){
          digitalWrite(MOSI, HIGH);
          Serial.print("1");
      }
      else{
            digitalWrite(MOSI, LOW);
            Serial.print("0");
      }
      data = data << 1 ;
      createClock();
      delay(20);
  }
  digitalWrite(SS,HIGH);
}
