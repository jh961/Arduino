//líbrerias necesarias
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h> // libreria que permite reproducir sonido en Arduino.
#include "Nextion.h"

const int led = 13;

TMRpcm Audio;   //Se crea un objeto de la librería TMRpcm llamado Audio.
#define pinSD 53 //Define el pin para seleccionar la tarjeta SD en el modulo es CS


//Declara los objetos a utilizar [pagina id:0,componente id:1, NombreComponente: "Objeto_ObjName"] 

NexDSButton botonstart = NexDSButton(2, 2, "b1");
NexDSButton botonpausa = NexDSButton(2, 3, "b2");
NexDSButton botonstop = NexDSButton(2, 4, "b3");

NexText estado =  NexText(2, 5, "t0");


// Registro al objeto Dual State Button a la lista de eventosTouch
NexTouch *nex_listen_list[] = 
{
    &botonstart,
    NULL
};

// Creo que una funcion que ingresara cuando el evento Touch sea detectado
void funcionboton(void *ptr);


void setup() {

  //pinMode(inicio, INPUT_PULLUP);
  //pinMode(pausa, INPUT_PULLUP);
  //pinMode(parar, INPUT_PULLUP);
  
  Audio.speakerPin = 9; //Define el pin en el que está conectada un parlante.
  Serial.begin(9600); // Inicia la comunicacion Serial.

  if (!SD.begin(pinSD)) {  //Verifica la coneccion de la tarjeta sd:
    Serial.println("Fallo en la tarjeta SD");  //Aviso de que algo no anda bien
    return;   //No hacer nada si no se pudo leer la tarjeta
  }

  Serial.println("Todo OK"); 

   Audio.volume(1);         
  //Audio.setVolume(7);



  //Inicio la comunicacion entre el Arduino y la Pantalla
    nexInit();
    
    pinMode(led, OUTPUT);   //defino el pin 13 definido como led como salida
    digitalWrite(led, LOW); //inicio en estado apagado

    //Registro  el llamado a la funcion del evento de Dual State Button
    botonstart.attachPop(funcionboton, &botonstart);
    

}

void loop() {


nexLoop(nex_listen_list);

if(Audio.isPlaying()==0){
  Audio.disable();  
}
// Audio.stop();
  
} // Fin del loop


// Creo que una funcion que ingresara cuando el evento Touch sea detectado
void funcionboton(void *ptr)
{
    uint32_t Estado_dual;
    /* Consigo el valor del estado del componente. */
    botonstart.getValue(&Estado_dual);

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
}
