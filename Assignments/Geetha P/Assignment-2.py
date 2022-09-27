#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);
#define ALARM 3
float tmax=50,tmin=0,temp,unid;
 
void setup(){
 
  Serial.begin(9600);
  
  Serial.println("Temperature and Humidity Alarm");
  Serial.println("Type maximum Temperature");
  while(tmax == 50) 
 {
  if (Serial.available() > 0)
  {
    tmax=Serial.parseFloat();
  }
 }
 Serial.println(tmin);
 dht.begin();
}
 
void loop(){
  delay(2000);
  umid = dht.readHumidity();
  temp = dht.readTemperature();
  if (isnan(temp) || isnan(umid)){

    
    Serial.println("\n error: Read Sensor DHT\n");
    tone (ALARM,440,1000);
  }
    else
    {
      if (temp> tmin && temp < tmax)
      {
        noTone(ALARM);
      }
      else
      {
        tone (ALARM,440,1000);
        Serial.print("tmin);
        Serial.print(" and "); 
        Serial.println(tmax);
      }
    }
}
