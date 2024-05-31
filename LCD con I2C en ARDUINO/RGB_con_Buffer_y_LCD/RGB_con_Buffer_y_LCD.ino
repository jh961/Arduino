#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
 
const int tiempo=500;
int led1=2;
int led2=3;
int led3=4;
int parlante=5;
 
// Constructor sin control de backlight (retroiluminacion)
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
// Constructor con control de backlignt (retroiluminacion)
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


char letra='.';
 
//Definicion de caracteres personalizados

void setup()
{
  // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin(16, 2);
  Serial.begin(9600);
  // Crear los caracteres personalizados en la pantalla

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(parlante,OUTPUT);


  lcd.clear();
  lcd.print("AUTORES");
  lcd.setCursor(0, 1);
  lcd.print("EIMY ZULUAGA");
  delay(1000);
}
 
void loop()
{
   while (Serial.available()) {
    // get the new byte:
    letra = (char)Serial.read();
    Serial.println(letra);
  }
 switch (letra) {
  case 'a':
  analogWrite(led1,255);
  analogWrite(led2,0);
  analogWrite(led3,0);
  analogWrite(parlante,0);
  break;
  case 'b':
  analogWrite(led1,0);
  analogWrite(led2,255);
  analogWrite(led3,0);
  analogWrite(parlante,0);
  break;
  case 'c':
  analogWrite(led1,0);
  analogWrite(led2,0);
  analogWrite(led3,255);
  analogWrite(parlante,0);
  break;
 case '1':
  analogWrite(led1,0);
  analogWrite(led2,0);
  analogWrite(led3,0);
  analogWrite(parlante,255);
  break;
  case '2':
  analogWrite(led1,0);
  analogWrite(led2,0);
  analogWrite(led3,0);
  analogWrite(parlante,170);
  break;
  case '3':
  analogWrite(led1,0);
  analogWrite(led2,0);
  analogWrite(led3,0);
  analogWrite(parlante,120);
  break;
 }
 

}
