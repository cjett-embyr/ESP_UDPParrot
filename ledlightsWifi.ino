#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
 
const char* ssid = "Bees?";
const char* password = "BBBBBBBBBB";
WiFiUDP udpClient;
char packetBuffer[255]; //buffer to hold incoming packet

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  Serial.println("1282550005000");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  udpClient.begin(1337);
  Serial.println("00000000010000");
}
 
void loop() {
  for( int i = 0; i < sizeof(packetBuffer);  ++i )
    packetBuffer[i] = (char)0;
    
  static String lastMsg = "";
  int packetSize=udpClient.parsePacket();
  if (packetSize) {
    int len = udpClient.read(packetBuffer, 255);
    String incomingMessage = packetBuffer;
    if (incomingMessage != lastMsg)
    {
      lastMsg = incomingMessage;
      Serial.println(incomingMessage);
    }
  }
}
