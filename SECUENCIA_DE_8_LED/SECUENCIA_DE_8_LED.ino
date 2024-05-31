
const int led1=2;
const int led2=3;
const int led3=4;
const int led4=5;
const int led5=6;
const int led6=7;
const int led7=8;
const int led8=9;
const int espera=100;

void setup() {
pinMode(led1,OUTPUT); 
pinMode(led2,OUTPUT); 
pinMode(led3,OUTPUT); 
pinMode(led4,OUTPUT); 
pinMode(led5,OUTPUT); 
pinMode(led6,OUTPUT); 
pinMode(led7,OUTPUT); 
pinMode(led8,OUTPUT); 
}

void loop() {
  digitalWrite(led1,HIGH);
   delay(espera);
  digitalWrite(led2,HIGH);
   delay(espera);
  digitalWrite(led3,HIGH);
   delay(espera);
   
  digitalWrite(led4,HIGH);
  digitalWrite(led1,LOW);
   delay(espera);

  digitalWrite(led5,HIGH);
  digitalWrite(led2,LOW);
   delay(espera);

  digitalWrite(led6,HIGH);
  digitalWrite(led3,LOW);
   delay(espera);

  digitalWrite(led7,HIGH);
  digitalWrite(led4,LOW);
   delay(espera);

  digitalWrite(led8,HIGH);
  digitalWrite(led5,LOW);
   delay(espera);

  digitalWrite(led6,LOW);
   delay(espera);
  digitalWrite(led7,LOW);
   delay(espera);
  digitalWrite(led8,LOW);
   delay(espera);

  /////////////////////////////////////

  digitalWrite(led8,HIGH);
   delay(espera);
  digitalWrite(led7,HIGH);
   delay(espera);
  digitalWrite(led6,HIGH);
   delay(espera);
   
  digitalWrite(led5,HIGH);
  digitalWrite(led8,LOW);
   delay(espera);

  digitalWrite(led4,HIGH);
  digitalWrite(led7,LOW);
   delay(espera);

  digitalWrite(led3,HIGH);
  digitalWrite(led6,LOW);
   delay(espera);

  digitalWrite(led2,HIGH);
  digitalWrite(led5,LOW);
   delay(espera);

  digitalWrite(led1,HIGH);
  digitalWrite(led4,LOW);
   delay(espera);

  digitalWrite(led3,LOW);
   delay(espera);
  digitalWrite(led2,LOW);
   delay(espera);
  digitalWrite(led1,LOW);
   delay(espera);
  
}
