


const int motord =2;
const int motori =3;
char caracter='.';


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motord,OUTPUT);
  pinMode(motori,OUTPUT);
}

void loop() {
  while(Serial.available() > 0) {
    // get incoming byte:
    caracter = Serial.read();
    Serial.println(caracter);
  }

  switch(caracter){
    case 'd':    // your hand is on the sensor
      analogWrite(motord,255);
      analogWrite(motori,0);
      Serial.println("Motor Derecha");
      break;
      
    case 'b':    // your hand is on the sensor
      analogWrite(motord,0);
      analogWrite(motori,255);
      Serial.println("Motor Izquierda");
      break;
      
    case 'c':    // your hand is on the sensor
      analogWrite(motord,0);
      analogWrite(motori,0);
      Serial.println("Motor Alto");
      break;
  }
  caracter='.';
}
