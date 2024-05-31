#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
 


float temperatura = 0;
float valor=0;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  

  pinMode(A1, INPUT);
  
  Serial.begin(9600); //Se inicia el puerto serial
 
  lcd.begin(16, 2);
  lcd.clear(); 
     lcd.setCursor(0,0); 
     lcd.print("AUTOR");
     lcd.setCursor(0,1); 
     lcd.print("JAIME DIAZ");
     delay(1000);  
}

void loop() {
  
  valor=analogRead(A1);
  temperatura=((0.125*valor)-15.98);
  
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("Temperatura");
  lcd.setCursor(0,1); 
  lcd.print(temperatura);
  lcd.print(" °C");

  Serial.print(temperatura);
  Serial.println(" °C");
  delay(500);
}
