#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define DEBUG 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

int l_IBI = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("TEST");
  strip.begin();
  strip.show();
}

void loop() {

  if (Serial.available() > 0) {
    int IBI = Serial.read();

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
    l_IBI = IBI;
  }      
}
    
    

