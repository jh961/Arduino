#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>
#include "Nextion.h"

TMRpcm Audio;   
#define pinSD 53 // pin para la lectura de sd

    uint32_t Estado_start=1;
    uint32_t Estado_pausa=1;
    uint32_t Estado_stop=1;

    int Estado_encender=0;
    int Estado_apagar=0;

   

NexDSButton botonstart = NexDSButton(3, 2, "b1");
NexDSButton botonpausa = NexDSButton(3, 3, "b2");
NexDSButton botonstop = NexDSButton(3, 4, "b3");
NexDSButton botonencender = NexDSButton(0, 1, "b1");
NexDSButton botonapagar = NexDSButton(1,7, "b6");

//NexText estado1 =  NexText(1, 7, "b6");

NexTouch *nex_listen_list[] = 
{
    &botonstart,&botonpausa,&botonstop,&botonencender,&botonapagar,
    NULL
};



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

void funcionbotonstart(void *ptr);
void funcionbotonpausa(void *ptr);
void funcionbotonstop(void *ptr);
void funcionbotonencender(void *ptr);
void funcionbotonapagar(void *ptr);




void setup() {

  //TCCR2B = TCCR2B & 0b11111000 | 0x01;

  
  Audio.speakerPin = 11;
  Serial.begin(9600); // Inicia la comunicacion Serial.

  if (!SD.begin(pinSD)) {  //Verifica la coneccion de la tarjeta sd:
    Serial.println("Fallo en la tarjeta SD");  //Aviso de que algo no anda bien
    return;   //No hacer nada si no se pudo leer la tarjeta
  }
  Serial.println("tarjeta SD TODO OK");
  Audio.volume(1);         
  //Audio.setVolume(6);

  nexInit();

  botonstart.attachPop(funcionbotonstart, &botonstart);
  botonpausa.attachPop(funcionbotonpausa, &botonpausa);
  botonstop.attachPop(funcionbotonstop, &botonstop);
  botonencender.attachPop(funcionbotonencender, &botonencender);
  botonapagar.attachPop(funcionbotonapagar, &botonapagar);

  
  pinMode(ledinicio, OUTPUT);
  pinMode(ledpausa, OUTPUT);
  pinMode(ledparar, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(motor, OUTPUT);



  //encender();

/*
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
*/
               
   // delay(200);
  

  digitalWrite(motor, LOW); 


  digitalWrite(ledinicio , LOW);
  digitalWrite(ledpausa, LOW);
  digitalWrite(ledparar, LOW);
  
 
   Audio.disable(); 

}

void loop() {

  nexLoop(nex_listen_list);

  if(Audio.isPlaying()==0){
    Audio.disable();  
  }
  // Audio.stop();

  
  while(Serial.available() > 0) {
    // get incoming byte:
    caracter = Serial.read();
    Serial.print(caracter);
    //funcionboton();
    
  }

  if((Estado_encender == 1)||(caracter == 'K')){
    encender();
    Estado_encender = 0;
  }

  
  if((Estado_start == 0)||(caracter == 'S')){
   // while((digitalRead(inicio) == LOW)){}
   Estado_start=1;
   Estado_pausa=1;
   Estado_stop=1;

    Serial.println("paso 1");
    
    digitalWrite(motor, HIGH); 
    Audio.play("inicio.wav");
    
    
    estado=1;
    pausa1=0;
    cont1=0;
    cont2=0;
    tiempo=millis();
    digitalWrite(ledinicio , HIGH);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, LOW);

    caracter='.';
    Serial.println("paso 1,5");
  
  }else if(((Estado_pausa == 0)&&(estado==1))||(caracter == 'P')){
    //while((digitalRead(pausa) == LOW)){}
    Estado_start=1;
   Estado_pausa=1;
   Estado_stop=1;

    digitalWrite(motor, LOW); 
    Audio.play("pausa.wav");

    Serial.println("paso 2");
   
     pausa1=1;
     cont1=0;
     cont2=0;
  
     digitalWrite(ledinicio , LOW);
     digitalWrite(ledpausa, HIGH);
     digitalWrite(ledparar, LOW);

     caracter='.';
    
  }else if(((Estado_stop == 0)&&(estado==1))||(timefinal==1)||(caracter == 'F')){
    //while((digitalRead(parar) == LOW)){}
    Estado_start=1;
   Estado_pausa=1;
   Estado_stop=1;
      
    digitalWrite(motor, LOW); 
    Audio.play("final.wav");

  Serial.println("paso 3");
  
    digitalWrite(ledinicio , LOW);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, HIGH);
    

    estado=0;
    timefinal=0;
    cont1=0;
    cont2=0;
    z=0;
    caracter='.';


    
  }else if((Estado_apagar == 1)) {

    Estado_apagar = 0;

  Serial.println("paso 23");

  digitalWrite(motor, LOW); 
  Audio.play("adios.wav");
  delay(2000);
  Audio.stopPlayback();
   Audio.disable();

  
    digitalWrite(ledinicio , LOW);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, LOW);
    

    estado=0;
    timefinal=0;
    cont1=0;
    cont2=0;
    z=0;
    caracter='.';
    
  }



  if(estado==1){

    if((Audio.isPlaying()==0)&&(cont1==0)&&(pausa1==0)){
    Audio.play("indus.wav");
    cont1=1;
    //cont2=0;
    tiempo=millis();
    Serial.println("paso 1,2");
    }
    
      
   

    if((Audio.isPlaying()==0)&&(pausa1==0)){
        timefinal=1;
        Serial.println("paso 2,2");
    }
    
    if((cont1==1)&&(cont2==0)&&(pausa1==0)){
      if((millis() - tiempo) >= 60000){
         Audio.play("curso.wav");
         cont1=0;
         cont2=1;
         Serial.println("paso 2,3");
      }
      Serial.println("paso 2,5");
         }
         /*
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
    */
    if(pausa1==1){
      tiempo=millis();
      Serial.println("paso 2,7");
    }
    Serial.println("paso 1,7");  
  }

 if(cont==0){
      digitalWrite(led1 , HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      cont=1;
     // Serial.println("paso 1,11111");
    }else if(cont==1){
      digitalWrite(led1 , LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
       cont=2;
       //Serial.println("paso 1,222222");
    }else if(cont==2){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      cont=0;
     // Serial.println("paso 1,333333");
    }
    delay(100);
    
  if(Audio.isPlaying()==0){
    Audio.disable();  
    //Serial.println("paso 1,5555555");
  }
Serial.println("paso 3333.773");
  
}


void funcionbotonstart(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botonstart.getValue(&Estado_start);
    //botonpausa.getValue(&Estado_pausa);
    //botonstop.getValue(&Estado_stop);

    Serial.println(Estado_start);
    Serial.println(Estado_pausa);
    Serial.println(Estado_stop);
    
    /*
    Serial.println(Estado_dual);
    if(Estado_dual==0) 
    {
       //estado.setText("ON"); digitalWrite(led, HIGH);
       Audio.play("inicio.wav");
       Serial.println("audio 1");
    }
    else
    {
       //estado.setText("OFF"); digitalWrite(led, LOW);
       Audio.play("final.wav");
       Serial.println("audio 3");
    }

*/

 


    
}
void funcionbotonpausa(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    //botonstart.getValue(&Estado_start);
    botonpausa.getValue(&Estado_pausa);
    //botonstop.getValue(&Estado_stop);

    Serial.println(Estado_start);
    Serial.println(Estado_pausa);
    Serial.println(Estado_stop);
    
}
void funcionbotonstop(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    //botonstart.getValue(&Estado_start);
    //botonpausa.getValue(&Estado_pausa);
    botonstop.getValue(&Estado_stop);

    Serial.println(Estado_start);
    Serial.println(Estado_pausa);
    Serial.println(Estado_stop);
    
}
void funcionbotonencender(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    //botonencender.getValue(&Estado_encender);
    //botonpausa.getValue(&Estado_pausa);
    //botonstop.getValue(&Estado_stop);

    //recvRetNumber(&Estado_encender);
    Estado_encender = 1;
    Serial.println(Estado_encender);
    
}
void funcionbotonapagar(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    //botonstart.getValue(&Estado_start);
    //botonpausa.getValue(&Estado_pausa);
    //botonapagar.getValue(&Estado_apagar);
    Estado_apagar = 1;
    Serial.println(Estado_apagar);
    
}

void encender(){


       
      Serial.println("paso 0");
      digitalWrite(ledinicio , LOW);
      digitalWrite(ledpausa, LOW);
      digitalWrite(ledparar, LOW);

      Audio.play("bienve.wav"); 
      
     // while(true){
          
           // if((Estado_Estado_encnder == 0)||(caracter == 'O')){
            //while((Estado_start == LOW)){}
            //Estado_encender = 0;
            
            
            digitalWrite(ledinicio , HIGH);
             Serial.println("paso 0.1");
           
            estado=0;
            timefinal=0;
            cont=0;
            cont1=0;
            cont2=0;
            z=0;
            caracter='.';
            pausa1=1;
             Serial.println("paso 0.00000");
      //}
      
 }
