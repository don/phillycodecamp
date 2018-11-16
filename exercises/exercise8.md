# Exercise 8: Azure

Before running code, you need to have IoT Hub and a device set up in Azure. See https://github.com/Mangu/azure-iot-hol/tree/master/module1 for more details.

1. Open [/arduino/Feedbox/Feedbox.ino](arduino/Feedbox/Feedbox.ino) in the Arduino IDE
1. Update WiFi ssid and password
1. Update the server, clientId, and username
   * The server is the hostname of your IoT Hub _e.g. workshop.azure-devices.net_
   * The clientId is the name of the device you created in IoT Hub _e.g. arduino1010_
   * The username is server + clientId + version _e.g. workshop.azure-devices.net/arduino1010/api-version=2016-11-14_
1. The password is a Shared Access Signature (SAS) that is generated using a tools such as the [Azure IoT Toolkit](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.azure-iot-toolkit), [Azure Device Explorer](https://github.com/Azure/azure-iot-sdk-csharp/tree/master/tools/DeviceExplorer), or using the [Azure Cloud Shell](https://azure.microsoft.com/en-us/features/cloud-shell/). Let's use the Azure Cloud shell.
    1. Log into the Aure Portal
    1. Launch the Azure Cloud Shell using the **>_** button near the top right of the portal
    1. Install the IoT extension 
        `az extension add --name azure-cli-iot-ext`
    1. Generate a SAS token 
        `az iot hub generate-sas-token -d arduino1010 -n workshop -du 63072000` (Note that you should substitute _arduino1010_ with your device name and _workshop_ with the name of your IoT Hub.)
    1. Copy and paste the SAS Token into the Arduino code. 
1. Azure's MQTT interface specifies the format for the topic names. Adjust the outbound feedbackTopic so it contains your device id `devices/${deviceId}/messages/events/`
1. Adjust the inbound ledTopic to include the device id `devices/${deviceId}/messages/devicebound/#`
1. Load the sketch onto the device _Sketch -> Upload_
1. Switch back to Dani's instructions https://github.com/Mangu/azure-iot-hol
