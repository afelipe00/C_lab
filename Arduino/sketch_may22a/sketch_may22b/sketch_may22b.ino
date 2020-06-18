#include <Keypad.h> 
 
char contrasena[]="1234";  
char codigo[4];            
int cont=0;          

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] =  
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 
 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
 
void setup()
{
  pinMode(13, OUTPUT); 
  pinMode(12, OUTPUT);
  Serial.begin(9600); 
}
 
void loop()
{
  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY)  
  {
    codigo[cont]=customKey;          
    Serial.print(codigo[cont]);    
    cont=cont+1;              
    if(cont==4)          
    {
      
      if(codigo[0]==contrasena[0]&&codigo[1]==contrasena[1]&&codigo[2]==contrasena[2]&&codigo[3]==contrasena[3])
      {
      
        Serial.println("\n Contraseña correcta");
        digitalWrite(13,HIGH);  
        digitalWrite(12, LOW);   
        
      }
      else if(codigo!=contrasena)
      {
        Serial.println("\n Contraseña incorrecta");
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        
      }
     
      cont=0; 
    }
    
  }
