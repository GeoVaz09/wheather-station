#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <dht11.h>
#define DHT11PIN 4

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
dht11 DHT11;
var char* url = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;

    int chk = DHT11.read(DHT11PIN);

    Serial.print("Humidity (%): ");
    Serial.println((float)DHT11.humidity, 2);
    float hum = (float)DHT11.humidity, 2

    Serial.print("Temperature  (C): ");
    Serial.println((float)DHT11.temperature, 2);
    float temp = (float)DHT11.temperature, 2

    if (client.connect("worldtimeapi.org", 80)) {
      
      client.print(String("GET ") + time_api_url + " HTTP/1.1\r\n" +
                   "Host: worldtimeapi.org\r\n" +
                   "Connection: close\r\n\r\n");

      delay(2000);
    }
  } else {
    Serial.println("WiFi not connected");
  }
}
