

#define SDA 5
#define SCL 6

void startI2C();
void stopI2C();
void transmitI2C(uint8_t data);
void Ack();
void NAck();

const uint8_t add = 0x05;

uint8_t read_Data();
uint8_t Wait_Ack();

void  setup(){
    pinMode (SDA, OUTPUT);
    pinMode (SCL, OUTPUT);

    Serial.begin(115200);
}


void loop(){
    uint8_t arr[] = "Embedded Interview";         // the data use for send
    transmitI2C(add);
    int size = sizeof arr / sizeof arr[0];
    for(int i = 0; i < size; i++){
        
    Serial.print("  Master send Data: ");
    Serial.println((char)arr[i]);
    delay(20);
  } 

}


void startI2C(){
    digitalWrite( SDA, 1);
    digitalWrite( SCL, 1);
    delay(5);
    digitalWrite( SDA, 0);
    delay(5);
    digitalWrite( SCL, 0);
}


void stopI2C(){	
    digitalWrite( SDA, 0);
    digitalWrite( SCL, 0);
    delay(5);
    digitalWrite( SDA, 1);
    digitalWrite( SCL, 1);	
    delay(5);
}

void Ack(){
	digitalWrite( SCL, 0);
	SDA_OUT();
	digitalWrite( SDA, 0);
	delay(2);
	digitalWrite( SCL, 1);
	delay(2);
	digitalWrite( SCL, 0);
}					
void NAck(){
	digitalWrite( SCL, 0);
	SDA_OUT();
	digitalWrite( SDA, 0);
	delay(2);
	digitalWrite( SCL, 1);
	delay(2);
	digitalWrite( SCL, 0);;
}

void SDA_OUT(){
    pinMode(SDA, OUTPUT);
}

void SDA_IN(){
    pinMode(SDA, INPUT);
}

void transmitI2C(uint8_t data){
	SDA_OUT();
	digitalWrite( SCL, 0);
	for(int i=0; i<8; i++){
        digitalWrite( SDA, (data &0x80) >> 7);
        data <<=1;
		delay(2);
		digitalWrite( SCL, 1);
		delay(2);
		digitalWrite( SCL, 0);
	}
}

void read_Data(uint8_t data){
    uint8_t rec=0;
	SDA_IN();
	for(int i=0; i<8; i++){
		digitalWrite( SCL, 0);
		delay(2);
		digitalWrite( SCL, 1);
		delay(2);
		rec<<=1;
		if(digitalRead(SDA)) rec++;
	}
	if(!data){
		Ack();
	}
		else{
		NAck();	
		}
}

uint8_t Wait_Ack(){
    uint8_t time=0;
	SDA_IN();
	digitalWrite(SDA, 1);
    delay(2);
	digitalWrite( SCL, 1);
    delay(2);
	while(digitalRead(SDA)){
		time++;
		if(time>250) {stopI2C(); return 1;}
	}
	digitalWrite( SCL, 0);
	return 0; 
}