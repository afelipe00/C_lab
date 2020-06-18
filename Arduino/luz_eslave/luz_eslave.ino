#include <Wire.h>
#define Slave1 11
#define Adress 1

int band =0;
int pinLDR = 0;
int valorLDR = 0;
int a = 800;
int pinLed1 = 2;
int pinLed2 = 3;
int pinLed3 = 4;
int pinLed4 = 5;
int pinLed5 = 6;
int pinLed6 = 7;
int pinLed7 = 8;
int pinLed8 = 9;
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
  Wire.onRequest(escrituraEvento);
  Serial.begin(9600);
}
void loop() {
  
}
int led;
byte luz;
void Recibir(int howMany){
  
  while(Wire.available() > 0){
      luz = Wire.read();
      valorLDR = analogRead(pinLDR);
      if(luz == 'O'){
        band = 1;      
      }else if(luz == 'o'){
        band = 0;
 
      }
      if(band == 1){
        digitalWrite(pinLed1, HIGH);
        digitalWrite(pinLed2, HIGH);
        digitalWrite(pinLed3, HIGH);
        digitalWrite(pinLed4, HIGH);
        digitalWrite(pinLed5, HIGH);
        digitalWrite(pinLed6, HIGH);
        digitalWrite(pinLed7, HIGH);
        digitalWrite(pinLed8, HIGH);  
      }else if(band == 0 ){
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);
        digitalWrite(pinLed4, LOW);
        digitalWrite(pinLed5, LOW);
        digitalWrite(pinLed6, LOW);
        digitalWrite(pinLed7, LOW);
        digitalWrite(pinLed8, LOW);  
         
      }
  }
}
void escrituraEvento() {  //define la función de envio
  valorLDR = analogRead(pinLDR);
  valorLDR = valorLDR / 4;
  Wire.write(valorLDR);  //responde con un mensaje de 5 bytes
  Serial.println(valorLDR);
}
