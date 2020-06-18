#include <Servo.h>
#include <Wire.h>

byte pos = 95;
Servo myservo;

void setup() {
   myservo.attach(9); 
    //direccion del esclavo
   Wire.begin(10);
   //recepcion
   Wire.onReceive(receiveEvent);
}

void loop() {
  delay(1);
}
void receiveEvent(int howMany){
 // Si hay dos bytes disponibles
  int pinOut = 0;
  int estado = 0;
  if (Wire.available() == 2)
  {
    // Leemos el primero que será el pin
    pinOut = Wire.read();
    
  }
  // Si hay un byte disponible
  if (Wire.available() == 1)
  {
//    leemos la accion
    pos = Wire.read(); 
  }
  if (pos == 'C'){
  myservo.write(180);             
  
  }else if(pos == 'c'){
  myservo.write(0);             
  
  }else if(pos == 's'){
  myservo.write(89);             
  
  }
}
