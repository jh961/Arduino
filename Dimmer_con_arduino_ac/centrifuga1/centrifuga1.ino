
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int tiempo=0,tiempo1=300,tiempo2=500;
int velo1=80,velo2=170,velo3=255;
int const espera=500; // tiempo de espera delay.
int esperadato = 500;
int flat = 0;
int flat1 = 0;
int concatenar[10];
byte dim = 0;    //Initial brightness level from 0 to 255, change as you like!

int const AC_pin =3;
int const pulsa1 =4;
int const pulsa2 =5;
int const pulsa3 =6;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  pinMode(AC_pin, OUTPUT);
  pinMode(pulsa1, INPUT);
  pinMode(pulsa2, INPUT);
  pinMode(pulsa3, INPUT);
  //attachInterrupt(0, light, FALLING);//When arduino Pin 2 is FALLING from HIGH to LOW, run light procedure!


  lcd.clear();
  lcd.print("CENTRIFUGA");
  lcd.setCursor(0, 1);
  lcd.print("V 1.9");
  delay(espera);

  lcd.clear();
  lcd.print("AUTOR");
  lcd.setCursor(0, 1);
  lcd.print("JAIME DIAZ");
  delay(espera);

 
 }


void light() {
 for(int i=0;i<tiempo;i++){
    if (dim < 1) {                  //Turn TRIAC completely OFF if dim is 0
      digitalWrite(AC_pin, LOW);
      dim=1;
    }
    if (dim > 254) {                //Turn TRIAC completely ON if dim is 255
      digitalWrite(AC_pin, HIGH);
      dim=255;
    }
  
  if (dim > 0 && dim < 255) {      //Dimming part, if dim is not 0 and not 255
    delayMicroseconds(34*(255-dim));
    digitalWrite(AC_pin, HIGH);
    delayMicroseconds(500);
    digitalWrite(AC_pin, LOW);
  }
}
detachInterrupt(0);
}


void loop() {
  if(flat1==0){
  lcd.clear();
  lcd.print("SELECCIONE");
  lcd.setCursor(0, 1);
  lcd.print("EL TIEMPO");
  delay(espera);

  lcd.clear();
  lcd.print("1) 30 Segundos");
  lcd.setCursor(0, 1);
  lcd.print("2) 50 Segundos");

  while(true){
  if((digitalRead(pulsa1)== HIGH )){
    tiempo = tiempo1;
  }if((digitalRead(pulsa2)== HIGH )){
    tiempo = tiempo2;
  }

  while((digitalRead(pulsa1)== HIGH )||(digitalRead(pulsa2)== HIGH )){
      flat=1;
   }
   if(flat==1){
    break;
    flat=0;
   }
  }

  lcd.clear();
  lcd.print("SELECCIONE");
  lcd.setCursor(0, 1);
  lcd.print("LA VELOCIDAD");
  delay(espera);

  lcd.clear();
  lcd.print("1) 80  2) 170  ");
  lcd.setCursor(5, 1);
  lcd.print("3)  255");

  while(true){
  if((digitalRead(pulsa1)== HIGH )){
    dim = velo1;
  }if((digitalRead(pulsa2)== HIGH )){
    dim = velo2;
  }if((digitalRead(pulsa3)== HIGH )){
    dim = velo3;
  }

  while((digitalRead(pulsa1)== HIGH )||(digitalRead(pulsa2)== HIGH )||(digitalRead(pulsa3)== HIGH )){
      flat=1;
   }
   if(flat==1){
    break;
    flat=0;
    flat1=1;
    attachInterrupt(0, light, FALLING);//When arduino Pin 2 is FALLING from HIGH to LOW, run light procedure!
   }
  }
 }
}
