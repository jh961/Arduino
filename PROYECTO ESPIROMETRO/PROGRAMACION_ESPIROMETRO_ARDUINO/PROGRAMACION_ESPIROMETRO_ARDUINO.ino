#include <Keypad.h>;
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int triger = 2;
int echo = 3;

float tiempo;
float distancia;
int distancia1;

 
int a=290;
int b=100;
int tiempoenvio = 100;
int concatenar[10];
int edad;
int espera = 1000;
int esperadato = 500;
int esperamuestra = 50;
int flat = 0;
char letra ='a';
char sexo = "";
int tiempoprueba;
const byte ROWS = 4; //Este código se estable para definir que nuestro teclado tiene 4 filas 
const byte COLS = 4; //Este código se estable para definir que nuestro teclado tiene 4 columnas


char hexaKeys[ROWS][COLS] = //En el siguiente matriz se agregan en orden las teclas que posee nuestro teclado
{
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','-','D'}
};

byte rowPins[ROWS] = {22, 24, 26, 28}; // Estos son los pines de conexión de Arduino de las columnas
byte colPins[COLS] = {23, 25, 27, 29}; //Estos son los pines de conexión de Arduino de las filas

Keypad teclado = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); //En este punto el teclado se inicia y realiza el mapeo de sus teclas con respecto a la matriz colocada arriba
  

void setup() {
  lcd.begin(16, 2);

  pinMode(triger,OUTPUT);
  pinMode(echo,INPUT);
  
  Serial.begin(9600);

  lcd.clear();
  lcd.print("ESPIROMETRO");
  lcd.setCursor(0, 1);
  lcd.print("V 1.0");
  delay(espera);

  lcd.clear();
  lcd.print("AUTORES");
  lcd.setCursor(0, 1);
  lcd.print("EIMY ZULUAGA");
  delay(espera);
  
  lcd.clear();
  lcd.print("AUTORES");
  lcd.setCursor(0, 1);
  lcd.print("DAVID MORENO");
  delay(espera);
  
  lcd.clear();
  lcd.print("AUTORES");
  lcd.setCursor(0, 1);
  lcd.print("JAIME DIAZ");
  delay(espera);


  lcd.clear();
  lcd.print("ESPIROMETRO");
  lcd.setCursor(0, 1);
  lcd.print("V 1.0   OPRIMA *");
  
  letra = teclado.getKey();

  while(true){
    letra = teclado.getKey();
    //Serial.print("hola");
    //Serial.print(letra);
    if(letra == '*'){
      break;
    }
  }
}

