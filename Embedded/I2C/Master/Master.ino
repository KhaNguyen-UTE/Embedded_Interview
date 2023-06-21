/*
* File Name: Master.ino
* Author: Nguyen Tran Minh Kha
* Date: 20/06/2023
* Description: The program is used for creating the program for Slave received data from Master as I2C
*/

//Set pin for circuit
#define SDA 5
#define SCL 6

//Set the period for transmit data
#define FULL_PERIOD 100
#define HALF_PERIOD FULL_PERIOD / 2

//Set SDA pin as high level
#define SDA_HIGH              \
digitalWrite(SDA, 1);         \

//Set SDA pin as low level
#define SDA_LOW               \
digitalWrite(SDA, 0);         \

//Set SCL pin as high level
#define SCL_HIGH              \
digitalWrite(SCL, 1);         \

//Set SCL pin as low level
#define SCL_LOW               \
digitalWrite(SCL, 0);         \

//define a input mode for SDA pin
#define SDA_IN                \
pinMode(SDA, INPUT);          \

//define a output mode for SDA pin
#define SDA_OUT               \
pinMode(SDA, OUTPUT);         \

//define a output mode for SCL pin
#define SCL_OUT               \
pinMode(SCL, OUTPUT);         \

/*
* Function: SDA_READ()
* Description: read the signal from SDA pin
* Input:
*   none
* Output:
*   return the value of SDA
*/
uint8_t SDA_READ(){
    return digitalRead(SDA);
}

const byte ADDRESS = 0x55;    //Set the ADDRESS of Slave for Master

//Declare functions for Master
void startI2C();                                                //Start I2C
void stopI2C();												    //Stop I2C
uint8_t read_Ack();                                             //Read Ack status
void send_Ack();                                                //Send Ack Status
uint8_t receiveData(byte ADDRESS, byte * data, byte numbytes);  //Receive data from Slave
uint8_t readData();                                             //Read the data from Slave 
void transmitData(byte data);                                   //Send 1 byte data from Master
uint8_t writeData(byte ADDRESS, char *data);                    //Send full data with address from Master for Slave

/*
* Function: setup()
* Description: create the initial data
* Input:
*   none
* Output:
*   none
*/
void setup() {
  
  Serial.begin(115200);  
  
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
  uint8_t send = 0;
  uint8_t receive = 0;
  
  //State in which Master will write data to Slave
  Serial.println("Master begin sending data...");
  while ( send == 0){
      uint8_t run = writeData(ADDRESS, "I am Kha");    // The data want to send is "I am Kha"
      if (run == 1)    Serial.println("Send Error");
      else{
          Serial.println("Successfully send");
          send = 1;
      } 
  }

  delay(100);

  //State in which master will read data from Slave
  Serial.println("Master begin receiving data...");
  while (receive == 0){
  uint8_t res;
  byte rev[20] = {};
  res = receiveData(ADDRESS, rev, 10);
  if (res == 1){
    Serial.println("");
    Serial.println(String((char*)rev));
    receive = 1;
  }
  else    Serial.println("Sending Error");
  }

  delay(100);
}

/*
* Function: writeData()
* Description: have the function write the data base on the status of SDA pin
* Input:
*   ADDRESS : byte
*   *data: char
* Output:
*   return 1 if successfully write or 0 if reserve
*/
uint8_t writeData(byte ADDRESS, char *data){
    SDA_OUT;
    uint8_t ack_status;
    startI2C();

    ADDRESS = ADDRESS << 1;
    transmitData(ADDRESS);

    ack_status = read_Ack();
    if(ack_status == 1)  {
        stopI2C();
        Serial.println("");
        Serial.println("Don''t have Slave match ADDRESS");
        return 1;
    }
    else if(ack_status == 0){
      Serial.println("");
      Serial.println("One Slave match ADDRESS");
      Serial.println("");
    }

    while( *data != '\0'){
      transmitData(*data);
      Serial.print("  Master send Data: ");
      Serial.println((char)*data); 
      ack_status = read_Ack();
      if(ack_status == 1){
          stopI2C();
          return 1 ;
      }
      data++;
    }
    return 0;
}

