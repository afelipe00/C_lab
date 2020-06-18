#include <Wire.h>
#define Slave1 3

#define Adress 1

void setup() {
  // Pines en modo salida
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Wire.begin(Slave1);
  Wire.onReceive(Recibir);
  Serial.begin(9600);
}
int led;
void Recibir(int howMany){
  while(Wire.available() > 0){
    led=2;
    byte N = Wire.read();
    for(int k = 0; k<=7 ; k++){
      digitalWrite(led,bitRead(N,k));
      led++;
    }
  }
}
void loop() {
}
