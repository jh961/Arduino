#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>


const int pin=2;

unsigned long contador =0;
unsigned long tiempo;
int Frecuencia =0;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


void cuenta(){
  contador++;
}

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  
  pinMode(pin,INPUT);

  attachInterrupt(0, cuenta, RISING);

  lcd.clear();
  lcd.print("QUE MIRAA");
  lcd.setCursor(0, 1);
  lcd.print("BUENA LA RATA ");
  delay(1000);

  Serial.println("QUE COMIENCE EL JUEGO");
  delay(100);
}

void loop() {
  if((millis() - tiempo)>=979){

    
  lcd.clear();
  
  lcd.print("FRECUENCIA= ");
  Serial.print("FRECUENCIA= ");
  lcd.setCursor(0, 1);
  contador = (contador/20)*60;
  Serial.print(contador);
  lcd.print(contador);
  lcd.print(" RPM");
  Serial.println(" RPM");

  
  Serial.print("tiempo: ");
  tiempo = millis();
  Serial.println(tiempo);
  
  contador=0;

  
  
  }
  
}