/*
* Function: readData()
* Description: have the function read the data base on the status of SDA pin
* Input:
*   none
* Output:
*   return data
*/
uint8_t readData(){
  uint8_t data;
  SDA_IN;
  SCL_LOW;

  for( int i = 0; i < 8; i++){
    delay(HALF_PERIOD);
    SCL_HIGH;
    data = (data << 1) | SDA_READ();
    delay(HALF_PERIOD);
    SCL_LOW;
  }
  return data;
}

/*
* Function: receiveData()
* Description: have the function change the status of SDA pin for receive full input data
* Input:
*   ADDRESS : byte
*   data : byte
*   numbytes: byte
* Output:
*   return 1 if successfully receive
*/
uint8_t receiveData(byte ADDRESS, byte * data, byte numbytes){
  uint8_t ACK_STATUS;
  startI2C();

  ADDRESS = (ADDRESS << 1) +1 ;
  transmitData(ADDRESS);

  ACK_STATUS = read_Ack();
  if (ACK_STATUS == 1){
    stopI2C();
    return -1;
  }
  Serial.println("");
  Serial.println("One Slave match ADDRESS, begin receive..."); 

  for ( int i = 0; i < numbytes; i++){
      *data = readData();
      data++;
      send_Ack();
  }

  stopI2C();
  return 1;
}

/*
* Function:startI2C()
* Description: have the function start I2C
* Input:
*   none
* Output:
*   change the status of SCL, SDA pin
*/
void startI2C(){
  SDA_HIGH;
  SCL_HIGH;
  SDA_OUT;
  SCL_OUT;
  delay(FULL_PERIOD);

  SDA_LOW;
  delay(HALF_PERIOD);
  SCL_LOW;
  delay(HALF_PERIOD);
}

/*
* Function: transmitData()
* Description: have the function change the status of SDA pin for transmit 1 byte of input data
* Input:
*   data : byte
* Output:
*   none
*/
void transmitData(byte data){
  SDA_OUT;
  
  for ( int i = 0; i < 8; i++){
    if(( data & 0x80) != 0 ){
      SDA_HIGH;
      Serial.print(1);
    }
    else{
      SDA_LOW;
      Serial.print(0);
    }
    data = data << 1;
    delay(HALF_PERIOD);
    SCL_HIGH;
    delay(HALF_PERIOD);
    SCL_LOW;
    } 
}

/*
* Function:stopI2C()
* Description: have the function stop I2C
* Input:
*   none
* Output:
*   change the status of SCL, SDA pin
*/
void stopI2C(){
  SDA_OUT;
  SDA_LOW;
  delay(HALF_PERIOD);
  SCL_HIGH;
  delay(HALF_PERIOD);
  SDA_HIGH;
}

/*
* Function: read_Ack()
* Description: have the function read the Ack status base on signal from SDA pin
* Input:
*   none
* Output:
*   return 0 (Ack) or 1 (NAck)
*/
uint8_t read_Ack(){
    uint8_t STATUS;
    SDA_IN;
    
    delay(HALF_PERIOD);
    SCL_HIGH;
    delay(HALF_PERIOD);
    STATUS = digitalRead(SDA);
    SCL_LOW;
    delay(HALF_PERIOD);
    return STATUS;
}

/*
* Function: send_Ack()
* Description: have the function send the Ack status base on signal from SDA pin when Master reading data from Slave
* Input:
*   none
* Output:
*   none
*/
void send_Ack(){
    SCL_LOW;
    SDA_OUT;
    SDA_LOW;
    delay(HALF_PERIOD);
    SCL_HIGH;
    delay(HALF_PERIOD);
    SCL_LOW;
    delay(HALF_PERIOD);
}




