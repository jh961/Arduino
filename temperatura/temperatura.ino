
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
 


float temperatura = 0;
float valor=0;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

 
//Definicion de caracteres personalizados

void setup()
{
  // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin(16, 2);
  // Crear los caracteres personalizados en la pantalla

  pinMode(A1,INPUT);

  lcd.clear();  
  lcd.print("AUTORES");
  delay(1000);
}

void loop()
{

  valor=analogRead(A1);
  temperatura=((0.125*valor)-15.98);
  
  lcd.clear(); 
  lcd.print(temperatura);
  lcd.print(" Temperatura");
  delay(500);

 }


