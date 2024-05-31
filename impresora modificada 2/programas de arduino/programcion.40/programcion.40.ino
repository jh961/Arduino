#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>
#include "Nextion.h"
#include "DHT.h"

TMRpcm Audio;   
#define pinSD 53 // pin para la lectura de sd

#define DHTPIN 3 //pin conexion sensor DHt-11
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

    uint32_t Estado_start=1;
    uint32_t Estado_pausa=1;
    uint32_t Estado_stop=1;

    
    
    uint32_t Estado_dere=1;
    uint32_t Estado_izq=1;
    uint32_t Estado_stopm=1;

    uint32_t Estado_play=1;
    uint32_t Estado_sigui=1;
    
    uint32_t Estado_velo=200;

    uint32_t Estado_luces1=1;
    uint32_t Estado_luces2=1;
    uint32_t Estado_luces3=1;

    uint32_t Estado_contador=1;
    uint32_t Estado_stopc=1;

    uint32_t Estado_slider=0;

    uint32_t Estado_ht=1;
    uint32_t Estado_salir=0;

    int Estado_encender=0;
    int Estado_apagar=0;


NexDSButton botonplay = NexDSButton(4, 2, "b1");
NexDSButton botonsigui = NexDSButton(4, 3, "b2");

NexDSButton botonstart = NexDSButton(3, 2, "b1");
NexDSButton botonpausa = NexDSButton(3, 3, "b2");
NexDSButton botonstop = NexDSButton(3, 4, "b3");
NexDSButton botonencender = NexDSButton(0, 1, "b1");
NexDSButton botonapagar = NexDSButton(1,7, "b6");

NexDSButton botonizq = NexDSButton(2, 2, "b1");
NexDSButton botondere = NexDSButton(2, 3, "b2");
NexDSButton botonstopm = NexDSButton(2, 6, "b3");

//NexText estado1 =  NexText(1, 7, "b6");

NexDSButton botonluces1 = NexDSButton(5, 2, "b1");
NexDSButton botonluces2 = NexDSButton(5, 3, "b2");
NexDSButton botonluces3 = NexDSButton(5, 4, "b3");


NexDSButton botoncontador = NexDSButton(6, 3, "b1");
NexDSButton botonstopc = NexDSButton(6, 6, "b2");

NexDSButton botonht = NexDSButton(1, 6, "b5");
NexDSButton botonsalir = NexDSButton(7, 1, "b0");

NexText texto1 =  NexText(6, 5, "t2");

NexText textoh =  NexText(7, 3, "t2");
NexText textot =  NexText(7, 4, "t0");

NexSlider slider = NexSlider(2, 8, "h0");

NexPage page7 = NexPage (0,0,"page7");
NexPage page0 = NexPage (1,0,"page0");
NexPage page2 = NexPage (3,0,"page2");
NexPage page6 = NexPage (7,0,"page6");

NexTouch *nex_listen_list[] = 
{
    &botonstart,&botonpausa,&botonstop,&botonencender,&botonapagar,&botondere,&botonizq,
    &botonplay,&botonsigui,&botonluces1,&botonluces2,&botonluces3,&botonstopc,&botoncontador,&botonstopm,
    &botonht,&botonsalir,
    NULL
};



const int ledinicio=30;
const int ledpausa=31;
const int ledparar=32;
const int motor= 36;
const int led1=33;
const int led2=34;
const int led3=35;
const int motor_dere=8;
const int motor_izq=9;
const int motor_contador= 37;
const int velocidad_motor = 200;

const int interruccion=2;

//int velocidad = 100;

char caracter='.';

int estado =0;
int i=0,z=0,flat=0,pausa1=0, timefinal=0,cont=0,cont1=0,cont2=0,cont3=0,cont5=0;

float humedad,temperatura;

long int tiempo;

void funcionbotonstart(void *ptr);
void funcionbotonpausa(void *ptr);
void funcionbotonstop(void *ptr);
void funcionbotonencender(void *ptr);
void funcionbotonapagar(void *ptr);

