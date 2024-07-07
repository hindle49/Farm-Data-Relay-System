//  FARM DATA RELAY SYSTEM
//
//  Sensor Configuration

#include <fdrs_globals.h>

#define READING_ID    2   //Unique ID for this sensor
#define GTWY_MAC      0x01 //Address of the nearest gateway

//#define USE_ESPNOW
#define USE_LORA
#define DEEP_SLEEP
//#define POWER_CTRL    14

#define FDRS_DEBUG     // Enable USB-Serial debugging
#define DBG_LEVEL 0    // 0 for minimal messaging, 1 for troubleshooting, 2 for development

/// I2C - OLED or RTC
#define I2C_SDA 21 // 5
#define I2C_SCL 22 //6

// OLED -- Displays console debugging messages on an SSD1306 I²C OLED
#define USE_OLED    
#define OLED_HEADER "FDRS"
#define OLED_PAGE_SECS 30
#define OLED_RST -1

// LoRa Configuration
#define RADIOLIB_MODULE SX1276 //Tested on SX1276
#define LORA_SS 18        // T-beam 18   Heltec 18     original 18
#define LORA_RST 23       // T-beam 23   Heltec 14     original 14
#define LORA_DIO 26       // T-beam 26   Heltec 26     original 26
#define LORA_BUSY 33      //             Heltec 35     oroginal 33 DIO1
//#define USE_SX126X

//#define CUSTOM_SPI
#define LORA_SPI_SCK  5   // T-Beam 5    Heltec 5   original 5 
#define LORA_SPI_MISO 19  // T-Beam 19   Heltec 19  original 19
#define LORA_SPI_MOSI 27  // T-beam 27   Heltec 27  original 27

#define LORA_TXPWR 17    // LoRa TX power in dBm (: +2dBm - +17dBm (for SX1276-7) +20dBm (for SX1278))
#define LORA_ACK        // Request LoRa acknowledgment.

// NTP Time settings for controllers and sensors
#define DST_RULE        EUDST // Daylight saving time rules: Use USDST for United States DST rules, EUDST for European Union
#define STD_OFFSET      (0)                // Local standard time offset in hours from UTC - if unsure, check https://time.is
#define DST_OFFSET      (STD_OFFSET + 1)    // Local savings time offset in hours from UTC - if unsure, check https://time.is
#define TIME_PRINTTIME    15     // Time, in minutes, between printing local time to debug