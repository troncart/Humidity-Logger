/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********Humidity Logger**************
***********1-08-2019**************
*/
#include <dht.h>
#include <SoftwareSerial.h>
dht DHT;
int counter = 0;
String Humidity ;
String Temperature ;


void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
  Serial.println("CLEARSHEET");
  Serial.println("DHT11 Humidity and temperature sensor\n\n");
  Serial.println("LABEL,Date,Time, Counter, Humidity(%) , Temperature(C)");
  Serial.println("RESETTIMER");
}
  void loop()
  {
    DHT.read11(A0);
    int sensorValue =  DHT.humidity;
    int temp =  DHT.temperature;
    counter++;
    Serial.print("DATA,DATE,TIME," + String(counter) +  String(Humidity) +","+String(Temperature));
    Serial.print(DHT.humidity );
    Serial.print(",");
    Serial.print (DHT.temperature);
    Serial.println();
    delay(1000);
  }
