#define SCK 2
#define MISO 3
#define MOSI 4
#define SS 5 


void startSPI();
void createClock();
void SlaveRecieve();

int val = 0;
uint8_t arr[50];
uint8_t temp = 0;
int i = 0;

void setup() {
    delay(5000);
    pinMode(SCK, INPUT);
    pinMode(MISO, OUTPUT);
    pinMode(MOSI, INPUT);
    pinMode(SS, INPUT);

    
    Serial.begin(115200);

}

void loop() {
    temp = 0;
    SlaveRecieve();
    arr[i] = temp;
    i++;
    Serial.print("Recieved: ");
    for(int j =0; j <i; j++) Serial.print((char)arr[j]);
    Serial.println("");
    delay(200);

}


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
        delay(1500);
    }
  }
  }
  Serial.println((char)temp);
  
}