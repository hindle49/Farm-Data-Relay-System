//  FARM DATA RELAY SYSTEM
//
//  AHT20 SENSOR MODULE plus the NTC160 addd by Ian Hindle
//
//  Developed by Timm Bogner (timmbogner@gmail.com) in Urbana, Illinois, USA.

#include "fdrs_node_config.h"
#include <Adafruit_AHTX0.h>
#include <ScioSense_ENS160.h>  // ENS160 library
#include <fdrs_node.h>

Adafruit_AHTX0 aht;
ScioSense_ENS160      ens160(ENS160_I2CADDR_0);
//ScioSense_ENS160      ens160(ENS160_I2CADDR_1);

void setup() {
  Serial.begin(115200);
  beginFDRS();
  if (! aht.begin()) 
     {
       Serial.println("Could not find AHT? Check wiring");
       while (1) delay(10);
     }

     ens160.begin();
     Serial.println(ens160.available() ? "done." : "failed!");
     if (ens160.available()) 
        {
        // Print ENS160 versions
        Serial.print("\tRev: "); Serial.print(ens160.getMajorRev());
        Serial.print("."); Serial.print(ens160.getMinorRev());
        Serial.print("."); Serial.println(ens160.getBuild());
        Serial.print("\tStandard mode ");
        Serial.println(ens160.setMode(ENS160_OPMODE_STD) ? "done." : "failed!");
        }

}

void loop() {  
  sensors_event_t humidity, temp;
  //sensors_event_t aqi;

  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data

  loadFDRS(temp.temperature, TEMP_T);
  loadFDRS(humidity.relative_humidity, HUMIDITY_T);

  if (ens160.available()) 
      {
      ens160.measure(true);
      ens160.measureRaw(true);
       
      loadFDRS(ens160.getAQI(),  AQI_T);      //Air quality Indicator
      loadFDRS(ens160.getTVOC(), TVOC_T);     //Total Volatile Organic Compounds ppb
      loadFDRS(ens160.geteCO2(), CO2_T);      //CO2 level ppm
      loadFDRS(ens160.getHP0(),  HP0_T);      //HP_0   ppm  Ohms
      loadFDRS(ens160.getHP1(),  HP1_T);      //HP_1   ppm  Ohms
      loadFDRS(ens160.getHP2(),  HP2_T);      //HP_2   ppm  Ohms
      loadFDRS(ens160.getHP3(),  HP3_T);      //HP_3   ppm  Ohms

      Serial.print("AQI: ");Serial.print(ens160.getAQI());Serial.print("\t");
      Serial.print("TVOC: ");Serial.print(ens160.getTVOC());Serial.print("ppb\t");
      Serial.print("eCO2: ");Serial.print(ens160.geteCO2());Serial.print("ppm\t");
      Serial.print("R HP0: ");Serial.print(ens160.getHP0());Serial.print("Ohm\t");
      Serial.print("R HP1: ");Serial.print(ens160.getHP1());Serial.print("Ohm\t");
      Serial.print("R HP2: ");Serial.print(ens160.getHP2());Serial.print("Ohm\t");
      Serial.print("R HP3: ");Serial.print(ens160.getHP3());Serial.println("Ohm");
      delay(2000);
      }

  sendFDRS();
  sleepFDRS(60);  //Sleep time in seconds
}
