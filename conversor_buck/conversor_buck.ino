const int pinpwm = 6;
const int voltsal = A0;


float voltaje,voltaje1;
int voltaje2 = 20;
float referencia = 10;

void setup() {
  Serial.begin(9600);
  TCCR0B = TCCR0B & 0b11111000 | 0b00000001; 
  
  pinMode(pinpwm, OUTPUT); 
  pinMode(voltsal, INPUT); 
}

void loop() {
  voltaje = analogRead(voltsal);
  voltaje = map(voltaje,0,1023,0,255);
  voltaje1 = voltaje*5 /255;
  voltaje1 = voltaje1*4;//.19;
  
 if (voltaje1 == referencia){
      voltaje2 = voltaje2;
      Serial.println("igual");
  }else if(voltaje1 > referencia){
      voltaje2 --;
      Serial.println("baja");

      if(voltaje2<=0){
          voltaje2 = 0;
      }
  }else if(voltaje1 < referencia){
      voltaje2 ++;
      Serial.println("sube");
      if(voltaje2 >= 250){
         voltaje2 = 250;
      }
  }

  Serial.print("voltaje1 : ");
  Serial.println(voltaje1);
  Serial.print("voltaje2 : ");
  Serial.println(voltaje2);
  //delay(10000);
  analogWrite(pinpwm, voltaje2);
}
