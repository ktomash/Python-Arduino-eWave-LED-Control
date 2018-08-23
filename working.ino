#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define DEBUG 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();
}

void loop() {
  int serial_working;
  serial_working = 0;
  // put your main code here, to run repeatedly:
  //colorSet(strip.Color(255,0,0));
  int l_IBI = 0;
 
 if (Serial.available() > 0) {
    serial_working = 1;
    int IBI = Serial.read();
<<<<<<< HEAD:working/working.ino
    if (IBI > 0){
=======

    if (l_IBI > IBI) {
      for (int i = l_IBI; i > IBI; i--) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  
        strip.show();
      }
    } else {
      for (int i = l_IBI; i <= IBI; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  
        strip.show();
      }
    }
   /* for (int i = 0; i <= IBI; i++) {
      strip.setPixelColor(i, strip.Color(255, 0, 0));  
      strip.show();
    }
    for (int j = IBI; j <= 60; j++) {
      strip.setPixelColor(j, strip.Color(0, 0, 0));  
      strip.show(); 
    } */

    l_IBI = IBI;
   // colorSet(30, strip.Color(IBI, 0, 0));
   /* if (IBI > 0){
      //for (int j = 0; j < IBI; j++) {
>>>>>>> parent of 172823a... fixed:working.ino
        
        strip.setPixelColor(IBI, strip.Color(0, 0, 255));
        strip.show();
        delay(100); 
    } 
 }      
}