void loop() {

if(flat==0){
  lcd.clear();
  lcd.print("INGRESE SU EDAD");
  
  letra = teclado.getKey();
  for(int i=0;i<2;i++){
    while(true){
      letra = teclado.getKey();
      //Serial.print(letra);
      if((letra == '0')||(letra == '1')||(letra == '2')||(letra == '3')||(letra == '4')||(letra == '5')||(letra == '6')||(letra == '7')||(letra == '8')||(letra == '9')){
      concatenar[i]=(letra-48);
      //Serial.print(letra);
      //Serial.print(concatenar[i]);
      lcd.setCursor(i+6, 1);
      lcd.print(concatenar[i]);
      delay(esperadato);
      /*while((letra == '0')||(letra == '1')||(letra == '2')||(letra == '3')||(letra == '4')||(letra == '5')||(letra == '6')||(letra == '7')||(letra == '8')||(letra == '9')){
        letra = teclado.getKey();
        }*/
      letra = teclado.getKey();
      break;
    }else if(letra == 'D'){
      letra = teclado.getKey();
      
      i--;
      lcd.setCursor(i+6, 1);
      lcd.print("  ");
      delay(esperadato);
    }
   }  
  }
      /*edad=concatenar[0]*10+concatenar[1];
      lcd.setCursor(7, 1);
      lcd.print(edad);*/
      flat=1;
  }else if(flat==1){
     lcd.clear();
     lcd.print("INGRESE SU ");
     lcd.setCursor(0, 1);
     lcd.print("SEXUALIDAD");
     delay(espera);
     lcd.clear();
     lcd.print("HOMBRE = A");
     lcd.setCursor(0, 1);
     lcd.print("MUJER = B");
     delay(espera);
     
      while(true){
        letra = teclado.getKey();
       // Serial.print(letra);
        if((letra == 'A')||(letra == 'B')){
          sexo=letra;
        if(sexo=='A'){
           concatenar[2]=1;
        }else if(sexo=='B'){
           concatenar[2]=2;
        }
        //Serial.print(letra);
        //Serial.print(sexo);
        delay(esperadato);
      /*while((letra == '0')||(letra == '1')||(letra == '2')||(letra == '3')||(letra == '4')||(letra == '5')||(letra == '6')||(letra == '7')||(letra == '8')||(letra == '9')){
        letra = teclado.getKey();
        }*/
      letra = teclado.getKey();
      break;
   } 
  }
      /*edad=concatenar[0]*10+concatenar[1];
      lcd.setCursor(7, 1);
      lcd.print(edad);*/
      flat=2;
  }else if(flat==2){
    
     lcd.clear();
     lcd.print("INGRESE SU PESO");
     

     letra = teclado.getKey();
  for(int i=3;i<5;i++){
    while(true){
      letra = teclado.getKey();
      //Serial.print(letra);
      if((letra == '0')||(letra == '1')||(letra == '2')||(letra == '3')||(letra == '4')||(letra == '5')||(letra == '6')||(letra == '7')||(letra == '8')||(letra == '9')){
      concatenar[i]=(letra-48);
      //Serial.print(letra);
      //Serial.print(concatenar[i]);
      lcd.setCursor(i+3, 1);
      lcd.print(concatenar[i]);
      lcd.print(" Kg");
      delay(esperadato);
      /*while((letra == '0')||(letra == '1')||(letra == '2')||(letra == '3')||(letra == '4')||(letra == '5')||(letra == '6')||(letra == '7')||(letra == '8')||(letra == '9')){
        letra = teclado.getKey();
        }*/
      letra = teclado.getKey();
      break;
    }else if(letra == 'D'){
      letra = teclado.getKey();
      
      i--;
      lcd.setCursor(i+3, 1);
      lcd.print("  ");
      delay(esperadato);
    }
   }  
  }
   flat=3;
  }else if(flat==3){
    /* lcd.clear();
     lcd.print("GUARDADO  ");
     for(int i=0;i<10;i++){
     lcd.setCursor(i, 1);
     lcd.print(concatenar[i]);
     }*/
    
     for(int i=5;i>=0;i--){
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("LA PRUEBA ");
       lcd.setCursor(0, 1);
       lcd.print("INICIA EN  ");
       lcd.print(i);
       
       delay(espera);
     }
     
       Serial.print('%'); 
    
    flat=4;
    tiempoprueba = millis();
    
  }else if((flat==4)&&((millis() - tiempoprueba)<=8000)){
    digitalWrite(triger,LOW);
    delayMicroseconds(2);
  
    digitalWrite(triger,HIGH);
    delayMicroseconds(10);
  
    tiempo = pulseIn(echo,HIGH);
    distancia = ((tiempo/2)/29.1);
    distancia= ((15.64-distancia));//-(2.47));
    distancia1 = ((distancia)*(22.779));
    distancia = 0.45558*distancia;
   // Serial.print(distancia);
   // Serial.println("cm");
   // delay(esperadato);
 
      
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("ESPIROMETRIA");
       lcd.setCursor(0, 1);
       lcd.print("DATOS  ");
       lcd.print(distancia);
       lcd.print("  ml");
       
       Serial.print('@');
       Serial.print(distancia1); 
       Serial.print('#');
      delay(esperamuestra);
      
  }else if((flat==4)){
    
       Serial.print('%'); 
    flat=5;
  }else if((flat==5)){
    while(true){
        letra = teclado.getKey();
       // Serial.print(letra);
        if((letra == 'D')){
          flat=0;
      break;
   } 
  }
      
  }
       
}
