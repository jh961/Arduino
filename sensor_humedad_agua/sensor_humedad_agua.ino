const int sensorPin = A0;

void setup() {
   Serial.begin(9600);
}

void loop() 
{
   int humedad = analogRead(sensorPin);
   Serial.print(" \n humedad analoga = ");
   Serial.print(humedad);
  
   if(humedad < 500)
   {
      Serial.println("Encendido");  
      //hacer las acciones necesarias
   }
   delay(1000);
}