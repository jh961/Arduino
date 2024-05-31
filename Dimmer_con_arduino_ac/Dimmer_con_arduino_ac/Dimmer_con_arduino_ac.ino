int AC_pin = 10; //Pin to MOC3020 - OptoTriac
int subida = 4;  // señal del pulsador en HIGH para subida 
int bajada = 5;  // señal del pulsador en LOW para bajada 
byte dim = 0;    //Initial brightness level from 0 to 255, change as you like!

void setup() {
  
  pinMode(AC_pin, OUTPUT);
  pinMode(subida, INPUT);
  pinMode(bajada, INPUT);
  attachInterrupt(0, light, FALLING);//When arduino Pin 2 is FALLING from HIGH to LOW, run light procedure!
}

void light() {

    if (dim < 1) {                  //Turn TRIAC completely OFF if dim is 0
      digitalWrite(AC_pin, LOW);
      dim=1;
    }
    if (dim > 254) {                //Turn TRIAC completely ON if dim is 255
      digitalWrite(AC_pin, HIGH);
      dim=255;
    }
  
  if (dim > 0 && dim < 255) {      //Dimming part, if dim is not 0 and not 255
    delayMicroseconds(34*(255-dim));
    digitalWrite(AC_pin, HIGH);
    delayMicroseconds(500);
    digitalWrite(AC_pin, LOW);
  }
}

void loop() {

  if((digitalRead(subida)== HIGH )){
    dim=dim+25;
  }if((digitalRead(bajada)== HIGH )){
    dim=dim-25;
  }

}
