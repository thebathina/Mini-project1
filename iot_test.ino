#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h> 
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
int enable2 = 13;    
#define dht_dpin 0
char auth[] = "TJ35YvwW0I9r7DpGSu5oC3IOpimbJdnh";
char ssid[] = "My Zone";
char pass[] = "sreevani";
DHT dht(dht_dpin, DHTTYPE); 
BlynkTimer timer;
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
 }
void setup(void)
{ 
  dht.begin();
  pinMode(enable2, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  Serial.println("Humidity and temperature\n\n");
  timer.setInterval(1000L, sendSensor);
  delay(700);

}
void loop() {
   
    float h = dht.readHumidity();
    float t = dht.readTemperature();  
    
    Serial.println();
    Serial.flush();       
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
    Serial.println();
    delay(1000);
    Blynk.run();
    timer.run();
}
