# Exercise 1 - Development Environment

Set up your computer for writing Arduino code.

## Arduino IDE
Install the Arduino IDE from https://arduino.cc/downloads

![Arduino IDE Download](../images/ArduinoIDE.PNG)
        
### Arduino SAMD Board Definitions
Use the Arduino Boards Manager to install the Arduino SAMD Board definitions. Open the Boards Manager using the menu _Tools -> Boards -> Boards Manager_

![Arduino Boards Manager](../images/BoardManager-Menu.PNG)

Search for "1010" and install the Arduino SAMD Boards (32-bit ARM Cortex-M0+) definitions.

![Arduino SAMD Board Definitions](../images/BoardsManager.PNG)
        
### Arduino Libraries        
Install the following Arduino Libraries using the Library manager. 

    * WiFiNINA library (search for "NINA")
    * Joël Gähwiler's MQTT library (search for "lwmqtt")
    * DHT sensor library by Adafruit (search for "DHT")
    * Adafruit Unified Sensor library (search for "adafruit abstraction")

Open the library manager using the menu _Sketch -> Include Libraries -> Manage Libraries_

![Arduino Library Manager Menu](../images/ManageLibraries.PNG)

WiFiNINA library (search for "NINA")

![Arduino Library Manager WiFiNINA](../images/library-wifinina.png)

Joël Gähwiler's MQTT library (search for "lwmqtt")

![Arduino Library Manager MQTT](../images/library-mqtt.png)

DHT sensor library by Adafruit (search for "DHT")

![Arduino Library Manager Adafruit DHT](../images/library-dht.png)

Adafruit Unified Sensor library (search for "adafruit abstraction")

![Arduino Library Manager Adafruit Unified Sensor](../images/library-AdafruitUnifiedSensor.png)
