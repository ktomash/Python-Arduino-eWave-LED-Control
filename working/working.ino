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
    if (IBI > 0){
        
        strip.setPixelColor(IBI, strip.Color(0, 0, 255));
        strip.show();
        delay(100); 
    } 
 }      
}

