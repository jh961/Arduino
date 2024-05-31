
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


byte carga1[8] = {    
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b11111111,
};
byte carga2[8] = {    
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b11111111,
  0b11111111,
};
byte carga3[8] = {    
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b11111111,
  0b11111111,
  0b11111111,
};
byte carga4[8] = {    
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
};
byte carga5[8] = {    
  0b00000000,
  0b00000000,
  0b00000000,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
};
byte carga6[8] = {    
  0b00000000,
  0b00000000,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
};
byte carga7[8] = {    
  0b00000000,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
};
byte carga8[8] = {    
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
};

const int neufase= 4;  // reley de habilitación para fase y neutro en la descarga
const int pwm= 3;   // PWM para fuente conmutada
const int descargado= 2;  // pin de verificación 

const int espera= 1000;
const int espera1= 500;
const int espera2= 100;

const int pinvolta = A2;
const int alarma = 5;

char dato ;
int flat=0;
double voltasalida=0;
float voltadescarga=0;
float voltareferencia=5;
float energia=0;

void setup() {

  TCCR2B = TCCR2B & 0b11111000 | 0x01;
  
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(neufase, OUTPUT);
  pinMode(pwm, OUTPUT);
  pinMode(alarma, OUTPUT);
  pinMode(descargado, INPUT);

  lcd.createChar (0, carga1);
  lcd.createChar (1, carga2);
  lcd.createChar (2, carga3);
  lcd.createChar (3, carga4);
  lcd.createChar (4, carga5);
  lcd.createChar (5, carga6);
  lcd.createChar (6, carga7);
  lcd.createChar (7, carga8);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DESFIBRILADOR");
  lcd.setCursor(0, 1);
  lcd.print("V 1.0");
  delay(espera);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AUTORES");
  lcd.setCursor(0, 1);
  lcd.print("DAVID URREGO");
  delay(espera);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AUTORES");
  lcd.setCursor(0, 1);
  lcd.print("JAIME DIAZ");
  delay(espera);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DESFIBRILADOR");
  lcd.setCursor(0, 1);
  lcd.print("V 1.0");
  delay(espera);

  //lcd.write((byte)0);
  
}

void loop() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DESFIBRILADOR");
  lcd.setCursor(0, 1);
  lcd.print("V 1.0");
  delay(espera2);
  analogWrite(pwm, 0);
  digitalWrite(neufase, LOW);
  digitalWrite(alarma, LOW);

  if (Serial.available()) {
    dato = Serial.read();
    if (dato=='A') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     10v");
      delay(espera);
      
      voltareferencia=15;        
      
      flat=1;
    }else if (dato=='B') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     20v");
      delay(espera);
      
      voltareferencia=25;        
      
      flat=1;
    }else if (dato=='C') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     30v");
      delay(espera);
      
      voltareferencia=35;        
      
      flat=1;
    }else if (dato=='D') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     40v");
      delay(espera);
      
      voltareferencia=45;        
      
      flat=1;
    }else if (dato=='E') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     50v");
      delay(espera);
      
      voltareferencia=55;        
      
      flat=1;
    }else if (dato=='F') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     60v");
      delay(espera);
      
      voltareferencia=65;        
      
      flat=1;
    }else if (dato=='G') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     70v");
      delay(espera);
      
      voltareferencia=75;        
      
      flat=1;
    }else if (dato=='H') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     80v");
      delay(espera);
      
      voltareferencia=85;        
      
      flat=1;
    }else if (dato=='I') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     90v");
      delay(espera);
      
      voltareferencia=95;        
      
      flat=1;
    }else if (dato=='J') {  
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nivel de Carga ");
      lcd.setCursor(0, 1);
      lcd.print("     100v");
      delay(espera);
      
      voltareferencia=101;        
      
      flat=1;
    }else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("VALOR NO ");
      lcd.setCursor(0, 1);
      lcd.print("     CONOCIDO");
      delay(espera);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("INGRESAR VALOR");
      lcd.setCursor(0, 1);
      lcd.print("MAYOR A 9 Volt");
      delay(espera);
    }
    dato=0;
  }

  if(flat==1){

        digitalWrite(neufase, LOW);
        analogWrite(pwm, 200);
        

        while(voltadescarga<=voltareferencia){
          lcd.clear();
        for(int i=0 ; i<16 ; i++){
          
          if(i<8){
          lcd.setCursor(i, 1);
          lcd.write((byte)i);
          
          
          }else {
          lcd.setCursor(i, 1);
          lcd.write((byte)7);
          
          lcd.setCursor(i, 0);
          lcd.write((byte)i-8);
          
          }
              delay(espera2);
              
              voltasalida = analogRead(pinvolta);
              voltasalida=((voltasalida*5)/1023);
              voltadescarga=((voltasalida*42.2499)-2);
              energia=(((0.08174)*((voltadescarga)*(voltadescarga)))/2);
              if(voltadescarga<0){
                energia=0;
              }

              Serial.print("@");
              Serial.print(voltasalida);
              Serial.print("#");

              
             /* 
              Serial.print("Voltage de salida   ");
              Serial.print(voltasalida);
              Serial.print("    Voltage de descarga  ");
              Serial.print(voltadescarga);
              Serial.print("    Energia almacenada  ");
              Serial.print(energia);
              Serial.println("  MicroJulios");
              */
              if(voltadescarga>=voltareferencia){
                break;
              }
        }
        }

          analogWrite(pwm, 0);
         
          lcd.clear();
          lcd.setCursor(5, 0);
          lcd.print("CARGA");
          lcd.setCursor(4, 1);
          lcd.print("COMPLETA");
          delay(espera);

        while(voltadescarga>=0){
        
          
          
          analogWrite(pwm, 0);
          digitalWrite(neufase, HIGH);
          digitalWrite(alarma, LOW);

              voltasalida = analogRead(pinvolta);
              voltasalida=((voltasalida*5)/1023);
              voltadescarga=((voltasalida*42.2499)-2);
              energia=(((0.08174)*((voltadescarga)*(voltadescarga)))/2);
              if(voltadescarga<0){
                energia=0;
              }

              Serial.print("@");
              Serial.print(voltasalida);
              Serial.print("#");
              /*
              Serial.print("Voltage de salida   ");
              Serial.print(voltasalida);
              Serial.print("    Voltage de descarga  ");
              Serial.print(voltadescarga);
              Serial.print("    Energia almacenada  ");
              Serial.print(energia);
              Serial.println("  MicroJulios");
              */
          digitalWrite(alarma, HIGH);

          lcd.clear();
          lcd.setCursor(1, 0);
          lcd.print("EQUIPO CARGADO");
          lcd.setCursor(1, 1);
          lcd.print("DESCARGUE  ");
          lcd.print(voltadescarga);
          delay(espera2);
          
        }
        
        flat=0;
    }
   voltasalida = analogRead(pinvolta);
   voltasalida=((voltasalida*5)/1023);
   voltadescarga=((voltasalida*42.2499)-2);
   energia=(((0.08174)*((voltadescarga)*(voltadescarga)))/2);
   if(voltadescarga<0){
   energia=0;
   }

   
   Serial.print("@");
   Serial.print(voltasalida);
   Serial.print("#");
   
   /*           
   Serial.print("Voltage de salida   ");
   Serial.print(voltasalida);
   Serial.print("    Voltage de descarga  ");
   Serial.print(voltadescarga);
   Serial.print("    Energia almacenada  ");
   Serial.print(energia);
   Serial.println("  MicroJulios");
   */
}
