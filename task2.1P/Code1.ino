#include <DHT.h>
#include <WiFiNINA.h>
#include "ThingSpeak.h"
#define DHTPIN 2         
#define DHTTYPE DHT22     
#define LEDPIN 4         
#define BUZZERPIN 5       
DHT dht(DHTPIN, DHTTYPE);
char ssid[] = "OnePlus 12R";
char pass[] = "12345678";
WiFiClient client;
unsigned long channelID = 3019499;
const char *writeAPIKey = "UVUO0DUDMLP8HKWI";
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");

  ThingSpeak.begin(client);
}
void loop() {
  delay(2000);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C | Humidity: ");
  Serial.print(hum);
  Serial.println("%");
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, hum);
  int response = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (response == 200) {
    Serial.println("Data sent to ThingSpeak.");
  } else {
    Serial.print("Failed to send data. HTTP error code: ");
    Serial.println(response);
  }
  if (temp > 30) {
    digitalWrite(LEDPIN, HIGH);
    tone(BUZZERPIN, 1500);  
  } else {
    digitalWrite(LEDPIN, LOW);
    noTone(BUZZERPIN);    
  }
  delay(30000);  
}
