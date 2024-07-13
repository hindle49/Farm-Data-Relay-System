//  FARM DATA RELAY SYSTEM
//
//  ESP-NOW Sensor Example
//
//  Developed by Timm Bogner (timmbogner@gmail.com) in Urbana, Illinois, USA.
//  An example of how to send data via ESP-NOW using FDRS.
//

#include "fdrs_node_config.h"
//#include <Adafruit_BME280.h>
#include <Adafruit_BMP280.h>
#include <fdrs_node.h>

Adafruit_BMP280 bmp;

//float data1;
//float data2;

void setup() {
  beginFDRS();
   
  while (!bmp.begin(0x76)) {
    Serial.println("BMP not initializing!");
    delay(1000);  // 1 second
  }
}
void loop() {

  loadFDRS(bmp.readTemperature(), TEMP_T);
  //loadFDRS(bme.readHumidity(), HUMIDITY_T);
  loadFDRS(bmp.readPressure() / 100.0F, PRESSURE_T);
  sendFDRS();
  sleepFDRS(60);  //Sleep time in seconds
  
  /*data1 = readHum();
  loadFDRS(data1, HUMIDITY_T);
  data2 = readTemp();
  loadFDRS(data2, TEMP_T);
//  DBG(sendFDRS());
    if(sendFDRS()){
      DBG("Big Success!");
    } else {
      DBG("Nope, not so much.");
    }
  sleepFDRS(10);  //Sleep time in seconds
}

float readTemp() {
  return 22.069;
}

float readHum() {
  return random(0, 100);  */


}
