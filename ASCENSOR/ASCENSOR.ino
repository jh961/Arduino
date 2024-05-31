
//pines de salida
const int encendido= 2;
const int stopp= 3;
const int abrir= 4;
const int cerrar= 5;
const int piso1= 6;
const int piso2= 7;
const int piso3= 8;
const int piso4= 9;

const int tiempo= 1000;

int flat =0;
char caracter='.';

void setup() {
   Serial.begin(9600); // Inicia la comunicacion Serial.
   
   pinMode(encendido, OUTPUT);
   pinMode(abrir, OUTPUT);
   pinMode(cerrar, OUTPUT);
   pinMode(stopp, OUTPUT);
   pinMode(piso1, OUTPUT);
   pinMode(piso2, OUTPUT);
   pinMode(piso3, OUTPUT);
   pinMode(piso4, OUTPUT);
}

void loop() {
   
   while(Serial.available() > 0) {
    // get incoming byte:
    caracter = Serial.read();
    Serial.print(caracter);
  }


  if((caracter == 'O')){
     digitalWrite(encendido , HIGH);
  }else if (caracter == 'F'){
    digitalWrite(encendido , LOW);
  }else if (caracter == 'A'){
    digitalWrite(abrir , HIGH);
    delay(tiempo);
    digitalWrite(abrir , LOW);
  }else if (caracter == 'C'){
    digitalWrite(cerrrar , HIGH);
    delay(tiempo);
    digitalWrite(cerrar , LOW);
  }else if (caracter == '1'){
    digitalWrite(piso1 , HIGH);
    delay(tiempo);
    digitalWrite(piso1 , LOW);
  }else if (caracter == '2'){
    digitalWrite(piso2 , HIGH);
    delay(tiempo);
    digitalWrite(piso2 , LOW);
  }else if (caracter == '3'){
    digitalWrite(piso3 , HIGH);
    delay(tiempo);
    digitalWrite(piso3 , LOW);
  }else if (caracter == '4'){
    digitalWrite(piso4 , HIGH);
    delay(tiempo);
    digitalWrite(piso4 , LOW);
  }else if (caracter == 'S'){
    if(flat==0){
        digitalWrite(stopp , HIGH);
      flat=1;
    }else{
      digitalWrite(stopp , LOW);
      flat=0;
    }
  }
  
caracter='.';
}
