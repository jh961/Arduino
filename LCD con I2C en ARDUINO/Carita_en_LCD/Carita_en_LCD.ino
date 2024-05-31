
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
 
const int tiempo=1000;
int flat=0;
 
// Constructor sin control de backlight (retroiluminacion)
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
// Constructor con control de backlignt (retroiluminacion)
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 
//Definicion de caracteres personalizados
byte ojoa1[8] = {    //// OJO ABIERTO PARTE 1
  0b00001000,
  0b00000101,
  0b00000010,
  0b00001101,
  0b00001001,
  0b00000100,
  0b00000001,
  0b00000000,
};

byte ojoa2[8] = {    //// OJO ABIERTO PARTE 2
  0b00010010,
  0b00011111,
  0b00010001,
  0b00001100,
  0b00001100,
  0b00010001,
  0b00011111,
  0b00000000,
};
byte ojoa3[8] = {    //// OJO ABIERTO PARTE 3
  0b00000010,
  0b00010100,
  0b00001000,
  0b00010110,
  0b00010010,
  0b00000100,
  0b00010000,
  0b00000000,
};

byte ojoc1[8] = {    //// OJO CERRADO PARTE 1
  0b00000000,
  0b00000001,
  0b00000010,
  0b00000101,
  0b00001111,
  0b00000100,
  0b00000001,
  0b00000000,
};
byte ojoc2[8] = {    //// OJO CERRADO PARTE 2
  0b00000000,
  0b00011111,
  0b00000000,
  0b00001010,
  0b00011111,
  0b00000000,
  0b00011111,
  0b00000000,
};
byte ojoc3[8] = {    //// OJO CERRADO PARTE 3
  0b00000000,
  0b00010000,
  0b00001000,
  0b00010100,
  0b00011110,
  0b00000100,
  0b00010000,
  0b00000000,
};

byte pico1[8] = {   //// PICO PARTE 1
  0b00000001,
  0b00000100,
  0b00010001,
  0b00000100,
  0b00010001,
  0b00000100,
  0b00010001,
  0b00000100,
};

byte pico2[8] = {   //// PICO PARTE 2
  0b00000000,
  0b00101010,
  0b00010101,
  0b00111110,
  0b00111110,
  0b00111110,
  0b00010101,
  0b00101010,
};

byte pico3[8] = {   //// PICO PARTE 3
  0b00010000,
  0b00001000,
  0b00010010,
  0b00001000,
  0b00010010,
  0b00001000,
  0b00010010,
  0b00001000,
};
 
byte risa1[8] = {   //// RISA PARTE 1
  0b00010000,
  0b00011100,
  0b00011111,
  0b00001000,
  0b00000010,
  0b00000001,
  0b00000000,
  0b00000000,
};

byte risa2[8] = {   //// RISA PARTE 2
  0b00000000,
  0b00000000,
  0b00011111,
  0b00000000,
  0b00000000,
  0b00001111,
  0b00000110,
  0b00000000,
};

byte risa3[8] = {   //// RISA PARTE 3
  0b00000001,
  0b00000111,
  0b00011111,
  0b00000010,
  0b00001000,
  0b00010000,
  0b00000000,
  0b00000000,
};

void setup(){
  
  // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin(16, 2);
  
  // Crear los caracteres personalizados en la pantalla
  lcd.createChar (0, ojoa1);
  lcd.createChar (1, ojoa2);
  lcd.createChar (2, ojoa3);
 
  lcd.createChar (3, ojoc1);
  lcd.createChar (4, ojoc2);
  lcd.createChar (5, ojoc3);
  
  lcd.createChar (6, pico1);
  lcd.createChar (7, pico2);
  /*lcd.createChar (8, pico3);
  
  lcd.createChar (9, risa1);
  lcd.createChar (10, risa2);
  lcd.createChar (11, risa3);
*/
  
  lcd.clear();
  lcd.print("AUTOR");
  lcd.setCursor(0, 1);
  lcd.print("JAIME DIAZ");
  delay(1000);

/*lcd.clear();
  lcd.setCursor(4, 0);
  ////////////// OJO 1 ABIETO
  lcd.print (char(0));
  lcd.print (char(1));
  lcd.print (char(2));
  
  lcd.setCursor(9, 0);
  lcd.print (char(0));
  lcd.print (char(1));
  lcd.print (char(2));

  lcd.setCursor(6, 1);
  lcd.print (char(3));
  lcd.print (char(4));
  lcd.print (char(5));

  ////////////// OJO 2 ABIERTO
  lcd.setCursor(9, 0);
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.write((byte)2);

  ///////////// RISA
  lcd.setCursor(6, 1);
  lcd.write((byte)9);
  lcd.write((byte)10);
  lcd.write((byte)11);
  */
}
 
void loop(){
 
  lcd.clear();
  
  lcd.createChar (0, ojoa1);
  lcd.createChar (3, risa1);
  lcd.createChar (4, risa2);
  lcd.createChar (5, risa3);
  
  ////////////// OJO 1 ABIETO
  lcd.setCursor(4, 0);
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.write((byte)2);
  
  ////////////// OJO 2 ABIERTO
  lcd.setCursor(9, 0);
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.write((byte)2);

  ///////////// RISA
  lcd.setCursor(6, 1);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  
  delay(tiempo);
  lcd.clear();
  
  lcd.createChar (0, pico3);
  lcd.createChar (3, ojoc1);
  lcd.createChar (4, ojoc2);
  lcd.createChar (5, ojoc3);
  
  ////////////// OJO 1 CERRADO
  lcd.setCursor(4, 0);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  
  ////////////// OJO 2 CERRADO
  lcd.setCursor(9, 0);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);

  ///////////// PICO
  lcd.setCursor(6, 1);
  lcd.write((byte)6);
  lcd.write((byte)7);
  lcd.write((byte)0);
  
  delay(tiempo);
  
}
