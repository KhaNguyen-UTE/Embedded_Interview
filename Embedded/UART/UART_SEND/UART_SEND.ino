/*
* File Name: UART_SEND.ino
* Author: Nguyen Tran Minh Kha
* Date: 20/06/2023
* Description: The program is used for creating the program for received data UART 
*
*/

//Set pin for circuit
#define TX 7
#define RX 6

//define a output mode for TX pin
#define TX_OUT                      \
pinMode(TX, OUTPUT);                \

//define a input mode for RX pin
#define RX_IN                       \
pinMode(RX, INPUT);                 \

//Set TX pin as high level
#define TX_HIGH                     \
digitalWrite(TX, 1);                \

//Set TX pin as low level
#define TX_LOW                      \
digitalWrite(TX, 0);                \


unsigned int UART_Cycle = 0;
char data = 'a';                    // The initial data will be uesed for send

/*
* Function: setup()
* Description: create the initial data
* Input:
*   none
* Output:
*   none
*/
void setup(){
  TX_OUT;
  TX_HIGH;
  delay(2000);
  start_UART(1200);
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
void loop(){
  write_1Byte_UART(data);
  data++;
  if (data > 'z'){
    data = 'a';
  }
  delay(1000);
}

/*
* Function:start_UART()
* Description: have the function start UART
* Input:
*   baudrate: unsigned int
* Output:
*   change the status of TX pin
*/
void start_UART(unsigned int baudrate){
    UART_Cycle = 1.0 / baudrate * 1000000;    // Change s to us
    TX_HIGH;
    TX_OUT;
}

/*
* Function: write_1Byte_UART()
* Description: have the function read the status base on signal from RX pin
* Input:
*   u_byte : const uint8_t
* Output:
*   print the data
*/
void write_1Byte_UART(const uint8_t u_byte){
    uint8_t count_parity = 0;
    uint8_t data;
    uint8_t send_byte;
    send_byte = u_byte;
    TX_LOW;
    delayMicroseconds(UART_Cycle);

    for(int i = 0; i < 8; i++){
        data = send_byte & 0x01;
        count_parity = count_parity ^ data;
        if (data == 1){
            TX_HIGH;
            Serial.print(1);
        }
        else if(data == 0){
            TX_LOW;
            Serial.print(0);
        }
        send_byte >>= 1;
        delayMicroseconds(UART_Cycle);
    }
    Serial.println("");
    if(count_parity == 1){
      TX_HIGH;
    }
    else{
      TX_LOW;
    }

    delayMicroseconds(UART_Cycle);

    Serial.print("Data send: ");
    Serial.println(String((char)u_byte));

    TX_HIGH;
    delayMicroseconds(UART_Cycle);
}

