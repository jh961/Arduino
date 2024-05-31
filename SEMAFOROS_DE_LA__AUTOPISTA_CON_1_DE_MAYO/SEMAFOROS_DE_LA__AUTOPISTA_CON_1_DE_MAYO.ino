const int c1r=22;
const int c1a=23;
const int c1v=24;

const int c2r=25;
const int c2a=26;
const int c2v=27;

const int c3r=28;
const int c3a=29;
const int c3v=30;

const int c4r=31;
const int c4a=32;
const int c4v=33;

const int c5r=34;
const int c5a=35;
const int c5v=36;

const int c6r=37;
const int c6a=38;
const int c6v=39;

int selec=0;
const int espera=500;
const int espera1=1000;

void setup() {
  pinMode(c1r,OUTPUT);
  pinMode(c1a,OUTPUT);
  pinMode(c1v,OUTPUT);

  pinMode(c2r,OUTPUT);
  pinMode(c2a,OUTPUT);
  pinMode(c2v,OUTPUT);

  pinMode(c3r,OUTPUT);
  pinMode(c3a,OUTPUT);
  pinMode(c3v,OUTPUT);

  pinMode(c4r,OUTPUT);
  pinMode(c4a,OUTPUT);
  pinMode(c4v,OUTPUT);

  pinMode(c5r,OUTPUT);
  pinMode(c5a,OUTPUT);
  pinMode(c5v,OUTPUT);

  pinMode(c6r,OUTPUT);
  pinMode(c6a,OUTPUT);
  pinMode(c6v,OUTPUT);
  
  digitalWrite(c1r,HIGH);
  digitalWrite(c2r,HIGH);
  digitalWrite(c3r,HIGH);
  digitalWrite(c4r,HIGH);
  digitalWrite(c5r,HIGH);
  digitalWrite(c6r,HIGH);
}

void loop() {
  if(selec==0){
    digitalWrite(c1r,HIGH);
    digitalWrite(c2r,HIGH);
    delay(espera);
    digitalWrite(c1a,HIGH);
    digitalWrite(c2a,HIGH);
    delay(espera);
    digitalWrite(c1r,LOW);
    digitalWrite(c2r,LOW);
    digitalWrite(c1a,LOW);
    digitalWrite(c1v,HIGH);
    digitalWrite(c2a,LOW);
    digitalWrite(c2v,HIGH);
    delay(espera1);
    digitalWrite(c1v,LOW);
    digitalWrite(c2v,LOW);
    digitalWrite(c1a,HIGH);
    digitalWrite(c2a,HIGH);
    delay(espera);
    digitalWrite(c1a,LOW);
    digitalWrite(c1r,HIGH);
    digitalWrite(c2a,LOW);
    digitalWrite(c2r,HIGH);
    delay(espera);

    selec=1;
  }else if(selec==1){
    digitalWrite(c3r,HIGH);
    digitalWrite(c4r,HIGH);
    delay(espera);
    digitalWrite(c3a,HIGH);
    digitalWrite(c4a,HIGH);
    delay(espera);
    digitalWrite(c3r,LOW);
    digitalWrite(c4r,LOW);
    digitalWrite(c3a,LOW);
    digitalWrite(c3v,HIGH);
    digitalWrite(c4a,LOW);
    digitalWrite(c4v,HIGH);
    delay(espera1);
    digitalWrite(c3v,LOW);
    digitalWrite(c4v,LOW);
    digitalWrite(c3a,HIGH);
    digitalWrite(c4a,HIGH);
    delay(espera);
    digitalWrite(c3a,LOW);
    digitalWrite(c3r,HIGH);
    digitalWrite(c4a,LOW);
    digitalWrite(c4r,HIGH);
    delay(espera);

    selec=2;
  }else if(selec==2){
    digitalWrite(c5r,HIGH);
    digitalWrite(c6r,HIGH);
    delay(espera);
    digitalWrite(c5a,HIGH);
    digitalWrite(c6a,HIGH);
    delay(espera);
    digitalWrite(c5r,LOW);
    digitalWrite(c6r,LOW);
    digitalWrite(c5a,LOW);
    digitalWrite(c5v,HIGH);
    digitalWrite(c6a,LOW);
    digitalWrite(c6v,HIGH);
    delay(espera1);
    digitalWrite(c5v,LOW);
    digitalWrite(c6v,LOW);
    digitalWrite(c5a,HIGH);
    digitalWrite(c6a,HIGH);
    delay(espera);
    digitalWrite(c5a,LOW);
    digitalWrite(c5r,HIGH);
    digitalWrite(c6a,LOW);
    digitalWrite(c6r,HIGH);
    delay(espera);


    selec=0;
  }
  
}
