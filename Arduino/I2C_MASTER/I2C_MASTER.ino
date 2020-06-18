#include<Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}
byte pin[] = {2,3,4,5,6};
byte estado = 0;
void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(1);
  Wire.write(2);
  Wire.write(estado);
  Wire.endTransmission();
  delay(1000);

  if (estado == 0)
  {
    estado = 1;
  }
  else
  {
    estado = 0;
  }
}
