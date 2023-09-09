#include <PubSubClient.h>
#include <SPI.h>
#include <UIPEthernet.h>

EthernetClient ethClient;
PubSubClient client(ethClient);

const int WS_PORT = 1883;
const byte mac[] = { 0xDE, 0x3E, 0x1F, 0x22, 0x52, 0xA2 }; 
const String CONFIG_DEVICE_UUID = "DE:3E:1F:22:52:A2";
const char *mqtt_address = "192.168.1.209";
const int mqtt_port = 1883;
const String CONFIG_SUBSCRIBED_TOPIC = "#";

void setup_ethernet_connection() {
  Ethernet.begin(mac);
}

void mqttReconnect()
{
  while (!client.connected()){
    if (client.connect(CONFIG_DEVICE_UUID.c_str())){
      client.subscribe(CONFIG_SUBSCRIBED_TOPIC.c_str());
    }else{
      Serial.println("Connecting mqtt...");
      delay(500);
    }
  }
}

void setup() {
    Serial.begin(115200);
    setup_ethernet_connection();
    client.setServer(mqtt_address, mqtt_port);
    client.setCallback(mqttListener);
}



void loop() {
  delay(500);
  if (!client.connected()){
    mqttReconnect();
  }

  client.loop();
}

void mqttListener(char *topic, byte *payload, unsigned int length) {
  Serial.println("xxxxx");
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println(topic);
  Serial.println(message);
}