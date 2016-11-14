//#include "DHT.h"
//#define DHTPIN 7
//#define DHTTYPE DHT11
//DHT dht(DHTPIN, DHTTYPE);
 
int led = 13; //led Rojo de prueba de conexión
byte sensorpir = 6;

char inbyte = 0; //Char para leer el led
 
void setup() {
  // initialise serial communications at 9600 bps:
   pinMode(sensorpir,INPUT);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  //dht.begin();
}
 
void loop() {

  
  
  if (Serial.available() > 0)
  {
    inbyte = Serial.read();
    Serial.println(inbyte);
    if (inbyte == '2')
    {
      digitalWrite(led, LOW); //LED off
    
    }
    if (inbyte == '1')
    {
      digitalWrite(led, HIGH); //LED on
    }
  }
  sendAndroidValues();
  delay(2000); 
}
 


//enviar los valores por el dipositivo android por el modulo Bluetooth
void sendAndroidValues()
 {
  Serial.print('#'); //hay que poner # para el comienzo de los datos, así Android sabe que empieza el String de datos

    Serial.print(digitalRead(sensorpir));
    Serial.print(1);
    //Serial.print('+'); //separamos los datos con el +, así no es más fácil debuggear la información que enviamos
  
 Serial.print('~'); //con esto damos a conocer la finalización del String de datos
 Serial.println();
 delay(10);        //agregamos este delay para eliminar tramisiones faltantes
}
