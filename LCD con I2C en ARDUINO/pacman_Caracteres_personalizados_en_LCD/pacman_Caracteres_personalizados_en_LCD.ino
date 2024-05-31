#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
 
const int tiempo=500;
int p=0,g=2;
 
// Constructor sin control de backlight (retroiluminacion)
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
// Constructor con control de backlignt (retroiluminacion)
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 
//Definicion de caracteres personalizados
byte PACMAN1[8] = {    //// PACMAN ABIERTO 
  0b00001110,
  0b00011101,
  0b00011111,
  0b00011100,
  0b00011000,
  0b00011100,
  0b00011111,
  0b00001110,
};
byte PACMAN2[8] = {    //// PACMAN CERRADO
  0b00001110,
  0b00011101,
  0b00011111,
  0b00011111,
  0b00011000,
  0b00011111,
  0b00011111,
  0b00001110,
};
 
byte GHOST1[8] = {   //// FANTASMITA 1
  0b00001110,
  0b00011111,
  0b00010010,
  0b00010010,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00010101,
};

byte GHOST2[8] = {   //// FANTASMITA 2
  0b00001110,
  0b00011111,
  0b00010010,
  0b00010010,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00001010,
};

 
void setup()
{
  // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin(16, 2);
  
  // Crear los caracteres personalizados en la pantalla
  lcd.createChar (0, PACMAN1);
  lcd.createChar (1, PACMAN2);
  lcd.createChar (2, GHOST1);
  lcd.createChar (3, GHOST2);
  
  
  lcd.clear();
  lcd.print("BUENAS NOCHES");
  lcd.setCursor(0, 1);
  lcd.print("EIMY ZULUAGA");
  delay(1000);
}
 
void loop()
{
 for(int i=0;i<16;i++){
  lcd.clear();
  lcd.setCursor(i, 0);
  if(p==0){
     lcd.write((byte)p);
     lcd.write((byte)g);
     g=3;
     p=1;
  }else{
     lcd.write((byte)p);
     lcd.write((byte)g);
     g=2;
     p=0;
  }
  delay(tiempo);
  }
  
lcd.clear();

  for(int i=0;i < 16;i++){
    lcd.clear();
  lcd.setCursor(i, 1);
  if(p==0){
     lcd.write((byte)p);
     lcd.write((byte)g);
     g=3;
     p=1;
  }else{
     lcd.write((byte)p);
     lcd.write((byte)g);
     g=2;
     p=0;
  }
  delay(tiempo);
  }
}
