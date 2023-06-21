/*
* File Name: Slave.ino
* Author: Nguyen Tran Minh Kha
* Date: 20/06/2023
* Description: The program is used for creating the program for Slave received data from Master as I2C
*/

//Set pin for circuit
#define SDA 5
#define SCL 6

//Set the period for transmit data
#define SDA_HIGH              \
digitalWrite(SDA, 1);         \

//Set SDA pin as high level
#define SDA_LOW               \
digitalWrite(SDA, 0);         \

//Set SDA pin as low level
#define SCL_HIGH              \
digitalWrite(SCL, 1);         \

//Set SCL pin as high level
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

//define a output mode for SCL pin
#define SCL_IN                \
pinMode(SCL, INPUT);          \

const byte address = 0x55;    //Set the address of Slave for Master

//Declare functions for Master
uint8_t slave_begin(byte address);                    //Start I2C Slave 
uint8_t read_1Byte();                                 //Read 1 byte data from Master
void readFullData(byte *data, uint8_t count);         //Read full data from Master
uint8_t read_Ack();                                   //Read Ack status
void write_1Byte(byte data);                          //Write 1 byte data from Slave
uint8_t writeFullData(char *data);                    //Write 1 byte data from Slave


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
  uint8_t rev[100] = {};
  uint8_t data;

  delay(100);
  begin_I2C:
  uint8_t begin_status = slave_begin(address);
  if(begin_status == 0) {
    Serial.println("");
    Serial.println("Match address of Master...");
    Serial.println("Slave begin receiving data...");
    readFullData(rev, 8);
    
    Serial.println(String((char*)rev));
    goto begin_I2C;
  }

  else if(begin_status == 1){
    Serial.println("");
    Serial.println("Master want to read");
    Serial.println("Slave begin sending data...");
    again:
    data = writeFullData("I am slave");
    if (data == 1) {
        Serial.println("Successfull send data");
        goto begin_I2C;
    }
    else {
        Serial.println("Send error");
        goto again;
    }
  }

  else {
    Serial.println("Don't match with address sending by Master");
    delay(100);
    goto begin_I2C;
  }
}

/*
* Function: loop()
* Description: the main function for program, have the function send then print the sent data to the monitor
* Input:
*   none
* Output:
*   print the data
*/
void loop(){
    delay(100);
}

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

/*
* Function: SCL_READ()
* Description: read the signal from SCL pin
* Input:
*   none
* Output:
*   return the value of SCL
*/
uint8_t SCL_READ(){
    return digitalRead(SCL);
}

/*
* Function: read_1Byte()
* Description: have the function read 1 byte of the data base on the status of SDA pin
* Input:
*   none
* Output:
*   return data
*/
uint8_t read_1Byte(){
    byte data;
    SDA_IN;
    for(int i = 0; i < 8; i++){
        while(SCL_READ() == 0);
        data = (data << 1) | SDA_READ();
        while (SCL_READ() == 1);
    }

    SDA_OUT;
    SDA_LOW;
    while(SCL_READ() == 0);
    while(SCL_READ() == 1);
    SDA_IN;
    return data;
} 

/*
* Function: readFullData()
* Description: have the function read the data base on the status of SDA pin
* Input:
*   none
* Output:
*   return data
*/
void readFullData(byte *data, uint8_t count){
    for(int i = 0; i < count; i++){
        *data = read_1Byte();
        data++;
    }
}

/*
* Function: slave_begin()
* Description: have the function begin the function of Slave (waiting for matching address) base on the status of SDA pin
* Input:
*   none
* Output:
*   return 0 if match address and master want to write, 1 if match address and master want to read, -1 if don't match address
*/
uint8_t slave_begin(byte address){
    uint8_t data = 0;
    uint8_t read_write_status = 0;
    while(1){
        SDA_IN;
        SCL_IN;
        while((SDA_READ() != 1) || (SCL_READ() != 1));
        while ((SDA_READ() == 1));
        delay(25);
        if(SCL_READ() == 1){
            while (SCL_READ() == 1);
            for(int i = 0; i < 8; i++){
                 while(SCL_READ() == 0);
                 data = (data << 1) | SDA_READ();
                 while (SCL_READ() == 1); 
            }
            
            read_write_status = data & 1;

            data = data >> 1 ; 

            if(data == address){
                SDA_OUT;
                SDA_LOW;
                while(SCL_READ() == 0);
                while(SCL_READ() == 1);
                SDA_IN;
                return read_write_status;
            }
            return -1;
        }
    }
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
    
    while(SCL_READ() == 0);
    SCL_HIGH;
    STATUS = digitalRead(SDA);
    while(SCL_READ() == 1);

    return STATUS;
}

/*
* Function: write_1Byte()
* Description: have the function write 1 byte of the data base on the status of SDA pin
* Input:
*   data : byte
* Output:
*   none
*/
void write_1Byte(byte data){
    SDA_OUT;
    for (int i =0; i < 8; i++){
        if( (data & 0x80) != 0){
            SDA_HIGH;
            Serial.print(1);
        }
        else {
            SDA_LOW;
            Serial.print(0);
        }
        while(SCL_READ() == 0);
        while(SCL_READ() == 1);
        data = data << 1 ;
    }
}

/*
* Function: writeFullData()
* Description: have the function write full data base on the status of SDA pin
* Input:
*   *data : char
* Output:
*   none
*/
uint8_t writeFullData(char *data){
    while (*data !='\0'){
        uint8_t ACK_STATUS;
        write_1Byte(*data);
        ACK_STATUS= read_Ack();
        if (ACK_STATUS == 1){
            SDA_IN;
            return -1;
        }
        Serial.print("  Slave send Data: ");
        Serial.println((char)*data); 
        data++;
    }
    SDA_IN;
    return 1;
}

