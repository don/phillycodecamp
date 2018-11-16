// Philly Code Camp IoT Workshop
// Send temperature and humidity data to MQTT
//
// Uses WiFiNINA https://www.arduino.cc/en/Reference/WiFiNINA
// Joël Gähwiler's MQTT Library https://github.com/256dpi/arduino-mqtt
// Adafruit DHT Sensor Library https://github.com/adafruit/DHT-sensor-library
// Adafruit Unified Sensor Library https://github.com/adafruit/Adafruit_Sensor
//

#include <SPI.h>
#include <WiFiNINA.h>
#include <MQTT.h>

WiFiSSLClient net;
MQTTClient mqtt;

// Temperature and Humidity Sensor
#include <DHT.h>
#define DHTTYPE DHT22
#define DHTPIN  1
DHT dht(DHTPIN, DHTTYPE);

const char wifi_ssid[] = "workshop";
const char wifi_password[] = "wifi-password";

const char server[] = "mqtt.iotwork.shop";
const char clientId[] = "deviceX";
const char username[] = "deviceX";
const char password[] = "mqtt-password";

String temperatureTopic = String("workshop/") + clientId + String("/temperature");
String humidityTopic = String("workshop/") + clientId + String("/humidity");

// Publish every 10 seconds for the workshop. Real world apps need this data every 5 or 10 minutes.
unsigned long publishInterval = 10 * 1000;
unsigned long lastMillis = 0;

int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);

  // Uncomment next line to wait for a serial connection
  // while (!Serial) { }
 
  // initialize temperature sensor
  dht.begin();   
 
  Serial.println("Connecting WiFi");
  connectWiFi();

  // Start the MQTT connection
  Serial.println("Setting up MQTT");
  mqtt.begin(server, 8883, net);

}

void loop() {
  mqtt.loop();

  if (!mqtt.connected()) {
    connectMQTT();
  }

  if (millis() - lastMillis > publishInterval) {
    lastMillis = millis();

    float temperature = dht.readTemperature(true);
    float humidity = dht.readHumidity();

    Serial.print(temperature);
    Serial.print("°F ");
    Serial.print(humidity);
    Serial.println("% RH");
    
    mqtt.publish(temperatureTopic, String(temperature)); 
    mqtt.publish(humidityTopic, String(humidity)); 
  }  
}

void connectWiFi() {
  // Check for the WiFi module
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  Serial.print("WiFi firmware version ");
  Serial.println(WiFi.firmwareVersion());
  
  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(wifi_ssid);
    status = WiFi.begin(wifi_ssid, wifi_password);

    // wait 3 seconds for connection
    delay(3000);
  }
  Serial.println("Connected to WiFi");
  printWiFiStatus();

}

void connectMQTT() {
  Serial.print("Connecting MQTT...");
  while (!mqtt.connect(clientId, username, password)) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("connected.");
}

void printWiFiStatus() {
  // print your WiFi IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
