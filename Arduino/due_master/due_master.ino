#include<Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}
byte slaves[] = {1,2,3,4};
byte pin;
byte rx;
char estado;
void loop() {
  rx = Serial.read();
  int tx;
  Wire.requestFrom(11, 1);  // solicita 6 bytes al dispositivo esclavo #11
  while (Wire.available()) {  // mientras hay datos lee los datos recibidos
    tx = Wire.read();  // recibe bytes como caracteres
    Serial.print("d");
    Serial.print(tx);  // imprime el carácter
    Serial.println("f");
  }
  switch(rx){
    case 'C':
         Serial.write(rx);
         Wire.beginTransmission(10);
         Wire.write(9);
         estado = 'C';
         Wire.write(estado);
         Wire.endTransmission();
         break;
     case 'c':
         Wire.beginTransmission(10);
         Wire.write(9);
         estado = 'c';
         Wire.write(estado);
         Wire.endTransmission();
         break;
     case 's':
         Wire.beginTransmission(10);
         Wire.write(9);
         estado = 's';
         Wire.write(estado);
         Wire.endTransmission();
         break;
     case 'O':
         Wire.beginTransmission(11);
         Wire.write(9);
         estado = 'O';
         Wire.write(estado);
         Wire.endTransmission();
         break;
     case 'o':
         Wire.beginTransmission(11);
         Wire.write(9);
         estado = 'o';
         Wire.write(estado);
         Wire.endTransmission();
         break;
     case 'f':
         Wire.beginTransmission(12);
         Wire.write(9);
         estado = 'f';
         Wire.write(estado);
         Wire.endTransmission();
         break;
     case 'l':
         Wire.beginTransmission(12);
         Wire.write(9);
         estado = 'f';
         Wire.write(estado);
         Wire.endTransmission();
         break;
     default:
          break;  
  }
  delay(20);
}
