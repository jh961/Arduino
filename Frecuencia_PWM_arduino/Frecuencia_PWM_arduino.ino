int AC_pin = 3; 

void setup() {

TCCR2B = TCCR2B & 0b11111000 | 0x01;
  
  pinMode(AC_pin, OUTPUT);
  analogWrite(AC_pin, 125);
  }


void loop() {

  

}
