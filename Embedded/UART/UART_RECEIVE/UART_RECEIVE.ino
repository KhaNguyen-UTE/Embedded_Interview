/*
* File Name: UART_RECEIVE.ino
* Author: Nguyen Tran Minh Kha
* Date: 20/06/2023
* Description: The program is used for creating the program for received data UART 
*
*/

//Set pin for circuit
#define TX 5
#define RX 7

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

/*
* Function: RX_READ()
* Description: read the signal from RX pin
* Input:
*   none
* Output:
*   return the value of RX
*/
uint8_t RX_READ(){
    return digitalRead(RX);
}

unsigned int UART_Cycle = 0;
char data;

/*
* Function: setup()
* Description: create the initial data
* Input:
*   none
* Output:
*   none
*/
void setup(){
    Serial.begin(9600);
    start_UART(2400);
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
  data = read_1Byte_UART();
  Serial.print(data);
}

/*
* Function:start_UART()
* Description: have the function start UART
* Input:
*   baudrate: unsigned int
* Output:
*   change the status of RX pin
*/
void start_UART(unsigned int baudrate){
    UART_Cycle = 1.0 / baudrate * 1000 * 1000;    // Change s to us
    RX_IN;
}

/*
* Function: read_1Byte_UART()
* Description: have the function read the status base on signal from RX pin
* Input:
*   none
* Output:
*   return the input data
*/
uint8_t read_1Byte_UART(){
    uint8_t data;
    uint8_t  u_byte = 0;
    while (RX_READ() == HIGH){}
    delayMicroseconds(UART_Cycle + UART_Cycle / 2);
    for (int i = 0; i < 8; i++){
        data = RX_READ();
        data = data << i;
        u_byte = u_byte | data;
        delayMicroseconds(UART_Cycle);
        
    }
    data = RX_READ();
    delayMicroseconds(UART_Cycle);
    if(data == 0) {
        return 0;
    }
    else return u_byte;
}