//  FARM DATA RELAY SYSTEM
//
//  ESP-NOW Sensor Example
//
//  Developed by Timm Bogner (timmbogner@gmail.com) in Urbana, Illinois, USA.
//  An example of how to send data via ESP-NOW using FDRS.
//

#include "fdrs_node_config.h"
#include <Adafruit_BMP280.h>
#include <fdrs_node.h>


Adafruit_BMP280 bmp;

bool status = false;      

void setup() {
  beginFDRS();
   
  while (!bmp.begin(0x76)) {
    Serial.println("BMP not initializing!");
    delay(1000);  // 1 second
  }
  
}
void loop() {

  loopFDRS();
  
  loadFDRS(bmp.readTemperature(), TEMP_T);
  //                    loadFDRS(bme.readHumidity(), HUMIDITY_T);
  loadFDRS(bmp.readPressure() / 100.0F, PRESSURE_T);
  sendFDRS();

 
  sleepFDRS(60);  //Sleep time in seconds
  

}
