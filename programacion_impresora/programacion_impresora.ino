
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

byte carga8[8] = {    
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
};

TMRpcm Audio;   
#define pinSD 2 // pin para la lectura de sd

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int inicio= 3;
const int pausa= 4;
const int parar= 5;
const int ledinicio=6;
const int ledpausa=7;
const int ledparar=8;
const int motor= 14;
const int led1=15;
const int led2=16;
const int led3=17;

char caracter='.';

int estado =0;
int i=0,z=0,flat=0,pausa1=0, timefinal=0,cont=0,cont1=0,cont2=0;

long int tiempo;




void setup() {

  //TCCR2B = TCCR2B & 0b11111000 | 0x01;

  
  lcd.begin(20, 4);


  Audio.speakerPin = 9;
  Serial.begin(9600); // Inicia la comunicacion Serial.

  if (!SD.begin(pinSD)) {  //Verifica la coneccion de la tarjeta sd:
    Serial.println("Fallo en la tarjeta SD");  //Aviso de que algo no anda bien
    return;   //No hacer nada si no se pudo leer la tarjeta
  }
  Audio.volume(1);         
  //Audio.setVolume(6);
   
  pinMode(inicio, INPUT_PULLUP);
  pinMode(pausa, INPUT_PULLUP);
  pinMode(parar, INPUT_PULLUP);
  pinMode(ledinicio, OUTPUT);
  pinMode(ledpausa, OUTPUT);
  pinMode(ledparar, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(motor, OUTPUT);



 

  
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("IMPRESORA ");
  lcd.setCursor(14, 2);
  lcd.print("4D ");
  
  delay(1000);


  encender();

  
  lcd.clear();
  lcd.setCursor(6, 1);
  lcd.print("INICIANDO ");
  lcd.write((byte)7);
  

  for(i=0; i<20; i++){
    if(cont==0){
      digitalWrite(ledinicio , HIGH);
      digitalWrite(ledpausa, LOW);
      digitalWrite(ledparar, LOW);
      digitalWrite(led1 , HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      cont=1;
    }else if(cont==1){
      digitalWrite(ledinicio , LOW);
      digitalWrite(ledpausa, HIGH);
      digitalWrite(ledparar, LOW);
      digitalWrite(led1 , LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
       cont=2;
    }else if(cont==2){
      digitalWrite(ledinicio, LOW);
      digitalWrite(ledpausa, LOW);
      digitalWrite(ledparar, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      cont=0;
    }

        //lcd.clear();
        lcd.setCursor(i, 3);
        lcd.print("*");
        
    delay(200);
  }

  digitalWrite(motor, LOW); 


  digitalWrite(ledinicio , LOW);
  digitalWrite(ledpausa, LOW);
  digitalWrite(ledparar, LOW);
  
  

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BIENVENIDO");
  lcd.setCursor(0, 2);
  lcd.print("PROCESO DE CLONADO ");
  lcd.setCursor(0, 3);
  lcd.print("ORIGINAL Y COPIAS");
  delay(1000);
}

void loop() {

  while(Serial.available() > 0) {
    // get incoming byte:
    caracter = Serial.read();
    Serial.print(caracter);
  }

  if((caracter == 'K')){
    encender();
  }
  
  if((digitalRead(inicio) == LOW)||(caracter == 'S')){
    while((digitalRead(inicio) == LOW)){}

    
    
    digitalWrite(motor, HIGH); 
    Audio.play("inicio.wav");
    
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PROCESO INICIADO....");
    lcd.setCursor(0, 2);
    lcd.print("ORIGINAL Y COPIADO");
     delay(1000);

    estado=1;
    pausa1=0;
    cont1=0;
    cont2=0;
    tiempo=millis();
    digitalWrite(ledinicio , HIGH);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, LOW);

    caracter='.';
  
  }else if(((digitalRead(pausa) == LOW)&&(estado==1))||(caracter == 'P')){
    while((digitalRead(pausa) == LOW)){}

    digitalWrite(motor, LOW); 
    Audio.play("pausa.wav");
    
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PROCESO PAUSADO....");
    lcd.setCursor(0, 2);
    lcd.print("ORIGINAL Y COPIADO");
     delay(1000);
     pausa1=1;
     cont1=0;
     cont2=0;
  
     digitalWrite(ledinicio , LOW);
     digitalWrite(ledpausa, HIGH);
     digitalWrite(ledparar, LOW);

     caracter='.';
    
  }else if(((digitalRead(parar) == LOW)&&(estado==1))||(timefinal==1)||(caracter == 'F')){
    while((digitalRead(parar) == LOW)){}
      
    digitalWrite(motor, LOW); 
    Audio.play("final.wav");

    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PROCESO FINALIZADO....");
    lcd.setCursor(0, 2);
    lcd.print("ORIGINAL Y COPIADO");
    delay(1000);
    digitalWrite(ledinicio , LOW);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, HIGH);
    

    estado=0;
    timefinal=0;
    cont1=0;
    cont2=0;
    z=0;
    caracter='.';


    
  }else if((estado==0)&&(Audio.isPlaying()==0)) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BIENVENIDO");
    lcd.setCursor(0, 2);
    lcd.print("PROCESO DE CLONADO ");
    lcd.setCursor(0, 3);
    lcd.print("ORIGINAL Y COPIAS ");
    delay(100);

        lcd.setCursor(19, 3);
        lcd.print("-");
        delay(100);
  }



  if(estado==1){

    if((Audio.isPlaying()==0)&&(cont1==0)&&(pausa1==0)){
    Audio.play("indus.wav");
    cont1=1;
    //cont2=0;
    tiempo=millis();
    }
    
      
   

    if((Audio.isPlaying()==0)&&(pausa1==0)){
        timefinal=1;
    }
    
    if((cont1==1)&&(cont2==0)&&(pausa1==0)){
      if((millis() - tiempo) >= 60000){
         Audio.play("curso.wav");
         cont1=0;
         cont2=1;
      }
         }
  if(((millis() - tiempo) >= 4000)&&(pausa1==0)){
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PROCESO EN CURSO....");
    lcd.setCursor(0, 2);
    lcd.print("ORIGINAL Y COPIADO");

        if(z<20){ 
            lcd.setCursor(z, 3);
            lcd.write((byte)7);
            //delay(200);
          }
        z++;
        if(z>=20){
         z=0;  
        }
        
        
    delay(500);
      
  }
    
    if(pausa1==1){
      tiempo=millis();
    }
      
  }

 if(cont==0){
      digitalWrite(led1 , HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      cont=1;
    }else if(cont==1){
      digitalWrite(led1 , LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
       cont=2;
    }else if(cont==2){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      cont=0;
    }
    delay(100);
    
  if(Audio.isPlaying()==0){
    Audio.disable();  
  }
 
}



void encender(){

      lcd.clear();
      lcd.setCursor(5, 1);
      lcd.print("IMPRESORA ");
      lcd.setCursor(14, 2);
      lcd.print("4D ");

      digitalWrite(ledinicio , LOW);
      digitalWrite(ledpausa, LOW);
      digitalWrite(ledparar, LOW);

      Audio.stopPlayback();
      Audio.disable(); 
      
      while(true){
            while(Serial.available() > 0) {
              caracter = Serial.read();
              Serial.print(caracter);
            }
            if((digitalRead(inicio) == LOW)||(caracter == 'O')){
            while((digitalRead(inicio) == LOW)){}
            break;

            
            digitalWrite(ledinicio , HIGH);
            
           }
            estado=0;
            timefinal=0;
            cont=0;
            cont1=0;
            cont2=0;
            z=0;
            caracter='.';
            pausa1=1;
      }
 }
