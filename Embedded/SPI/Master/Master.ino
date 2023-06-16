#define SCK 2
#define MISO 3
#define MOSI 4
#define SS 5 

uint8_t data_transfer = 0x001;

void startSPI();
void createClock();
void masterTransfer(uint8_t data);


void setup() {
    delay(10000);
    pinMode(SCK, OUTPUT);
    pinMode(MISO, INPUT);
    pinMode(MOSI, OUTPUT);
    pinMode(SS, OUTPUT);

    
    Serial.begin(115200);
    startSPI();

}

void loop() {
  uint8_t arr[] = "Master transfer";
  int size = sizeof arr / sizeof arr[0];
  for(int i = 0; i< size; i++){
    masterTransfer(arr[i]);
    Serial.print("  Master send Data: ");
    Serial.println((char)arr[i]);
    delay(100);
  } 
  

}

void startSPI(){
  digitalWrite(SCK, LOW);
  digitalWrite(MOSI, LOW);
  digitalWrite(SS, LOW);
}

void createClock(){
  digitalWrite(SCK, HIGH);
  delay(1000);
  digitalWrite(SCK, LOW);
  delay(1000);
}

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
      delay(200);
  }
  digitalWrite(SS,HIGH);
}
