## Arduino  + ENC8J60 mqtt connection

The code is working even in PubSubClient repository author mentioned that it will not

[PubSubClient](https://github.com/knolleary/pubsubclient) 

**from PubSubClient**

> The library cannot currently be used with hardware based on the ENC28J60 chip – such as the Nanode or the Nuelectronics Ethernet Shield. For those, there is an alternative library available.


However later version of UIPEthernet library make it compatible. You can read more here:
[A Simple MQTT Pub/Sub Node With Arduino UNO and ENC28J60 Ethernetshield](https://www.instructables.com/A-Simple-MQTT-PubSub-Node-With-Arduino-UNO-and-ENC/)


>For the youngsters: The ENC28J60 Ethernetshield was the first shield to connect the Arduino with the internet. The major drawback of the chip was that it was lacking a stack, that subsequently had to be constructed in software. As a result it was kinda memory hungry. The initial version was without an SD card slot, the later version had an SD card slot. There were two libraries available: The Ethercard and the Ethershield library. The UIPEthernet library came later. As far as I could figure out, the PubSubClient library that is needed for MQTT doesnt work with the original Ethershield/EtherCard libraries. It does work with the UIPEthernet library though (extended fork here).