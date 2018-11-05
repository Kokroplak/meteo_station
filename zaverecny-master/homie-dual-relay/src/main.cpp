/*
 *   Tested with "WiFi Smart Socket ESP8266 MQTT"
 *   and "Sonoff - WiFi Wireless Smart Switch ESP8266 MQTT"
 *
 *   The Relay could be toggeled with the physical pushbutton
*/

#include <Homie.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4         // Pin which is connected to the DHT sensor.

// Uncomment the type of sensor in use:
#define DHTTYPE           DHT11     // DHT 11 
//#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview
#define INTERVAL 1000

unsigned long lastSent = 0;

DHT dht(DHTPIN, DHTTYPE);

HomieNode temperatureNode("temperature", "temperature");

void setupHandler() {

  temperatureNode.setProperty("unit").send("c");
  }

void loopHandler() {
   if (millis() - lastSent >= INTERVAL * 1000UL || lastSent == 0) {
     float temperature = dht.readTemperature(true);
     temperatureNode.setProperty("degrees").send(String(temperature));
     
     
     lastSent = millis();
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Homie_setFirmware("homie-dht", "1.0.0");
  
  Homie.setSetupFunction(setupHandler).setLoopFunction(loopHandler);
  


  Homie.setup();
}

void loop() {
  Homie.loop();
}