#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <dht11.h>
#define DHT11PIN 4

const char* ssid = "";
const char* password = "";
dht11 DHT11;

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
    int hum = DHT11.humidity;

    Serial.print("Temperature  (C): ");
    Serial.println((float)DHT11.temperature, 2);
    int temp = DHT11.temperature;

    // Connect to Flask server
    if (client.connect("192.168.0.108", 80)) {
      String url = "/post/" + String(temp) + "/" + String(hum);
      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                   "Host: 192.168.0.108\r\n" +
                   "Connection: close\r\n\r\n");

      delay(500);
    }
  } else {
    Serial.println("WiFi not connected");
  }

  delay(2000);
}

