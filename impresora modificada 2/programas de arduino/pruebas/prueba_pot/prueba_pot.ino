#include "Nextion.h"

NexGauge ObjGauge  = NexGauge(1, 5, "j0");

byte pot = A0;

void setup(void)
{      
    Serial.begin(115200);
    nexInit();//Inicio la comunicacion entre el Arduino y la Pantalla Nextion
    
    ObjGauge.setValue(0);
    Serial.println("Iniciando...");
    delay(2000);
}

void loop(void)
{     
  int Aleatorio = analogRead(pot);//random(1,1023);
  //Serial.println(Aleatorio + "/n");
  //int Val_FunMap = map(Aleatorio, 1, 1023, 0, 360);
  int Val_FunMap = map(Aleatorio, 1, 1023, 0, 215); 
  Serial.print("Angulo: ");Serial.println(Val_FunMap);
  
  ObjGauge.setValue(Val_FunMap);
  delay(500);
}
