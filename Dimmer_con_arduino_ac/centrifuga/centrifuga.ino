
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

int AC_pin = 10;           //Pin to MOC3020 - OptoTriac
int dim[4];
int modu=0;              //Initial brightness level from 0 to 255, change as you like!

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pinMode(AC_pin, OUTPUT);
  attachInterrupt(0, light, FALLING);//When arduino Pin 2 is FALLING from HIGH to LOW, run light procedure!


  lcd.clear();
  lcd.print("AUTOR");
  lcd.setCursor(0, 1);
  lcd.print("JAIME DIAZ");
  delay(1000);
}

void light() {
   if (modu > 0 && modu < 255) {      //Dimming part, if dim is not 0 and not 255
       delayMicroseconds(34*(255-modu));
       digitalWrite(AC_pin, HIGH);
       delayMicroseconds(500);
       digitalWrite(AC_pin, LOW);
  }else if (modu < 1) {                  //Turn TRIAC completely OFF if dim is 0
      digitalWrite(AC_pin, LOW);
  }else if (modu > 254) {                //Turn TRIAC completely ON if dim is 255
      digitalWrite(AC_pin, HIGH);
  }
}

void loop() {

 for(int i=0;i<10;i++){
  lcd.clear();
  lcd.print("CONTEO");
  lcd.setCursor(0, 1);
  lcd.print(i);
  lcd.print("   ");
  lcd.print(modu);
  //delay(100);
 }

 if (Serial.available()) {
    for(int i=0;i<3;i++){
        dim[i] = Serial.read();
    }
    modu=(((dim[0]-48)*100)+((dim[1]-48)*10)+(dim[2]-48));
 }
}
