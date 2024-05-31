
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2 //pin conexion sensor DH-11

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

const int espera=1000;
const int espera1=2000;

const int limtemp=30;
const int limhumed=60;
float h,t,f;

const int bombillo =3;
const int ventilador =4;

void setup()
{
  Serial.begin(9600);
  dht.begin();

  lcd.begin(16, 2);
  //lcd.home ();

  pinMode(bombillo, OUTPUT);
  pinMode(ventilador, OUTPUT);
  
  lcd.setCursor ( 0, 0 );
  lcd.print("AUTOR");
  lcd.setCursor ( 0, 1 );
  lcd.print("JAIME DIAZ");
  delay(espera);
  
  lcd.clear();
  lcd.print("ENCUBADORA");
  lcd.setCursor(0, 1);
  lcd.print("V 1.0");
  delay(espera);
}
 
void loop()
{
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();

  Serial.print("humedad  ");
  Serial.println(h);
  Serial.print("temperatura  ");
  Serial.println(t);

  if(h > limhumed){
    digitalWrite(ventilador,HIGH);
  }else if(h <= limhumed){
    digitalWrite(ventilador,LOW);
  }

  if(t <= limtemp){
    digitalWrite(bombillo,HIGH);
  }else if(t > limtemp){
    digitalWrite(bombillo,LOW);
  }


  lcd.setCursor ( 0, 0 );
  lcd.print("humed y Temp");
  lcd.setCursor ( 0, 1 );
  lcd.print(h);
  lcd.setCursor ( 7, 1 );
  lcd.print(t);
  delay(espera1);
  
 
}


 /*
  int i;
 
  for ( int i = 0; i < 5; i++ ) {
    lcd.scrollDisplayRight();
    delay (1000);
  }
 
 
  for ( int i = 0; i < 5; i++ ) {
    lcd.scrollDisplayLeft();
    delay (1000);
  }*/