void funcionbotondere(void *ptr);
void funcionbotonizq(void *ptr);
void funcionbotonstopm(void *ptr);


void funcionbotonplay(void *ptr);
void funcionbotonsigui(void *ptr);


void funcionbotonluces1(void *ptr);
void funcionbotonluces2(void *ptr);
void funcionbotonluces3(void *ptr);

void funcionbotoncontador(void *ptr);
void funcionbotonstopc(void *ptr);

void funcionbotonht(void *ptr);
void funcionbotonsalir(void *ptr);

void setup() {

  //TCCR2B = TCCR2B & 0b11111000 | 0x01;

  
  Audio.speakerPin = 11;
  Serial.begin(9600); // Inicia la comunicacion Serial.
   Serial3.begin(9600); // Inicia la comunicacion Serial.

   dht.begin();

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
  
  botondere.attachPop(funcionbotondere, &botondere);
  botonizq.attachPop(funcionbotonizq, &botonizq);
  botonstopm.attachPop(funcionbotonstopm, &botonstopm);

  botonplay.attachPop(funcionbotonplay, &botonplay);
  botonsigui.attachPop(funcionbotonsigui, &botonsigui);

  botonluces1.attachPop(funcionbotonluces1, &botonluces1);
  botonluces2.attachPop(funcionbotonluces2, &botonluces2);
  botonluces3.attachPop(funcionbotonluces3, &botonluces3);

  botoncontador.attachPop(funcionbotoncontador, &botoncontador);
  botonstopc.attachPop(funcionbotonstopc, &botonstopc);

  botoncontador.attachPop(funcionbotoncontador, &botoncontador);


  botonht.attachPop(funcionbotonht, &botonht);
  botonsalir.attachPop(funcionbotonsalir, &botonsalir);

  //scro.attachPop(funcionbotonvelo, &scro);

  
  pinMode(ledinicio, OUTPUT);
  pinMode(ledpausa, OUTPUT);
  pinMode(ledparar, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(motor_dere, OUTPUT);
  pinMode(motor_izq, OUTPUT);
  pinMode(motor_contador, OUTPUT);
  pinMode(interruccion, INPUT);

//  attachInterrupt(digitalPinToInterrupt(interruccion), contador, RISING);
  //attachInterrupt(digitalPinToInterrupt(3), velocidadMas, RISING);

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
  analogWrite(motor_dere, LOW); 
  analogWrite(motor_izq, LOW);
  analogWrite(motor_contador, LOW); 


  digitalWrite(ledinicio , LOW);
  digitalWrite(ledpausa, LOW);
  digitalWrite(ledparar, LOW);
  digitalWrite(led1 , LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  
   Audio.stopPlayback();
   Audio.disable(); 

}

void loop() {

  nexLoop(nex_listen_list);

  while(Serial3.available() > 0) {
    // get incoming byte:
    caracter = Serial3.read();
    Serial.print(caracter);
  }

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

  if((Estado_encender == 1)||(caracter == 'O')){
    encender();
    Estado_encender = 0;
    page0.show();

    
    digitalWrite(ledinicio , HIGH);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, HIGH);
    digitalWrite(led1 , HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }

 
  
  if((Estado_start == 0)||(caracter == 'S')){
   // while((digitalRead(inicio) == LOW)){}
   page2.show();
   Estado_start=1;
   Estado_pausa=1;
   Estado_stop=1;
   Estado_contador= 1;
   
   digitalWrite(ledinicio , HIGH);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, LOW);


    Serial.println("paso 1");
    
    digitalWrite(motor, HIGH); 
    analogWrite(motor_contador, LOW);

    
    Audio.play("inicio.wav");
    
    
    estado=1;
    pausa1=0;
    cont1=0;
    cont2=0;
    tiempo=millis();
    
    
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


    
  }else if((Estado_apagar == 1)||(caracter == 'K')) {

    Estado_apagar = 0;
    page7.show();
    
    Estado_start=1;
   Estado_pausa=1;
   Estado_stop=1;
   Estado_contador= 1;

   estado=0;
    timefinal=0;

    caracter='.';

          digitalWrite(ledinicio , LOW);
          digitalWrite(ledpausa, LOW);
          digitalWrite(ledparar, LOW);
          digitalWrite(led1 , LOW);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);

  Serial.println("paso 23");

  analogWrite(motor, LOW);
  analogWrite(motor_contador, LOW); 
  analogWrite(motor_dere, LOW);
    analogWrite(motor_izq, LOW);
    Estado_dere=1;
    Estado_izq=1;
    Estado_stopm=1; 
    Estado_contador= 1;
   
  Audio.play("adios.wav");
  delay(800);
  Audio.stopPlayback();
   Audio.disable();


    

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
    
      
   

    if((Audio.isPlaying()==0)&&(pausa1==0)&&(cont2==1)){
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

     if(((millis() - tiempo) >= 4000)&&(pausa1==0)){
    

        if(z<10){ 
          digitalWrite(ledinicio , HIGH);
          digitalWrite(ledpausa, LOW);
          digitalWrite(ledparar, LOW);
          digitalWrite(led1 , HIGH);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          }
        z++;
        if(z>=10){
         z=0;  
        }
        
        
    delay(1000);
          digitalWrite(ledinicio , LOW);
          digitalWrite(ledpausa, LOW);
          digitalWrite(ledparar, LOW);
          digitalWrite(led1 , LOW);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
     delay(500);      
      
  }
         
  
    if(pausa1==1){
      tiempo=millis();
      Serial.println("paso 2,7");
      
    digitalWrite(ledinicio , LOW);
  digitalWrite(ledpausa, HIGH);
  digitalWrite(ledparar, LOW);
  digitalWrite(led1 , LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
    }
    Serial.println("paso 1,7");  
  }

 
    
  if(Audio.isPlaying()==0){
    Audio.stopPlayback();
    Audio.disable(); 
    flat=0; 
    //Serial.println("paso 1,5555555");
  }

  if((Estado_luces1 == 0)){
    
   
    if(cont==0){
      digitalWrite(ledinicio , LOW);
      digitalWrite(ledpausa, HIGH);
      digitalWrite(ledparar, HIGH);
      digitalWrite(led1 , LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      cont=1;
    }else if(cont==1){
      digitalWrite(ledinicio , HIGH);
      digitalWrite(ledpausa, HIGH);
      digitalWrite(ledparar, LOW);
      digitalWrite(led1 , HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
       cont=2;
    }else if(cont==2){
      digitalWrite(ledinicio, HIGH);
      digitalWrite(ledpausa, LOW);
      digitalWrite(ledparar, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      cont=0;
      }
      Serial.println("paso 7,111111");
      delay(200);
       
  }else if((Estado_luces2== 0)){
    
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
        
    Serial.println("paso 7,222222");
    delay(500);
  }else if((Estado_luces3== 0)){

          digitalWrite(ledinicio , HIGH);
          digitalWrite(ledpausa, HIGH);
          digitalWrite(ledparar, LOW);
          digitalWrite(led1 , HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, LOW);
          cont=1;
        
   Serial.println("paso 7,333333");
  }

if((Estado_contador== 0)){


  Estado_start=1;
   Estado_pausa=1;
   Estado_stop=1;
   estado=0;
    timefinal=0;
    cont1=0;
    cont2=0;
    z=0;
    caracter='.';

          digitalWrite(ledinicio , HIGH);
          digitalWrite(ledpausa, HIGH);
          digitalWrite(ledparar, HIGH);
          digitalWrite(led1 , HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);

          if(digitalRead(interruccion) == HIGH){
            while(digitalRead(interruccion) == HIGH){}  

            cont5++;
            Serial.println("contador ="  );
            Serial.println(cont5);
            char conto[16];
            itoa(cont5, conto, 10);   
            texto1.setText(conto);
            Serial.println(conto);
            Audio.play("conteo.wav");
          }
          
          
          //Estado_contador= 1;
          
          analogWrite(motor_contador, 200);
        
   Serial.println("paso 8,22222");
  }

if ((Estado_dere==0)){

    slider.getValue(&Estado_slider);
    analogWrite(motor_izq, LOW);
    analogWrite(motor_dere, Estado_slider); 
    Serial.println(Estado_slider);
    Serial.println("paso 5,11111111111");
    Estado_izq=1;

    digitalWrite(ledinicio ,LOW);
    digitalWrite(ledpausa, HIGH);
    digitalWrite(ledparar, HIGH);
    digitalWrite(led1 , LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    
}else if(Estado_izq==0){
    slider.getValue(&Estado_slider);
    analogWrite(motor_dere, LOW);
    analogWrite(motor_izq, Estado_slider); 
    Serial.println(Estado_slider);
    Serial.println("paso 5,22222222222222");
    Estado_dere=1;

    digitalWrite(ledinicio , HIGH);
    digitalWrite(ledpausa, HIGH);
    digitalWrite(ledparar, LOW);
    digitalWrite(led1 , HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
}


if(Estado_ht==0){


 if((millis() - tiempo) >= 1000){
          humedad = dht.readHumidity();
          // Read temperature as Celsius (the default)
          temperatura = dht.readTemperature();
          //delay(1000);
        
          Serial.print("humedad = ");
          Serial.print(humedad);
          Serial.print("\n temperatura = ");
          Serial.print(temperatura);
          Serial.print("\n");
        
          char conto[16];
          itoa(humedad, conto, 10);   
          textoh.setText(conto);
          Serial.println(conto);
          
          itoa(temperatura, conto, 10);   
          textot.setText(conto);
          Serial.println(conto);
        Serial.println("paso 9.222222");

        tiempo=millis();
      }
   
    digitalWrite(ledinicio , LOW);
  digitalWrite(ledpausa, HIGH);
  digitalWrite(ledparar, LOW);
  digitalWrite(led1 , LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
            
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
    Estado_contador= 1;

    Estado_luces1=1;
    Estado_luces2=1;
    Estado_luces3=1;

    Estado_dere= 1;
    Estado_izq= 1;
    
    
    Serial.println(Estado_apagar);
    
}void funcionbotondere(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botondere.getValue(&Estado_dere);
    Serial.println(Estado_dere);
    Serial.println("paso 5,1");
    Estado_izq=1;
}
void funcionbotonizq(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botonizq.getValue(&Estado_izq);
    Serial.println(Estado_izq);
    Serial.println("paso 5,2");
    Estado_dere=1;
  
}
void funcionbotonstopm(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botonstopm.getValue(&Estado_stopm);
    analogWrite(motor_dere, LOW);
    analogWrite(motor_izq, LOW);
    Serial.println(Estado_stopm);
    Serial.println("paso 5,3333");
    Estado_dere=1;
    Estado_izq=1;
    Estado_stopm=1;

    digitalWrite(ledinicio , LOW);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, LOW);
    digitalWrite(led1 , LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  
}
void funcionbotonplay(void *ptr)
{
    
    if((flat==0)){
      flat=1;
      Audio.play("ca.wav");
    }else if (flat==1){
      flat=2;
      Audio.pause();
    }else{
      flat=1;
      Audio.pause();
    }
    Serial.println(flat);
    estado=0;
            timefinal=0;
            cont=0;
            cont1=0;
            cont2=0;
            z=0;
            caracter='.';
            pausa1=1;

            digitalWrite(ledinicio , HIGH);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, HIGH);
    digitalWrite(led1 , HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    
}
void funcionbotonsigui(void *ptr)
{
    
    cont3++;
    if(cont3>4){
       cont3=0;
      }
      flat=1;

    if(cont3==0){
        Audio.play("ca.wav");
      }else if(cont3==1){
        Audio.play("cb.wav");
      }else if(cont3==2){
        Audio.play("cc.wav");
      }else if(cont3==3){
        Audio.play("cd.wav");
      }else if(cont3==4){
        Audio.play("ce.wav");
      }
    Serial.println(cont3);
    estado=0;
            timefinal=0;
            cont=0;
            cont1=0;
            cont2=0;
            z=0;
            caracter='.';
            pausa1=1;
    
}
void funcionbotonluces1(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botonluces1.getValue(&Estado_luces1);
    Estado_luces2=1;
    Estado_luces3=1;
    
    Serial.println(Estado_luces1);
    Serial.println(Estado_luces2);
    Serial.println(Estado_luces3);
    Serial.println("paso 7,1");
    
}
void funcionbotonluces2(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botonluces2.getValue(&Estado_luces2);
    Estado_luces1=1;
    Estado_luces3=1;
    
    Serial.println(Estado_luces1);
    Serial.println(Estado_luces2);
    Serial.println(Estado_luces3);
    Serial.println("paso 7,2");
    
}
void funcionbotonluces3(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botonluces3.getValue(&Estado_luces3);
    Estado_luces2=1;
    Estado_luces1=1;
    
    Serial.println(Estado_luces1);
    Serial.println(Estado_luces2);
    Serial.println(Estado_luces3);
    Serial.println("paso 7,3");
    
}
void funcionbotoncontador(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botoncontador.getValue(&Estado_contador);
    cont5=0;
    //cont5++;

    Estado_luces2=1;
    Estado_luces1=1;
    Estado_luces3=1;

    analogWrite(motor, LOW); 
  analogWrite(motor_dere, LOW);
    analogWrite(motor_izq, LOW);
    Estado_dere=1;
    Estado_izq=1;
    Estado_stopm=1; 
    
  
    Audio.play("iconteo.wav");
    Serial.println(Estado_contador);

    char conto[16];
    itoa(cont5, conto, 10);   
    texto1.setText(conto);
    Serial.println(conto);
    
    Serial.println("paso 8,11");
    
}
void funcionbotonstopc(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botonstopc.getValue(&Estado_stopc);
    Audio.play("fconteo.wav");
    Serial.println(Estado_stopc);
    Serial.println("paso 8,2222");
    analogWrite(motor_contador, LOW);
    Estado_contador=1;
    Estado_stopm=1;

    digitalWrite(ledinicio , LOW);
    digitalWrite(ledpausa, LOW);
    digitalWrite(ledparar, LOW);
    digitalWrite(led1 , LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  
}
/*
void contador()
{
  
  cont5++;
  Serial.println("contador ="  );
  Serial.println(cont5);
  char conto[16];
  itoa(cont5, conto, 10);   
  texto1.setText(conto);
  Serial.println(conto);
  Audio.play("conteo.wav");
}
*/

void funcionbotonht(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botonht.getValue(&Estado_ht);
    Serial.println(Estado_ht);
    Serial.println("paso 9,111");
    //Estado_ht=1;
    tiempo=millis();
    page6.show();
  
}
void funcionbotonsalir(void *ptr)
{
    
    /* Consigo el valor del estado del componente. */
    botonsalir.getValue(&Estado_salir);
    Serial.println(Estado_salir);
    Serial.println("paso 9,2222");

    Estado_ht=1;
    page0.show();
  
}

void encender(){


       
      Serial.println("paso 0");

      Audio.play("bienve.wav"); 
      
     // while(true){
          
           // if((Estado_Estado_encnder == 0)||(caracter == 'O')){
            //while((Estado_start == LOW)){}
            //Estado_encender = 0;
            
            
            digitalWrite(ledinicio , LOW);
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
