#include <esp_now.h>
#include "esp_wifi.h"
#include <WiFi.h>

uint8_t groundsationMAC[] = {0xD4, 0xD4, 0xDA, 0x5A, 0x5A, 0x74};

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  Serial.write(incomingData, len);
}
 
void setup() {
  Serial.begin(921600);
  WiFi.mode(WIFI_STA);
  esp_wifi_set_mac(WIFI_IF_STA, &groundsationMAC[0]);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  Serial.println("CANSAT GS Starting");
  Serial.print("This GS MAC Address: ");
  Serial.println(WiFi.macAddress());
  esp_wifi_set_protocol( WIFI_IF_STA , WIFI_PROTOCOL_LR);   
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}
