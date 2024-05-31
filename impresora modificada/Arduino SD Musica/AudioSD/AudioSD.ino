//líbrerias necesarias
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h> // libreria que permite reproducir sonido en Arduino.

TMRpcm Audio;   //Se crea un objeto de la librería TMRpcm llamado Audio.
#define pinSD 53 //Define el pin para seleccionar la tarjeta SD en el modulo es CS

const int inicio= 4;
const int pausa= 5;
const int parar= 6;


void setup() {

   pinMode(inicio, INPUT_PULLUP);
  pinMode(pausa, INPUT_PULLUP);
  pinMode(parar, INPUT_PULLUP);
  
  Audio.speakerPin =11; //Define el pin en el que está conectada un parlante.
  Serial.begin(9600); // Inicia la comunicacion Serial.

Serial.println("vamos bien");
  if (!SD.begin(pinSD)) {  //Verifica la coneccion de la tarjeta sd:
    Serial.println("Fallo en la tarjeta SD");  //Aviso de que algo no anda bien
    return;   //No hacer nada si no se pudo leer la tarjeta
  }
  Serial.println("vamos bien x2");

  Audio.volume(1);         
  //Audio.setVolume(7);

}

void loop() {

   Audio.play("inicio.wav");
   Serial.println("audio 1");
   

delay (5000);
if(Audio.isPlaying()==0){
  Audio.disable();  
}
// Audio.stop();
  
} // Fin del loop
