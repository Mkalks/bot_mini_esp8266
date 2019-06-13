/* 
   -- Project -- 
    
   This source code of graphical user interface  
   has been generated automatically by RemoteXY editor. 
   To compile this code using RemoteXY library 2.3.3 or later version  
   download by link http://remotexy.com/en/library/ 
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                    
     - for ANDROID 4.1.1 or later version; 
     - for iOS 1.2.1 or later version; 
     
   This source code is free software; you can redistribute it and/or 
   modify it under the terms of the GNU Lesser General Public 
   License as published by the Free Software Foundation; either 
   version 2.1 of the License, or (at your option) any later version.     
*/ 
#include <Servo.h>
Servo servo1;
////////////////////////////////////////////// 
//          RemoteXY include library        // 
////////////////////////////////////////////// 

// definition of connection mode and connection of libraries
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h> 

#include <RemoteXY.h> 



// connection settings
#define REMOTEXY_WIFI_SSID "wifi" //Wi-Fi name
#define REMOTEXY_WIFI_PASSWORD "1234567890" //Wi-fi password
#define REMOTEXY_SERVER_PORT 6377 //port must coincide in app


// interface configuration  
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,2,0,1,0,28,0,8,25,2,
  66,33,84,5,10,52,6,4,54,13,
  35,24,5,22,19,16,30,30,14,38,
  38,38,24,26,31 }; 
   
// structure defines all variables of your control interface
struct { 

    // input variable
  int8_t joystick_1_x; // =-100..100 координата x положения джойстика 
  int8_t joystick_1_y; // =-100..100 координата y положения джойстика 

    // output variable
  int8_t level_1; // =-100..100 положение уровня 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 



void setup()  
{ 
  RemoteXY_Init ();  
pinMode(D7, OUTPUT);
pinMode(D5, OUTPUT);
servo1.attach(D6); // control signal of servo №1 is connected to pin D6
   
} 

void loop()  
{  
  RemoteXY_Handler ();
  if(RemoteXY.joystick_1_y < 0){
    digitalWrite(D7, HIGH);
    digitalWrite(D5, LOW);
  } else if(RemoteXY.joystick_1_y < 0){
    digitalWrite(D5, HIGH);
    digitalWrite(D7, LOW);
  }
int pov = map (RemoteXY.joystick_1_x, -100, 100, 0, 180);
 servo1.write(RemoteXY.int pov);
  // use the RemoteXY structure to transfer data


}
